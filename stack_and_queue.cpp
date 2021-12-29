// #include<iostream>
// #include<stack>
// #include<string>
// #include<queue>
// using namespace std;
// class Stack                    //Array implementation of stack
// {
//     int top=-1;
//     int stack[100];
//     public:
// void push(int n)                       //PUSH operation
// {
//     if(top>=100)
//     {
//         cout<<"stack overflow"<<endl;
//     }
//     else
//     {
//         top++;
//         stack[top]=n;
//     }
// }
// void pop()                                //POP OPERATION
// {
//     if(top<-1)
//     cout<<"stack underflow"<<endl;
//     else
//     {
//         top--;
//     }
// }
// void display()              
// {               //DISPLAY STACK
//     if(top<-1||top>100)
//     cout<<"Not possible"<<endl;
//     else
//     {
//         for(int i=top;i>=0;i--)
//         {
//             cout<<stack[i]<<" ";
//         }
//     }
// }
// int Top()
// {                                               //RETURNS TOP OF STACK
//     return stack[top];
// }
// };

// Space Complexity (for n push operations)              O(n)
// Time Complexity of Push()                             O(1)
// Time Complexity of Pop()                              O(1)
// Time Complexity of Size()                             O(1) 
// Time Complexity of IsEmptyStack()                     O(1)
// Time Complexity of IsFullStackf)                      O(1)
// Time Complexity of DeleteStackQ                       O(1)

/****************************IN LINKED LIST IMPLEMENTATION OF STACK,WE SIMPLY MAINTAIN TOP POINTER AND 
 *                           INCREAMENT IT BY1 WHILE INSERTING NODE AND DECREAMENT IT WHILE DLELETING
 *                            AND PUSH OPERATION IS LIKE INSERT NODE BEFORE HEAD AND POP OPERATION IS LIKE 
 *                           DELETING NODE AT HEAD*/ 


/*WE HAVE STL named stack in #include<stack> header file so instead of implementing it always use STL*/

// bool balanced_parenthesis(string s)                  //QUE 1
// {
//     if(s.empty())
//     return 1;
//     stack<char>st;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]=='['||s[i]=='{'||s[i]=='(')
//         {
//             st.push(s[i]);
//             continue;
//         }
//         if(s[i]==']'||s[i]=='}'||s[i]==')')
//         {
//             if((s[i]==')'&&st.top()=='(')&&!st.empty())
//             {
//                 st.pop();
                
//             }
//             else
//             return 0;
            
//         }
//         if(!st.empty())
//         return 0;
//         return 1;

//     }
// }
// void reverse_sentence(string s)               //HOW TO REVERSE A STATEMENT
// {                                               //RANDOM QUESTION
//     stack<string>st;
//     for(int i=0;i<s.size();i++)
//     {
//         string word="";
//         while(s[i]!=' '&&i<s.size())
//         {
//             word+=s[i];
//             i++;
//         }
//         st.push(word);
//     }
//     while(!st.empty())
//     {
//          cout<<st.top()<<" ";
//          st.pop();
//     }
//     cout<<endl;
// }
// void reverse_stack(stack<int>st)                               //REVERSE STACK WITH EXTRA SPACE(using another stack)
// {                                                                //RANDOM QUESTION 
//     stack<int>st1;
//     while(!st.empty())
//     {
//         st1.push(st.top());
//         st.pop();
//     }
//     while(!st1.empty())
//     {
//         cout<<st1.top()<<" ";
//         st1.pop();
//     }
//     cout<<endl;
// }
// void minstack(stack<int>st)                      //MINIMUM ELEMENT OF STACK
// {                                                //QUE NO 5
//     stack<int>st1;
//     if(st1.empty())
//         {
//             st1.push(st.top());
//             st.pop();
//         }
//     while(!st.empty())
//     {
//        if(st.top()<st1.top())
//        {
//            st1.push(st.top());
//            st.pop();
//            continue;
//        }
//        st.pop();
//     }
//     cout<<st1.top()<<endl;
// }
// bool is_palindrome(string s)                               //QUE NO 8
// {                                                          //WE CAN ALSO DO THIS QUESTION BY POINTING
//                                                          //ONE POINTER AT START OF STRING AND ANOTHER AT END
//                                                         //AND WILL INCREAMENT STARTING POINTER BY 1 AND DECREaMENT LAST POINTER BY 1
//                                                         //ACCORDINGLY 
//     stack<char>st;
//     for(int i=s.size()/2;i<s.size();i++)
//     {
//         st.push(s[i]);
//     }
//     for(int i=0;i<s.size()/2;i++)
//     {
//         if(s[i]==st.top())
//         st.pop();
//         else
//         return 0;
//     }
//     return 1;
// }
// //stack<char>st;
// // char insert_at_bottom(char k)              //INSERT AT BOTTOM USED IN REVERSAL OF STACK
// // {
    
