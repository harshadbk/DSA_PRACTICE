#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* left;
    ListNode* rit;

    ListNode(int val){
        this->val = val;
        this->left = nullptr;
        this->rit = nullptr;
    }
};

ListNode* buildtree(vector<int> &nums,int l,int r){
    if(l>r){
        return nullptr;
    }
    int mid = l + (r-l) / 2;
    ListNode* root = new ListNode(nums[mid]);

    root->left = buildtree(nums,l,mid-1);
    root->rit = buildtree(nums,mid+1,r);

    return root;
}

void traverse(ListNode* root){
    if(root==nullptr){
        return;
    }
    traverse(root->left);
    cout << root->val << " ";
    traverse(root->rit);
}

int main() {
    vector<int> nums{3,5,1,8,7,11,2,6,90,12};
    sort(nums.begin(),nums.end());
    int l = 0;
    int r = nums.size()-1;
    ListNode* root = buildtree(nums,l,r);
    traverse(root);
    return 0;
}