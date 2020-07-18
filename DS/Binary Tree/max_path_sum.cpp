#include <bits/stdc++.h>

using namespace std;

struct node{
    node *left, *right;
    int val;
};

class BTree{
    private:
        node* root;
    public:
        node* getRoot()
        { return root; }

        void setRoot(int val)
        { root = newNode(val); }

        node* newNode(int val)
        {
            node* Node = new node;
            Node->left = NULL;
            Node->right = NULL; 
            Node->val = val;

            return Node;
        }

        int findMaxPathSumUtil(node* root, int &maxSum)
        {
            if(root==NULL)
                return 0;
            
            int left = findMaxPathSumUtil(root->left, maxSum);
            int right = findMaxPathSumUtil(root->right, maxSum);
            
            if(left+right+root->val > maxSum)
                maxSum = left+right+root->val;
            else if(root->val > maxSum)
                maxSum = root->val;

            return  max({left+root->val, right+root->val, root->val, 0});
        }
        
        int findMaxPathSum(node* root)
        {
            int maxSum = -1;
            findMaxPathSumUtil(root, maxSum);
            return maxSum;
        }
};

int main()
{
    /*
        Time Complexity : O(n)
        Space Complexity: O(log n) | O(h)
    */

    BTree* btree = new BTree;
    btree->setRoot(10);
    btree->getRoot()->left = btree->newNode(2);
    btree->getRoot()->right = btree->newNode(10);
    btree->getRoot()->left->left = btree->newNode(20);
    btree->getRoot()->left->right = btree->newNode(1);
    btree->getRoot()->right->right = btree->newNode(-25);
    btree->getRoot()->right->right->left = btree->newNode(3);
    btree->getRoot()->right->right->right = btree->newNode(4);

    cout<<btree->findMaxPathSum(btree->getRoot())<<"\n";
    return 0;    
}