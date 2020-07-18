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

        int findMinHeight(node* root)
        {
            if(root==NULL)
                return 0;

            return min(
                findMinHeight(root->left)+1,
                findMinHeight(root->right)+1
            );
        }

        int findMaxHeight(node* root)
        {
            if(root==NULL)
                return 0;

            return max(
                findMaxHeight(root->left)+1,
                findMaxHeight(root->right)+1
            );
        }
};

int main()
{
    BTree* btree = new BTree;
    btree->setRoot(10);
    btree->getRoot()->left = btree->newNode(20);
    btree->getRoot()->right = btree->newNode(40);
    btree->getRoot()->left->left = btree->newNode(2);
    btree->getRoot()->left->right = btree->newNode(21);
    
    cout<<"Min height of tree: "<<btree->findMinHeight(btree->getRoot());
    cout<<"\n";
    cout<<"Max height of tree: "<<btree->findMaxHeight(btree->getRoot());
    cout<<"\n";
       
}