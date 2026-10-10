#include <iostream>
#include <vector>
using namespace std;

class tree{
    public:
    int val;
    tree* left;
    tree* right;

    tree(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

tree* insert_bst(vector<int> &nums,int st,int ed){
    while(st>ed){
        return nullptr;
    }

    int mid = st + (ed-st) / 2;

    tree* root = new tree(nums[mid]);
    root->left = insert_bst(nums,st,mid-1);
    cout << "Inserted "<<root->val<<endl;
    root->right = insert_bst(nums,mid+1,ed);

    return root;
}

int main() {
    vector<int> nums {2,4,5,7,11,19,22,23,26};
    int size = nums.size();
    insert_bst(nums,0,size-1);
    return 0;
}