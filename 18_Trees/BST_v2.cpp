#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // found node to delete
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            // two children: replace with inorder successor (smallest in right subtree)
            Node* succ = findMin(root->right);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}

// ----------------- Sequential traversals -----------------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

const int TASK_CUTOFF_DEPTH = 4; // tune: higher => fewer tasks

vector<int> parallel_inorder_vec(Node* root, int depth=0) {
    vector<int> result;
    if (!root) return result;

    if (depth >= TASK_CUTOFF_DEPTH || (!root->left && !root->right)) {
        function<void(Node*)> seq = [&](Node* n) {
            if (!n) return;
            seq(n->left);
            result.push_back(n->key);
            seq(n->right);
        };
        seq(root);
        return result;
    }

    vector<int> leftVec, rightVec;

    #pragma omp task shared(leftVec) firstprivate(root, depth)
    {
        leftVec = parallel_inorder_vec(root->left, depth + 1);
    }

    #pragma omp task shared(rightVec) firstprivate(root, depth)
    {
        rightVec = parallel_inorder_vec(root->right, depth + 1);
    }

    #pragma omp taskwait

    // merge: left + root + right
    result.reserve(leftVec.size() + 1 + rightVec.size());
    result.insert(result.end(), leftVec.begin(), leftVec.end());
    result.push_back(root->key);
    result.insert(result.end(), rightVec.begin(), rightVec.end());
    return result;
}

vector<int> parallel_preorder_vec(Node* root, int depth=0) {
    vector<int> result;
    if (!root) return result;

    if (depth >= TASK_CUTOFF_DEPTH || (!root->left && !root->right)) {
        function<void(Node*)> seq = [&](Node* n){
            if (!n) return;
            result.push_back(n->key);
            seq(n->left);
            seq(n->right);
        };
        seq(root);
        return result;
    }

    vector<int> leftVec, rightVec;
    // root value is immediate
    result.push_back(root->key);

    #pragma omp task shared(leftVec) firstprivate(root, depth)
    {
        leftVec = parallel_preorder_vec(root->left, depth + 1);
    }

    #pragma omp task shared(rightVec) firstprivate(root, depth)
    {
        rightVec = parallel_preorder_vec(root->right, depth + 1);
    }

    #pragma omp taskwait

    // merge: root + left + right
    result.insert(result.end(), leftVec.begin(), leftVec.end());
    result.insert(result.end(), rightVec.begin(), rightVec.end());
    return result;
}

// Utility to print a vector
void printVec(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// ----------------- Demo main -----------------
int main() {
    // Build a sample BST
    Node* root = nullptr;
    vector<int> keys = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65, 75, 85};
    for (int k : keys) root = insertNode(root, k);

    cout << "Sequential inorder: ";
    inorder(root);
    cout << "\n";

    cout << "Sequential preorder: ";
    preorder(root);
    cout << "\n";

    cout << "Sequential postorder: ";
    postorder(root);
    cout << "\n\n";

    // Parallel inorder using OpenMP tasks
    vector<int> inorderResult;
    #pragma omp parallel
    {
        #pragma omp single
        {
            inorderResult = parallel_inorder_vec(root, 0);
        }
    }
    cout << "Parallel inorder (collected and ordered): ";
    printVec(inorderResult);

    // Parallel preorder using OpenMP tasks
    vector<int> preorderResult;
    #pragma omp parallel
    {
        #pragma omp single
        {
            preorderResult = parallel_preorder_vec(root, 0);
        }
    }
    cout << "Parallel preorder (collected and ordered): ";
    printVec(preorderResult);

    // Test deletion
    cout << "\nDeleting 70 and 30\n";
    root = deleteNode(root, 70);
    root = deleteNode(root, 30);

    cout << "Inorder after deletions: ";
    inorder(root);
    cout << "\n";

    return 0;
}
