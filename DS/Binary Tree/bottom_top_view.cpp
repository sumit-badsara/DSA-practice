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

        void bottomViewUtil(node* root, int depth, int width, int &_min, int &_max, map<int, pair<int,int>> &bottomView)
        {
            if(root == NULL)
                return;
            
            if(depth>=bottomView[width].second)
                bottomView[width] = {root->val,depth};
            
            _min = min(width, _min);
            _max = max(width, _max);

            this->bottomViewUtil(root->left, depth+1, width-1, _min, _max, bottomView);
            this->bottomViewUtil(root->right, depth+1, width+1, _min, _max, bottomView);
        }

        void bottomView()
        {
            map <int,pair<int,int>> bottomView;
            int min=0, max=0;

            this->bottomViewUtil(this->root, 1, 0, min, max, bottomView);   

            for(int i=min;i<=max;i++)
                cout<<bottomView[i].first<<" ";
            cout<<"\n";
        }

        void TopViewUtil(node* root, int depth, int width, int &_min, int &_max, map<int, pair<int,int>> &bottomView)
        {
            if(root == NULL)
                return;
            
            if(bottomView[width].second == 0 || depth<=bottomView[width].second)
                bottomView[width] = {root->val,depth};
            
            _min = min(width, _min);
            _max = max(width, _max);

            this->TopViewUtil(root->left, depth+1, width-1, _min, _max, bottomView);
            this->TopViewUtil(root->right, depth+1, width+1, _min, _max, bottomView);
        }

        void TopView()
        {
            map <int,pair<int,int>> topView;
            int min=0, max=0;

            this->TopViewUtil(this->root, 1, 0, min, max, topView);   

            for(int i=min;i<=max;i++)
                cout<<topView[i].first<<" ";
            cout<<"\n";
        }
};

int main()
{

    /**
     *  Time Complexity : O(n)
     *  Space Complexity: O(n)
    **/

    /*    Tree-1

             20
            /   \
           8     22
         /  \     \
        5    3     25
            / \      
          10   14
    
    Ans : 5 10 3 14 25
    */
    
    BTree* btree = new BTree;
    btree->setRoot(20);
    btree->getRoot()->left = btree->newNode(8);
    btree->getRoot()->right = btree->newNode(22);
    btree->getRoot()->left->left = btree->newNode(5);
    btree->getRoot()->left->right = btree->newNode(3);
    btree->getRoot()->left->right->left = btree->newNode(10);
    btree->getRoot()->left->right->right = btree->newNode(14);
    btree->getRoot()->right->right = btree->newNode(25);
    
    cout<<"Bottom View Tree-1:\t";
    btree->bottomView();
    
    cout<<"Top View Tree-1:\t";
    btree->TopView();

    /*
        Tree-2

              20
            /    \
           8      22
         /   \    / \
        5     3  4   25
             / \      
            10 14 

        Ans: 5 10 4 14 25

    */

    btree->getRoot()->right->left = btree->newNode(4);
    
    cout<<"\nBottom View Tree-2:\t";
    btree->bottomView();
    
    cout<<"Top View Tree-2:\t";
    btree->TopView();

    return 0;
}