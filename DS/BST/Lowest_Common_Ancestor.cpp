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
        void findLca(node* root, int val1, int val2)
        {
            if(root->val>val1 && root->val>val2)
                findLca(root->left, val1, val2);
            else if(root->val<val1 && root->val<val2)
                findLca(root->right, val1, val2);
            else
                cout<<"LCA: "<<root->val<<"\n";
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
    /*
        Find LCA
        =========
        Time Complexity: O(log n)
        Memory Coplexity: O(1)
    */

    vector <int> pre({40,20,10,30,60,50,70});
    BST* newBst = new BST;
    int val1 = 20, val2 = 30;

    //Construct BSt from Preorder
    newBst->constructPreorder(pre);

    //Find LCA
    newBst->findLca(newBst->getRoot(), val1, val2);

    return 0;
}