#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Root{                             //ROOOT DECLARATION
    public:
    int data;
    Root*left;
    Root*right;
};
void preorder(Root*root)                //PREORDER TRAVERSAL(RECURSIVELY)
{                                       //O(n)  O(n)
    if(root==NULL)
    return ;
    
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
}
void inorder(Root*root)                  //INORDER TRAVERSAL(RECURSIVELY)
{                                         //O(n)  O(n)
    if(root==NULL)
    return ;
    
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
}
void postorder(Root*root)                 //POSTORDER TRAVERSAL(RECURSIVELY)
{                                          //O(n)  O(n)
    if(root==NULL)
    return ;
    
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
}
void preorder_iterative(Root*root)            //NON RECURSIVE PREORDER
{                                              //O(n)  O(n)
    stack<Root*>st;
    while(1)
    {
        while(root!=NULL);
        {
            cout<<root->data<<" ";
            st.push(root);
            root=root->left;
        }
        if(st.empty())
        break;
        root=st.top();
        st.pop();
        root=root->right;
    }
    while(!st.empty())
    st.pop();
}
void inorder_iterative(Root*root)               //NON RECURSIVE INORDER
{                                                //O(n)  O(n)
    stack<Root*>st;
    while(1)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        if(st.empty())
        break;
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
    while(!st.empty())
    st.pop();
}
void level_order(Root*root)                        //LEVEL ORDER TRAVERSAL(iteratively)
{                                                  //USING QUEUE
                                                   //O(n)   O(n)
    if(root==NULL)
    return;
    queue<Root*>q;
    Root*temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
    while(!q.empty())
    q.pop();
}
int maximum_ele(Root*root)               //que no 1
                                         //O(n)   O(n)
{
    int r,l;
    int maximum=0;
    if(root!=NULL)
    {
        r=maximum_ele(root->left);
        l=maximum_ele(root->right);
        if(r>l)
        maximum=r;
        else
        maximum=l;
        if(root->data>=maximum)
        return root->data;
        else
        return maximum;
    }
    return 0;
}
int max_in_tree(Root*root)                   //que no 2    WITHOUT RECURSION USING QUEUE
                                             // O(n)   O(n)
{
    queue<Root*>q;
    Root*temp;
    int maximum=0;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data>maximum)
        maximum=temp->data;
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
    while(!q.empty())
    {
        q.pop();
    }
    return maximum;
}
int present_or_not(Root*root,int key)                //que no 3
{                                                    //O(n)  O(n)
                                                    //FIND EITHER ELEMENT PRESENT OR NOT
    if(root==NULL)
      return 0;
    int l=present_or_not(root->left,key);
    int r=present_or_not(root->right,key);
    if(l==key)
      return l;
    if(r==key)
      return r;
    if(root->data==key)
      return key;
    return 0;
}
int present_or_nod(Root*root,int key)        //QUE NO 4
{
    if(root==NULL)
    return 0;
    queue<Root*>q;
    Root*temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->data==key)
        return key;
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
     while(!q.empty())
     q.pop();
    return 0;
}
void insert_root(Root*root,int data)                 //QUE NO 5
{                                                    //INSERT ROOT(ITERATIVELY)
    Root*newroot=new Root();                         //O(n)   O(n)
    newroot->data=data;
    newroot->left=NULL;
    newroot->right=NULL;
    queue<Root*>q;
    Root*temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        
        if(temp->left!=NULL)
        q.push(temp->left);
        else
        {
            temp->left=newroot;
            return;
        }
        if(temp->right!=NULL)
        q.push(temp->right);
        else
        {
            temp->right=newroot;
            return;
        }
    }
    while(!q.empty())
    q.pop();

}
int size_of_tree(Root*root)                      //QUE NO 6
{                                                //size of tree(RECURSIVELY)
    if(root==NULL)                               //O(n)   O(n)
    return 0;
    return (size_of_tree(root->left)+size_of_tree(root->right)+1);
}
int size_Of_tree(Root*root)                      //QUE NO 7(SAME)
{                                                //size of tree(ITERATIVELY)
    if(root==NULL)                               //O(n)   O(n)
    return 0;
    queue<Root*>q;   
    Root*temp;
    q.push(root);
    int cnt=0;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cnt++;
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
    while(!q.empty())
    q.pop();
    return cnt;
}
void reverse_level_order(Root*root)                //QUE NO 8
{                                                   //O(N) O(N)
                                                   //REVERSE OF LEVEL ORDER TRAVERSAL(iteratively)
    if(root==NULL)
    return;
    queue<Root*>q;
    Root*temp;
    stack<Root*>st;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        if(temp->right!=NULL)
        q.push(temp->right);
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        st.push(temp);
    }
    while(!q.empty())
    q.pop();
    while(!st.empty())
    {
        cout<<st.top()->data<<" ";
        st.pop();
    }
}
void delete_tree(Root*root)                     //que no 9
{                                               //deleting tree
    if(root=NULL)                               //O(n) O(n)
    return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);

}
int height_of_tree(Root*root)                      //que no 10
{                                                  //height of tree(RECURSION)
    if(root==NULL)                                 //O(n) O(n)
    return 0;
    int left_h=height_of_tree(root->left);
    int right_h=height_of_tree(root->right);
    return 1+max(left_h,right_h);
}
int height_Of_tree(Root*root)                         //QUE NO 11 (ITERATIVELY)
{                                                     //O(n)   O(n)
    if(root==NULL)                //HERE 2 WHILE LOOPS ARE PRESENT BUT TIME COMPLEXITY IS O(n)
                                  //BECAUSE ONE WHILE LOOP IS ITERATING N TIMES AND ANOTHER FOR CONSTANT AMOUNT
                                 //SO O(n*CONST)~O(n)
    return 0;
    queue<Root*>q;
    Root*temp;
    int lambi=0;
    int nodecount=0;
    q.push(root);
    while(!q.empty())
    {
        lambi++;
        nodecount=q.size();
        while(nodecount--)
        {
            temp=q.front();
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
            q.pop();
        }
    }
    return lambi;
}
Root*deepest_node(Root*root)                //que no 12
{                                           //O(n)  O(n)
    if(root==NULL)                           //ITERATIVELY(deepest root)
    return root;
    queue<Root*>q;
    Root*temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
    while(!q.empty())
    q.pop();
    return temp;
}
void delete_perticular_root(Root*root,int data)                   //SOME INSTENTSANCY IS THERE
{                                                                //IT IS WORKING BUT HAS TO MODIFY
    if(root==NULL)
    return;
    queue<Root*>q;
    Root*temp;
    Root*temp1;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==data)
        temp1=temp;
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
    swap(temp->data,temp1->data);
    
    // while(!q.empty())
    // q.pop();
    temp=NULL;
    delete temp;
}
int count_leaves(Root*root)                //QUE NO 14    COUNT NUMBER OF LEAVES
{                                          //O(n)   O(n)
    if(root==NULL)
    return 0;
    queue<Root*>q;
    int cnt=0;
    Root*temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left==NULL&&temp->right==NULL)
        cnt++;
        else
        {
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
    }
    while(!q.empty())
    q.pop();
    return cnt;
}
int count_full_nodes(Root*root)                 //que no 15
{                                              //O(n)   O(n)
    if(root==NULL)                             //TO FIND FULL NODES(having left and right nodes both)
    return 0;
    queue<Root*>q;
    Root*temp;
    int cnt=0;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left!=NULL&&temp->right!=NULL)
        cnt++;
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    while(!q.empty())
    q.pop();
    return cnt;
}
int count_half_nodes(Root*root)                       //que no 16
{                                                    //FIND NUMBER OF HALF NODES(having left or right child only)
    if(root==NULL)                                    //O(n)   O(n)
    return 0;
    queue<Root*>q;
    Root*temp;
    int cnt=0;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left&&!temp->right||!temp->left&&temp->right)
        cnt++;
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    while(!q.empty());
    q.pop();
    return cnt;
}
bool are_identical(Root*root1,Root*root2)           //que no 17
{                                                   //identical or not
    if(!root1&&!root2)                              //O(n)  O(n)
    return 1;
    if(!root1||!root2)
    return 0;
    return(root1->data==root2->data&&are_identical(root1->left,root2->left)&&are_identical(root1->right,root2->right));
}
int width_of_tree(Root*root)            //que no 18{CHECK WHAT IS WIDTH/DIAMETER OF TREE}
{                                       //NOT COMPLETED YET
    if(root==NULL)
    return 0;
    int width=0;
    int l=width_of_tree(root->left);
    int r=width_of_tree(root->right);
    if(l+r>width)
    width=l+r;
    return max(l,r)+1;
}
int sum_of_all_nodes(Root*root)                //QUE NO 22  SUM OF ALL NODES OF TREE(RANDOM QUESTION)
{                                              //O(n)  O(n) (ITERATIVELY)
    if(root==NULL)
    return 0;
    queue<Root*>q;
    Root*temp;
    int sum=0;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        sum+=temp->data;
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    while(!q.empty())
    q.pop();
    return sum;
}
int sum_Of_all_nodes(Root*root)                //QUE NO 22(RECURSIVELY)
{                                              //O(n)  O(n)
    if(!root)
    return 0;
    return root->data+sum_Of_all_nodes(root->left)+sum_Of_all_nodes(root->right);
}
int maximum_sum_level(Root*root)             //QUE NO 19
{                                            //maximum sum level
    if(root==NULL)                           //O(n)   O(n)
    return 0;
    queue<Root*>q;
    Root*temp;
    q.push(root);
    int result=root->data;
    while(!q.empty())
    {
        int cnt=q.size();
        int sum=0;
        while(cnt--)
        {
            temp=q.front();
            q.pop();
            sum+=temp->data;
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        }
    result=max(result,sum);
    }
    while(!q.empty())
    q.pop();
    return result;
}
void print_arr(int arr[],int len)
{
    for(int i=0;i<len;i++)
    cout<<arr[i]<<"->";
    cout<<endl;
}
void ALL_root_to_leaf_path(Root*root,int arr[],int len)      //que no 20
{                                                            //find all root to leaf path
    if(root==NULL)                                           //O(n)  O(n)
    return;
    arr[len]=root->data;
    len++;
    if(!root->left&&!root->right)
    print_arr(arr,len);
    else
    {
        ALL_root_to_leaf_path(root->left,arr,len);
        ALL_root_to_leaf_path(root->right,arr,len);
    }
}
Root*mirror_of_tree(Root*root)                  //QUE NO 24
{                                               //finding mirror image of given tree
    if(root==NULL)                             //O(n) O(n)
    return root;
    mirror_of_tree(root->left);
    mirror_of_tree(root->right);
    swap(root->left,root->right);
    return root;
}
bool mirror_or_not(Root*root1,Root*root2)            //MIRROR OR NOT(tree)
{                                                   //Que no 25
    if(!root1&&!root2)                              //O(n)  O(n)
    return 1;
    if(!root1||!root2)
    return 0;
    else
    return (root1->data==root2->data&&mirror_or_not(root1->left,root2->right)&&mirror_or_not(root1->right,root2->left));
}
Root*LCA(Root*root,Root*root1,Root*root2)           //QUE NO 26
{                                                    //*******VERY IMP QUE*********
    if(root==NULL)                                   //LOWEST COMMON ANCESTOR
    return root;                                      //O(n)  O(n)
    if(root1==root||root2==root)
    return root;
    Root*l=LCA(root->left,root1,root2);
    Root*r=LCA(root->right,root1,root2);
    if(l&&r)
    return root;
    else
    return (l?l:r);
}

