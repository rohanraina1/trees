#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int value)
    {
        data = value;
        left= NULL;
        right = NULL;
    }
};
void print(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
 void printlevelorder(struct node* root)
 {
     if(root==NULL)
     {
         return;
     }
     queue<node*>q;
     q.push(root);
     q.push(NULL);
     while(!q.empty())
     {
         struct node* Node = q.front();
         q.pop();
         if(Node!=NULL)
         {
             cout<<Node->data<<" ";
             if(Node->left!=NULL)
             {
                 q.push(Node->left);
             }
             if(Node->right!=NULL)
             {
                 q.push(Node->right);
             }
         }
         else if(!q.empty())
         {
             q.push(NULL);
         }
     }
 }
int main()
{
    struct node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    print(root);
    cout<<endl;
    printlevelorder(root);
    return 0;

}
