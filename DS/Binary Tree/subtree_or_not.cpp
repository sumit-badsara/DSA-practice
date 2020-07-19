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

        void getInorder(node* root, vector<int> &inorder)
        {
            if(root==NULL)
            {
                inorder.push_back(INT_MIN);
                return ;
            }
            
            getInorder(root->left, inorder);
            inorder.push_back(root->val);
            getInorder(root->right, inorder);
        }

        void getPreorder(node* root, vector<int> &preorder)
        {
            if(root==NULL)
            {
                preorder.push_back(INT_MIN);
                return ;
            }

            preorder.push_back(root->val);
            getPreorder(root->left, preorder);
            getPreorder(root->right, preorder);
        }

        vector<int> computeLps(vector<int> pattern)
        {
            vector<int> lps(pattern.size(), 0);
            int len = 0;

            for(int i=1;i<pattern.size();)
            {
                if(pattern[len] == pattern[i])
                {
                    len++;
                    lps[i] = len;
                    i++;
                }
                else
                {
                    if(len!=0)
                        len = lps[len-1];
                    else
                    {
                        lps[i] = 0;
                        i++;
                    }
                }
            }

            return lps;
        }

        bool checkSubarray(vector<int> subarr, vector<int> arr)
        {
            vector<int> lps = computeLps(subarr);

            int j=0;
            for(int i=0;i<arr.size();)
            {
                if(arr[i]==subarr[j])
                {
                    i++;
                    j++;
                }

                if(j==subarr.size())
                    return true;

                if(i<arr.size() && subarr[j]!=arr[i])
                {
                    if(j!=0)
                        j = lps[j-1];
                    else
                        i++;
                }
            }
            return false;
        }

        bool compare(BTree* btree)
        {
            vector<int> inorder1, inorder2;
            getInorder(this->getRoot(), inorder1);
            getInorder(btree->getRoot(), inorder2);
            
            vector<int> preorder1, preorder2;
            getPreorder(this->getRoot(), preorder1);
            getPreorder(btree->getRoot(), preorder2);

            return checkSubarray(inorder1, inorder2) && checkSubarray(preorder1, preorder2);
        }

};

int main()
{

    /**
     *  Time Complexity : O(n)
     *  Space Complexity: O(n)
    **/

    /*    

        Binary Tree 2
        =============

                0
              /   \
             1     2
           /   \     \
          2     3     3
           \
            4

        Binary Tree 1
        =============
             1     
           /   \    
          2     3 
           \
            4

    */
    
    BTree* btree1 = new BTree;
    btree1->setRoot(1);
    btree1->getRoot()->left = btree1->newNode(2);
    btree1->getRoot()->right = btree1->newNode(3);
    btree1->getRoot()->left->right = btree1->newNode(4);

    BTree* btree2 = new BTree;
    btree2->setRoot(0);
    btree2->getRoot()->left = btree2->newNode(1);
    btree2->getRoot()->right = btree2->newNode(2);
    btree2->getRoot()->right->right = btree2->newNode(3);
    btree2->getRoot()->left->left = btree2->newNode(2);
    btree2->getRoot()->left->right = btree2->newNode(3);
    btree2->getRoot()->left->left->right = btree2->newNode(4);
    
    if(btree1->compare(btree2))
        cout<<"Yes! the tree is subtree of given Binary Tree.\n";
    else
        cout<<"No! the tree isn't subtree of given Binary Tree.\n";
    
    return 0;
}