Root*All_ancestors(Root*root,Root*node)                            //QUE no 29
{                                                                  //finding all ancestors
    if(root==NULL)                                                 //O(n)  O(n)  
    return root;
    if(root==node)
    return root;
    if(root->left==node||root->right==node||All_ancestors(root->left,node)||All_ancestors(root->right,node))
    cout<<root->data<<" ";
}
void zig_zag_traversal(Root*root)                                //que no 30
{                                                                //zigzag traversal of tree
    if(root==NULL)                                               //O(n)  O(n)
    return ;
    stack<Root*>current;
    stack<Root*>next;
    current.push(root);
    Root*temp;
    bool left_to_right=1;
    while(!current.empty())
    {
        temp=current.top();
        current.pop();
        if(temp)
        {
            cout<<temp->data<<" ";
        if(left_to_right)
        {
            if(temp->left)
            next.push(temp->left);
            if(temp->right)
            next.push(temp->right);
        }
        else
        {

            if(temp->right)
            next.push(temp->right);
            if(temp->left)
            next.push(temp->left);
        }
        }
        if(current.empty())
        {
            left_to_right=!left_to_right;
            swap(current,next);
        }
    }
}

/*HOW MANY DIFFFERENT BINARY TREES ARE POSSIBLE WITH N NODES?
ANS=>       (2^N -N)

**************************************************************/
bool isomorphic(Root*root1,Root*root2)                       //que no 42 
{                                                           //isomorphic=>structure is same no need to have same values
    if(!root1&&!root2)                                       //O(n)  O(n)
    return 1;
    if(!root1&&root2||root1&&!root2)
    return 0;
    return isomorphic(root1->left,root2->left)&&isomorphic(root1->right,root2->right);
}
bool quasi_isomorphic(Root*root1,Root*root2)                    //que no 43
{                                                               //quasi isomorphic
    if(!root1&&!root2)                                          //O(n)  O(n)
    return 1;
    if(!root1||!root2)
    return 0;
    return quasi_isomorphic(root1->left,root2->left)&&isomorphic(root1->right,root2->right)||isomorphic(root1->left,root2->right)&&isomorphic(root1->right,root2->left);
}
// Representation of GENERIC TREES
// Since our objective is to reach all nodes of the tree, a possible solution to this is as follows:
// • At each node link children of same parent (siblings) from left to right.
// • Remove the links from parent to all children except the first child.
// Note: Since we are able to convert any generic tree to binary representation; in practice we use
// binary trees. We can treat all generic trees with a first child/next sibling representation as binary
// trees.


