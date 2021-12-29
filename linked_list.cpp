#include<iostream>
#include<stack>
#include<math.h>
#include<string>
using namespace std;

/****************************************************************************LINKED LIST ********************************************************************************
 * ***************************************************************
 * *********************************************************************************************************************************************************************/
class node{
    public:
    int data;                                 //node declaration
    node* next;
};
void insert_at_head(node**head_ref,int data){
    node*new_node=new node();                  /*inserting new node before head*/
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void display(node*head)
{
    while(head!=NULL)
    {                                          /*displaying nodes of linked list*/
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int count_node(node*head)
{
    int cnt=0;
    while(head!=NULL)                         /*count number of nodes present in linkes list*/
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}
void insert_at_tail(node**head_ref,int data)
{
    node*new_node=new node();
    new_node->data=data;                       /*inserting new node after at tail*/
    node*last=*head_ref;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    return;
}
void insert_after_node(node*prev_node,int data)
{
    if(prev_node==NULL)
    {
        cout<<"previos node cannot be NULL"<<endl;           /*inserting node after given node*/
        return;
    }
    node*new_node=new node();
    new_node->data=data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
int nth_node_from_end(node*head,int n)
{
    node*temp=head;
    int cnt=0;
    while(temp!=NULL)                                      /*finding nth node from the end of the linked list*/
    {                                                      //linked list problems in N.K book                                                         //que no-2
        cnt++;
        temp=temp->next;
    }
    for(int i=1;i<cnt-n+1;i++)                             //BRUTE FORCE APPPROACH 
    {                                                      //time complexity:O(n)                                                            //
        head=head->next;                                   //space complexity:O(1)
    }
    return head->data;
}
int nth_node(node*head,int n)
{
    node*ptr1=head;
    node*ptr2=head;
    while(n--)                                               //optimize solution
    ptr1=ptr1->next;                                          //time complexity:O(n) 
    while(ptr1!=NULL)                                          //space complexity:O(1)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr2->data;
}
void cyclic_or_not(node*head)
{
    node*fast=head;
    node*slow=head;
    while(fast!=NULL&&slow!=NULL&&fast->next!=NULL)              //que no 6
    {                                                           //FLOYD ALGO for cycle detection
        fast=fast->next->next;                                  //we can also use 2&3 steps intead but increases complexity
                                                                //optimize solution is this 
        slow=slow->next;                                         //time complexity:O(n) 
        if(fast==slow)                                           //space complexity:O(1)
        {
            cout<<"cyclic"<<endl;                         
            return;
        }
    }
    cout<<"NULL terminated"<<endl;
    return;
}
int cyclics_or_not(node*head)
{
    node*fast=head;
    node*slow=head;
    bool flag=0;
    while(fast!=NULL&&slow!=NULL&&fast->next!=NULL)            //que no 11
                                                                //for finding starting node of loop
    {                                                           //FLOYD ALGO EXTENSION for cycle detection
        fast=fast->next->next;                                   //optimize solution
        slow=slow->next;                                         //time complexity:O(n) 
        if(fast==slow)                                             //space complexity:O(1)
        {
            cout<<"cyclic"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    return slow->data;
    }
    return 0;
}
void make_cycle(node*head,node*temp1)
{
    node*temp=head;
    while(head!=temp1)                       //Make cycle in linked list
    {
        head=head->next;
    }
    temp=head;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
}
void deletenode(node**head,int val)
{
    if(*head==NULL)
    return;                                 //delete node from linked list
    
    node*temp1=*head;
    
    while(temp1->next->data!=val)
    {
        temp1=temp1->next;
    }
    node*temp=temp1->next;
    temp1->next=temp1->next->next;
    delete temp;
    
}
int lenght_of_loop(node*head)
{                                             //if cycle exist find lenght of loop
    node*fast=head;                           //que no:14
    node*slow=head;
    int cnt=0; 
    bool flag=0;
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)      // time complexity:O(n)
    {                                                     // space complexity:O(1)
        slow=slow->next;
        fast=fast->next->next;
       
        if(fast==slow)
        {
            flag=1;
            break;
        }
    }
     
        if(flag==1)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            fast=fast->next;
            while(fast!=slow)
        {
            cnt++;
            fast=fast->next;
        }
        return cnt;
        }
}
// void insert_in_sorted_list(node*head,node*newnode)
// {
//     node*curr=head,*temp;
//     if(head==NULL)
//     cout<<head->data<<" ";
//     while(curr->data<newnode->data||curr!=NULL)
//     {
//         temp=curr;
//         cout<<curr->data<<" ";
//         curr=curr->next;
//     }
//    newnode->next=curr;
//    temp->next=newnode; 
//    while()
//}
node*reverse_list(node*head)
{                                                       //que no 16
    node*prev=NULL;                                    // Time Complexity: O(n). Space Complexity: O(1)
    node*curr=head;
    node*next=NULL;                                    // Reverse a linked list 
    while(curr!=NULL)                                  //ITERATIVELY
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void merge_point(node*head1,node*head2)                //que no 17
{                                                     //Total time complexity = O(max(m, n)).
                                                       // Space Complexity = O(1).                            
                                                       //finding merging point of two linked list
    int cnt1=0,cnt2=0;
    while(head1!=NULL)
    {
        cnt1++;
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        cnt2++;
        head2=head2->next;
    }
    int cnt=max(cnt1,cnt2)-min(cnt1,cnt2);
    if(cnt1>cnt2)
    {
        while(cnt--)
        {
            head1=head1->next;
        }
        while(head1!=NULL)
        {
            head1=head1->next;
            head2=head2->next;
            if(head1==head2){
            cout<<head1->data<<endl;
            break;
            }
        }
    }
    else
    {
        while(cnt--)
        {
            head2=head2->next;
        }
        while(head2!=NULL)
        {
            head1=head1->next;
            head2=head2->next;
            if(head1==head2)
            {cout<<head1->data<<endl;
            break;}
        }
    }
}
void middle_of_list(node*head)
{
    node*fast=head;
    node*slow=head;                                 //que no 24                                                   //Total time complexity = O(n).
                                                       // Space Complexity = O(1).                            
                                                       //finding middle point of two linked list
    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}
void display_from_end(node*head)                        //que 28
{                                                       //printing list from end of linked list
    if(head==NULL)
    return;
    display_from_end(head->next);
    cout<<head->data<<" ";
}
void odd_or_even(node*head)
{
    int cnt=0;                                //que 29
                                              //naive approach to find list is even or odd
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
   
    if(cnt%2==0)
    cout<<"Even number of nodes"<<endl;
    else
    cout<<"Odd number of nodes"<<endl;
}
bool even_or_odd(node*head)
{
    node*ptr=head;
    while(ptr!=NULL&&ptr->next!=NULL)                      //same que with pointer
    {
        ptr=ptr->next->next;
        if(ptr==NULL)
        {
            return 0;
        }
    }
        return 1;
        
}
node*merge_sorted_list(node*head1,node*head2)                    //to merge two sorted linked list in sorted order
{                                                                //using dummy node we can achieve this
 node*dummy=new node();
 dummy->next=NULL;
 node*temp;
 temp=dummy;
 while(head1!=NULL&&head2!=NULL)
 {
     if(head1->data<=head2->data)
     {
         temp->next=head1;
         head1=head1->next;
         temp=temp->next;
     }
     else
     {
         temp->next=head2;
         head2=head2->next;
         temp=temp->next;
     }
}
if(head1!=NULL)
{
    temp->next=head1;
}
else
{
    temp->next=head2;
}
temp=dummy->next;
//delete dummy;
return temp;
}
void reverse_in_2_group(node*head)                                //que 32
{                                                                 //reverse in pair ITERATIVELY
    node*temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
}
void reverse_pair(node*head)
{
    if(head!=NULL&&head->next!=NULL)                          //same with RECURSION
    {
        swap(head->data,head->next->data);
        cout<<head->next->data<<" "<<head->data<<" ";
        reverse_pair(head->next->next); 
    }
}
void make_2_circular_list(node*head)
{
    node*head2=head;
    node*temp1=head;
    node*temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    if(cnt%2!=0)
    cnt=cnt/2+1;
    while(cnt--)
    head2=head2->next;
    while(head->next!=head)
    head=head->next;
    head->next=head2;
    head2->next=temp1;
}
bool is_palindrome(node*head)
{
    node*temp=head;
    stack<int>st;                                //que 37
     while(temp!=NULL)                           //linked is PALINDROME or not
    {                                            //Time complexity:O(n)
        st.push(temp->data);                     //space complexity:(O(n)
        temp=temp->next;
    }
    while(head!=NULL)
    {
        int top=st.top();
        st.pop();
        if(head->data!=top)
        return 0;
        head=head->next;
    }
    return 1;
}
node*reverse_k_nodes(node*head,int k)                             //que no 38
{                                                                 // reversing k nodes of linked list
                               
                                                               //space complexity:(O(1)
    if(head==NULL&&head->next==NULL)                               //Time complexity:O(n)
    return head;
    int cnt=k;
    node*prev=NULL;
    node*curr=head;
    node*next=NULL;
    while(curr!=NULL&&cnt--)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    cnt=k;
    if(next!=NULL)
    {
        head->next=reverse_k_nodes(next,cnt);
    }
    return prev;
}
                             // ACCESS TIME FOR LINKED LIST CAN BE O(1) IF WE
                            // STORE ALL THE ELEMNTS IN HASHTABLE AND THEN WE CAN ACCESS ELEMENTS IN O(1).

void delete_random_node(node*Node)                             //  que no 43
{                                                              //delete random node in liked list without previuos pointer
   node*temp=Node->next;                                         //time complexity:O(1)
   swap(Node->data,Node->next->data);                            //space complexity :O(1)
   Node->next=Node->next->next;
   delete temp;
}
void modular_node(node*head,int k)               //Find modular node
{                        
                                                //que no 46 O(n).O(1)
    node*temp=head;
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    int ans=(n/k)*k-1;
    while(ans--)
    head=head->next;
    cout<<head->data<<endl;
}
void modular_node_from_end(node*head,int k)           //que no 47
{                                                     //find modular node from end
    node*temp=head;                                  //same as finding kth node from end
    int n=0;                                           //O(n) O(1)
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    int ans=(n-k);
    while(ans--)
    head=head->next;
    cout<<head->data<<endl;
}
void fractional_node(node*head,int k)           //que no 48
{                                               //find fractional node i.e (n/k)th node
    node*temp=head;                             //O(n) O(1)
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    int ans=n/k;
    for(int i=1;i<ans;i++)
    {
        head=head->next;
    }
    cout<<head->data<<endl;
}
void root_nth_node(node*head)                    //que no 49
{                                                 //to find sqrt(n)th node from linked list
    node*temp=head;                              //O(n) O(1) 
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    int ans=(int)sqrt(n);
    for(int i=1;i<ans;i++)
    {
        head=head->next;
    }
    cout<<head->data<<endl;
}
void median_in_linkedlist(node*head)                         //que no 51
{                                                          //find median of the linked list
    node*temp=head;
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    bool ans=0;
    if(n%2==0)
    ans=1;
    else
    ans=0;
    for(int i=1;i<n/2;i++)
    {
        head=head->next;
    }
    if(ans==0)
    cout<<head->data<<endl;
    else
    cout<<(head->data+head->next->data)/2<<endl;     
}
node*new_node(node*head1,node*head2)
{
    node*newnode=new node();
    node*temp=newnode;
    newnode->next=NULL;     
    while(head1!=NULL)                             //Assuming both linked lists are of same lenght
    {
        newnode->data=head1->data+head2->data;
        newnode=newnode->next;
        head1=head1->next;
        head2=head2->next;
    }             
    return newnode;    
}
void reorder(node*head)                    //que no 55
{                                         //  List1 = {A1, A2'....An–1; An) => {A1,An,A2,An–1}
    node*slow=head;
    node*fast=head;                          /*HERE I USED EXTRA SPACE FOR REORDER i.e STACK */
    while(fast!=NULL&&fast->next!=NULL)         //O(n) O(1)
    {
        slow=slow->next;                         /******WITH EXTRA SPACE*******/
        fast=fast->next->next;
    }
    stack<int>st;
    while(slow!=NULL)
    {
        st.push(slow->data);
        slow=slow->next;
    }
    while(!st.empty()&&head!=NULL)
    {                                            //OUTPUT :1 20 2 19 3 18 4 17 5 16 6 15 7 14 8 13 9 12 10 11 
        int k=st.top();
        cout<<head->data<<" ";
        st.pop();
        cout<<k<<" ";
        head=head->next;
    }
}
node*reorder_2(node*head)
{
    node*slow=head;
    node*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {                                                      //same question 
                                                        /********WITHOUT EXTRA SPACE***********/
        slow=slow->next;
        fast=fast->next->next;
    }
    node*prev=NULL;
    node*curr=slow;
    node*next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;                                 //OUTPUT:1 20 2 19 3 18 4 17 5 16 6 15 7 14 8 13 9 12 10 11 
        prev=curr;
        curr=next;
    }

    while(head!=NULL&&prev!=NULL)
    {
        cout<<head->data<<" "<<prev->data<<" ";
        head=head->next;
        prev=prev->next;
    }
    return head; 
}
int main()
{
    node*head=NULL; 
   
    //  insert_at_head(&head,20);                                                  //initialiasing linked list
    insert_at_head(&head,1);
    insert_at_head(&head,2);
    insert_at_head(&head,3);
    insert_at_head(&head,4);
    insert_at_head(&head,5);
    insert_at_head(&head,6);
    insert_at_head(&head,7);
    insert_at_head(&head,8);
    insert_at_head(&head,9);
    // insert_at_head(&head,10);
    insert_at_head(&head,9);
    insert_at_head(&head,8);
    insert_at_head(&head,7);
    insert_at_head(&head,6);
    insert_at_head(&head,5);
    insert_at_head(&head,4);
    insert_at_head(&head,3);
    insert_at_head(&head,2);
    insert_at_head(&head,1);
    

     display(head);
    // cout<<count_node(head)<<endl;
    // insert_at_tail(&head,8);
    // insert_at_tail(&head,9);
    // insert_at_tail(&head,10);
    // insert_at_tail(&head,11);
    // display(head);
    // insert_after_node(head->next->next->next->next,20);
    // display(head);
    // cout<<count_node(head)<<endl;
    // cout<<nth_node_from_end(head,12)<<endl;
    // cout<<nth_node(head,3)<<endl;
    // cyclic_or_not(head);
     
    // deletenode(&head,4);
    // display(head);
    // cout<<count_node(head)<<endl;
    // deletenode(&head,20);
    // display(head);
     //make_cycle(head,head->next->next);
    //cout<<count_node(head)<<endl;
    //cyclic_or_not(head);
    //cout<<cyclics_or_not(head)<<endl;
    //lenght_of_loop(head);
    //display(head);
    //insert_in_sorted_list(&head,head->next->next->next);
    // node*newhead=reverse_list(head);
    // display(newhead);
    //middle_of_list(head);
   // display_from_end(head);
    // odd_or_even(head);
    // if(even_or_odd(head))
    // cout<<"Odd linked list"<<endl;
    // cout<<"Even linked list"<<endl;                /*************INSERTION SORT 
    // node*newhead=merge_sorted_list(head,head);                IS MOST APPROPRIATE 
    // display(newhead);                                         FOR LINKED LIST**************/
    // reverse_in_k_group(head,2);
    // reverse_in_2_group(head);
    // display(head);
    // reverse_pair(head);
    //  make_2_circular_list(head) ;
    //  display(head);  
    // cout<<is_palindrome(head)<<endl;
    // int k;
    // cin>>k;
    // node*newnode=reverse_k_nodes(head,4);
    // display(newnode);
    // delete_random_node(head->next->next->next->next->next);
    // display(head);
    // modular_node(head,3);
    // modular_node_from_end(head,3);
    //  fractional_node(head,3);
    //   root_nth_node(head);
    // median_in_linkedlist(head);
//    node*newhead= new_node(head1,head2);
//     display(newhead);
    //    reorder(head);
    // reorder_2(head);
//     common_element(head1,head2);
       cout<<endl;
       pali(head);
       return 0;
 }
 