// //     string s;
// //     if(st.empty())
// //     st.push(k);
// //     else
// //     {
// //         char a=st.top();
// //         st.pop();
// //         insert_at_bottom(k);
// //         st.push(a);
// //     }
// // }
// // char reverse()                           //QUE NO 11
// // {                                       //REVERSAL OF STACK WITHOUT USING EXTRA SPACE
// //     if(!st.empty())
// //     {
// //         char b=st.top();
// //         st.pop();
// //         reverse();
// //         insert_at_bottom(b);
// //     }
// //}
// void remove_duplicates(string s)
// {
//     if(s.size()==0||s.size()==1)
//     {
//         cout<<"no duplicates"<<endl;
//         return;
//     }
//     int i=0,j=1;
//     for(;i<s.size();i++)
//     {
//         if(s[i]==s[j])
//         {
//             s[i]=' ';
//             s[j]=' ';
//             i+=1;
//             j+=2;
//             continue;
//         }
//         j++;
//     }
//     string s1="";
//    for(int i=0;i<s.size();i++)
//    {
//        if(s[i]!=' ')
//        s1[i]=s[i];
       
//    }
//     for(int i=0;i<s.size();i++)
// {
//     if(s[i]>'a'&&s[i]<'z')
//     cout<<s1[i]<<" ";
//     else
//        continue;
// }
// remove_duplicates(s1);
// }
// void reverse_queue(queue<int>q)              //Que 1(queue chapter)
//                                             //QUEUE traversal using stack
// {                                           //O(n)   O(n)
//     stack<int>st;
//     cout<<"Before reversing"<<endl;
// while(!q.empty())
// {
//     cout<<q.front()<<" ";
//     st.push(q.front());
//     q.pop();
// }
// cout<<endl;
// cout<<"After reversal"<<endl;
// while(!st.empty())
// {
//     cout<<st.top()<<" ";
//     st.pop();
// }
// cout<<endl;
// }
// void sliding_window(vector<int>arr,int k)
// {
//     vector<int>arr1;
//     for(int i=0;i<arr.size();i++)
//     {
//         int maximum=0;
//         for(int x=0;x<k;x++)
//         {
//             maximum=max(maximum,arr[x]);
//         }
//         arr1[i]=maximum;
//     }
//     for(int i=0;i<arr.size();i++)
//     cout<<arr1[i]<<" ";
//     cout<<endl;
//}
// bool successive_or_not(int arr,int n)
// {
//     if(n%2==0)
//     {
//         for(int i=0;i<n;i+=2)
//         {
//             if(abs(arr[i]-arr[i+1])==1)
//             continue;
//             else
//             return 0;
//         }
//         return 1;
//     }
//     else
//     {
//         for(int i=0;i<n-1;i+=2)
//         {
//             if(abs(arr[i]-arr[i+1])==1)
//             continue;
//             else
//             return 0;
//         }
//         return 1;
//     }
// }
// int main()
// {
    //Stack st;
    // st.push(1);
    // st.push(2);
    // //st.pop();
    // st.display();
    // cout<<st.Top();
//     string s="()())";
//     if(balanced_parenthesis(s))
//     cout<<"balanced parenthsis"<<endl;
//     else
//     cout<<"UNbalanced parenthsis"<<endl;
// string s;
// cout<<"enter string"<<endl;
// getline(cin,s);
// reverse_sentence(s);
//stack<int>st;
// int n;
// cout<<"enter value of n"<<endl;
// cin>>n;
// while(n--)
// {
//     st.push(n);
// }
// st.push('1');                  //FOR STACK REVERSAL WITHOUT USING EXTRA SPACE
// st.push('2');
// st.push('4');
// st.push('5');
// st.push('9');
    //cout<<"After revrsal";
    //reverse_stack(st);
    // minstack(st);
   // cout<< is_palindrome("abaabxbababa");
//    string s;
//    reverse();
//    while(!st.empty())
//    {
//        char p=st.top();
//        st.pop();
//        s+=p;
//    }
//    for(int i=0;i<s.size();i++)
//    cout<<s[i]<<" ";
//      return 0;
// remove_duplicates("mississippi");
// queue<int>q;
// q.push(1);
// q.push(2);
// q.push(3);
// q.push(4);
// reverse_queue(q);
// vector<int>v={1,3,-1,-3,5,3,6,7};
// sliding_window(v,3);
// int n;
// cin>>n;
// int arr[n];
// for(int i=0;i<n;i++)
// cin>>arr[i];
//    successive_or_not(arr,n);

//}