//  Threaded Binary Tree Traversals (Stack or Queue-less Traversals)
// In earlier sections we have seen that, preorder, inorder and postorder binary tree traversals used
// stacks and level order traversals used queues as an auxiliary data structure. In this section we
// will discuss new traversal algorithms which do not need both stacks and queues. Such traversal
// algorithms are called threaded binary tree traversals or stack/queue – less traversals.
// The common convention is to put predecessor/successor information. That means, if we are
// dealing with preorder traversals, then for a given node, NULL left pointer will contain preorder
// predecessor information and NULL right pointer will contain preorder successor information.
// These 
// Types of Threaded Binary Trees
// Based on above discussion we get three representations for threaded binary trees.
// • Preorder Threaded Binary Trees: NULL left pointer will contain PreOrder
// predecessor information and NULL right pointer will contain PreOrder successor
// information.
// • Inorder Threaded Binary Trees: NULL left pointer will contain InOrder
// predecessor information and NULL right pointer will contain InOrder successor
// information.
// • Postorder Threaded Binary Trees: NULL left pointer will contain PostOrder
// predecessor information and NULL right pointer will contain PostOrder successor
// information.


// Expression Trees
// A tree representing an expression is called an expression tree. In expression trees, leaf nodes are
// operands and non-leaf nodes are operators. That means, an expression tree is a binary tree where
// internal nodes are operators and leaves are operands. An expression tree consists of binary
// expression. But for a u-nary operator, one subtree will be empty. The figure below shows a
// simple expression tree for (A + B * C) / D.

