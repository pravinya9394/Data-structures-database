#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;
class Root
{
public:
    int data;
    Root *left;
    Root *right;
};
void level_order(Root *root)
{
    if (root == NULL)
        return;
    queue<Root *> q;
    Root *temp;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    while (!q.empty())
        q.pop();
}
bool find_ele(Root *root, int key) //FIND ELEMENT IN BST
{                                  //O(n)   O(n)
    if (root == NULL)              //(RECURSIVELY)
        return 0;
    if (root->data < key)
        return find_ele(root->right, key);
    else if (root->data > key)
        return find_ele(root->left, key);
    return (bool)root;
}
bool find_element(Root *root, int key) //same que(ITERATIVELY)
{                                      //O(n)    O(1)
    if (root == NULL)
        return root;
    while (root)
    {
        if (root->data == key)
            return 1;
        if (root->data < key)
            root = root->right;
        else if (root->data > key)
            root = root->left;
    }
    return 0;
}
Root *min_element(Root *root) //same que (RECURSIVELY)
{                             //O(n)  O(n)
    if (root == NULL)
        return root;
    if (root->left)
        return min_element(root->left);
    else
        return root;
}
Root *min_ele(Root *root) //Finding min element in BST
{                         //O(logn)  O(1)
    if (root == NULL)     //(ITERATIVELY)
        return root;
    while (root)
    {
        if (root->left == NULL)
            return root;
        if (root->left)
            root = root->left;
    }
}
Root *max_ele(Root *root) //find max element in BST
{                         //(RECURSIVELY)
    if (root == NULL)     //O(n)  O(n)
        return root;
    if (root->right)
        return max_ele(root->right);
    else
        return root;
}
Root *max_element(Root *root) //same que (ITERATIVELY)
{                             //O(n)  O(1)
    if (root == NULL)
        return root;
    while (root)
    {
        if (!root->right)
            return root;
        if (root->right)
            root = root->right;
    }
}
Root *LCA(Root *root, Root *root1, Root *root2) // que no 47  FIND LCA(ITERATIVELY)
{                                               //O(n)   O(n)[skew trees]
    while (1)
    {
        if ((root->data > root1->data && root->data < root2->data) || (root->data > root2->data && root->data < root1->data))
            return root;
        if (root1->data < root->data)
            root = root->left;
        else
            root = root->right;
    }
}
bool BST_or_NOT(Root *root)                          //QUE NO 50
{                                                    //(RECURSIVELY)
    if (!root)                                       //to find TREE IS BST OR NOT
        return 1;                                    //inconsistent as it check only for current node
    if (root->left && root->data < root->left->data) //so we have to consider some broader concept
        return 0;
    if (root->right && root->data > root->right->data) //     6
        return 0;                                      //   /   \
    if(!BST_or_NOT(root->left)||!BST_or_NOT(root->right))              //   2    8
    return 0;                                          //   /  \ 
    return 1;                                                          //  1    9
                                                       //this example is not bst but this algo is giving it as a BST
}
bool Is_BST(Root *root, int *key)
{
    if (!root)
        return 1;
    if (!Is_BST(root->left, key))
        return 0;
    if (root->data < *key)
        return 0;
    *key = root->data;
    return Is_BST(root->right, key);
}
void inorder(Root *root)
{
    if (!root)
        return;
    int i = 0;
    vector<int> arr;
    inorder(root->left);
    arr[i++] = root->data;
    inorder(root->right);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i];
}
int level_order(Root *root, int k) //que no 60
{                                  //kth smallest element in BST
    if (root == NULL)              //O(n) O(n)
        return 0;
    queue<Root *> q;
    Root *temp;
    q.push(root);
    vector<int> v;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    while (!q.empty())
        q.pop();
    sort(v.begin(), v.end());
    return v[k - 1];
}
void range_que(Root *root, int k1, int k2) //que no 65
{                                          //O(N)  O(N)
    if (!root)
        return;
    if (root->data >= k1)
        range_que(root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2)
        cout << root->data << " ";
    if (root->data <= k2)
        range_que(root->right, k1, k2);
}
/*************6.12 Balanced Binary Search Trees
In earlier sections we have seen different trees whose worst case complexity is O(n), where n is
the number of nodes in the tree. This happens when the trees are skew trees. In this section we
will try to reduce this worst case complexity to O(logn) by imposing restrictions on the heights.
In general, the height balanced trees are represented with HB(k), where k is the difference
between left subtree height and right subtree height. Sometimes k is called balance factor.
*/


