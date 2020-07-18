#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

class BST{
    private:
        node* root = new node;
    
    public:

        //get root node of this object
        node* getRoot()
        {
            return this->root;
        }

        //create a new node with NULL childs and given value
        node* new_node(int val)
        {
            node* newNode = new node;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->val = val;
            return newNode;
        }

        //display inorder traversal of bst
        void inOrderTraversal(node* root)
        {
            if(root==NULL)
                return;
            
            inOrderTraversal(root->left);
            cout<<root->val<<" ";
            inOrderTraversal(root->right);
        }

        //create bst from preorder (main code)
        node* constructPreorderUtil(vector<int> pre, int &index, int key, int size, int min, int max)
        {
            if(index>=size)
                return NULL;
            
            node* myNode = NULL;
            if(key<=max && key>=min)
            {
                myNode = new_node(key);
                index++;
                if(index<size)
                {   
                    myNode->left  = constructPreorderUtil(pre, index, pre.at(index), size, min, key-1);
                    myNode->right = constructPreorderUtil(pre, index, pre.at(index), size, key, max);   
                }
            }
            return myNode;
        }

        //create bst from preorder (driver code)
        void constructPreorder(vector<int> pre)
        {
            int index = 0;
            this->root = constructPreorderUtil(pre, index, pre.at(index), pre.size(), INT_MIN, INT_MAX);
        }


};

int main()
{
    vector <int> pre({40, 30, 35, 80, 25, 100});
    BST* newBst = new BST;

    //Construct BSt from Preorder
    newBst->constructPreorder(pre);

    //Display Inorder traversal of tree
    newBst->inOrderTraversal(newBst->getRoot());

    return 0;
}