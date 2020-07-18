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

        bool isFullBTreeUtil(node* root)
        {
            if(root==NULL)
                return false;

            bool left = isFullBTreeUtil(root->left);
            bool right = isFullBTreeUtil(root->right);

            if(left==right) return true;
            
            return false;
        }

        bool isFullBTree()
        {
            if(root==NULL)
                return true;
            return isFullBTreeUtil(this->root);
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

    //Comment below lines to make it Full binary tree 
    btree->getRoot()->right->right = btree->newNode(-25);
    btree->getRoot()->right->right->left = btree->newNode(3);
    btree->getRoot()->right->right->right = btree->newNode(4);
    
    if(btree->isFullBTree())
        cout<<"Given Tree is full binary tree.\n";
    else
        cout<<"Given Tree isn't full binary tree.\n";
       
}