/**Full Balanced Binary Search Trees
 * In HB(k), if k = 0 (if balance factor is zero), then we call such binary search trees as full
balanced binary search trees. That means, in HB(0) binary search tree, the difference between left
subtree height and right subtree height should be at most zero. This ensures that the tree is a full
binary tree.
*/


/***6.13 AVL (Adelson-Velskii and Landis) Trees
In HB(k), if k = 1 (if balance factor is one), such a binary search tree is called an AVL tree. That
means an AVL tree is a binary search tree with a balance condition: the difference between left
subtree height and right subtree height is at most 1.

A binary tree is said to be an AVLtree, if:
• It is a binary search tree, and
• For any node X, the height of left subtree of X and height of right subtree of X differ
by at most 1

the minimum
number of nodes with height h is:
N(h) = N(h – 1) + N(h – 2) + 1*/
int is_avl(Root*root)          //que no 77
{                              //O(N) O(N)
    if(!root)
    return 0;
    int left=is_avl(root->left);
    if(left==-1)
    return left;
    int right=is_avl(root->right);
    if(right==-1)
    return right;
    if(abs(left-right)>-1)
    return -1;
    return max(left,right)+1;
    
}
int main()
{
    Root*root=new Root();
    root->data=4;
    root->left=new Root();
    root->left->data=2;
    root->right=new Root();
    root->right->data=6;
    root->left->left=new Root();
    root->left->left->data=1;
    root->left->right=new Root();
    root->left->right->data=3;
    root->right->left=new Root();
    root->right->left->data=5;
    root->right->right=new Root();
    root->right->right->data=7;
    level_order(root);

    // Root*root1=new Root();
    // root1->data=1;
    // root1->left=new Root();
    // root1->left->data=2;
    // root1->right=new Root();
    // root1->right->data=3;
    // root1->left->left=new Root();
    // root1->left->left->data=4;
    // root1->left->right=new Root();
    // root1->left->right->data=5;
    // root1->right->left=new Root();
    // root1->right->left->data=6;
    // root1->right->right=new Root();
    // root1->right->right->data=7;


    // Root*root2=new Root();
    // root2->data=1;
    // root2->left=new Root();
    // root2->left->data=2;
    // root2->right=new Root();
    // root2->right->data=3;
    // root2->left->left=new Root();
    // root2->left->left->data=4;
    // root2->left->right=new Root();
    // root2->left->right->data=5;
    // root2->right->left=new Root();
    // root2->right->left->data=6;
    // root2->right->right=new Root();
    // root2->right->right->data=986;
    // cout<<endl;
    // cout<<find_ele(root,7);
    //  cout<<endl;
    // cout<<find_element(root,5);
    // cout<<endl;
    // cout<<min_ele(root)->data;
    // cout<<endl;
    // cout<<min_element(root)->data;
    // cout<<endl;
    // cout<<max_ele(root)->data;
    // cout<<endl;
    // cout<<max_element(root)->data;
    // cout<<endl;
    // cout<<LCA(root,root->left->right,root->left->left)->data;
    // cout<<endl;
    // cout<< BST_or_NOT(root);
    // cout<<endl;
    // cout<<Is_BST(root,0);
    cout<<endl;
    // inorder(root);
    // cout<<level_order(root,2);
    // range_que(root,2,6);
    cout<<is_avl(root);
    return 0;
}





























































