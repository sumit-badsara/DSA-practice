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

        node* deletePathForKUtil(node* _root, int depth, int k)
        {
            if(_root==NULL)
                return NULL;

            if(_root->left==NULL && _root->right==NULL && depth<k)
            {
                cout<<"Deleted "<<_root->val<<"\n";
                delete _root;
                return NULL;
            }    

            _root->left = deletePathForKUtil(_root->left, depth+1, k);
            _root->right = deletePathForKUtil(_root->right, depth+1, k);

            return _root;
        }

        void deletePathForK(int k)
        {
            this->deletePathForKUtil(this->root, 1, k);
        }

};

int main()
{

    /**
     *  Time Complexity : O(n)
     *  Space Complexity: O(log n) | O(h)
    **/

    /*    Tree-1

                1
              /   \
             2     3
           /   \     \
          4     5     6
         /           /
        7           8 
    
     For k=4, We remove 1->2->5 (Only 5 as 1->2 us also part of other path)
    */
    
    BTree* btree = new BTree;
    btree->setRoot(1);
    btree->getRoot()->left = btree->newNode(2);
    btree->getRoot()->right = btree->newNode(3);
    btree->getRoot()->left->left = btree->newNode(4);
    btree->getRoot()->left->right = btree->newNode(5);
    btree->getRoot()->left->left->left = btree->newNode(7);
    btree->getRoot()->right->right = btree->newNode(6);
    btree->getRoot()->right->right->left = btree->newNode(8);
    
    btree->deletePathForK(4);

    return 0;
}