// XOR Trees
// This concept is similar to memory efficient doubly linked lists of Linked Lists chapter. Also, like
// threaded binary trees this representation does not need stacks or queues for traversing the trees.
// This representation is used for traversing back (to parent) and forth (to children) using ⊕
// operation. To represent the same in XOR trees, for each node below are the rules used for
// representation:
// • Each nodes left will have the ⊕ of its parent and its left children.
// • Each nodes right will have the ⊕ of its parent and its right children.
// • The root nodes parent is NULL and also leaf nodes children are NULL nodes



/****************************BINARY SEARCH TREE********************************************/
int maximum(Root*root)
{
    if(root==NULL)
    return -1;
    else
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int main()
{
    // Root*root=new Root();
    // root->data=1;
    // root->left=new Root();
    // root->left->data=2;
    // root->right=new Root();
    // root->right->data=3;
    // root->left->left=new Root();
    // root->left->left->data=4;
    // root->left->right=new Root();
    // root->left->right->data=5;
    // root->right->left=new Root();
    // root->right->left->data=6;
    // root->right->right=new Root();
    // root->right->right->data=7;


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
    
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // preorder_iterative(root)
    // cout<<endl;
    // inorder_iterative(root);
    // cout<<endl;
    //level_order(root);
    // cout<<maximum_ele(root);
    // cout<<endl;
    // cout<<max_in_tree(root);
    // cout<<endl;
    //cout<< present_or_nod(root,0);
    // insert_root(root,100);
    // level_order(root);
    // cout<<size_of_tree(root);
    // cout<<endl;
    // cout<<size_Of_tree(root);
    //reverse_level_order(root);
    //delete_tree(root); 
    //cout<<endl;
    //level_order(root);
    //cout<<height_of_tree(root);
    //cout<<endl;
    //cout<<height_Of_tree(root);
    //cout<<endl;
    //cout<<deepest_node(root)->data;
    // delete_perticular_root(root,2);
    // level_order(root);
    //cout<<count_leaves(root);
    //cout<<count_full_nodes(root);
    //cout<<count_half_nodes(root);
    // cout<<are_identical(root1,root2);
    //cout<<width_of_tree(root);
    //cout<<sum_of_all_nodes(root);
    //cout<<sum_Of_all_nodes(root);
    //cout<<maximum_sum_level(root);                                         
    /*int len=0;                                            //simply for que no 20
    int arr[len];                              
    ALL_root_to_leaf_path(root,arr,len);*/
    //mirror_of_tree(root2);
    //level_order(root);
    // cout<<mirror_or_not(root1,root2);
    //cout<<LCA(root,root->left->left,root->left->right)->data;
    // All_ancestors(root,root->left->right);
    // zig_zag_traversal(root);
    //cout<<isomorphic(root1,root2);
    // cout<<quasi_isomorphic(root1,root2);
    cout<<maximum(root);
    return 0;
}