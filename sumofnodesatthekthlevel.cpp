#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int value)
    {
        data= value;
        left= NULL;
        right= NULL;
    }

};
int sumatk(node* root , int k)
{
    if(root==NULL)
    {
        return -1 ;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int level = 0;
    while(!q.empty())
    {
        node* Node = q.front();
        q.pop();
        if(Node!=NULL)
        { 
            if(level==k)
            {
                sum= sum+ Node->data;
            }
            
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
            level++;
        }
    }
    return sum;

}
int main()
{
    struct node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left = new node(6);
    root->right->right= new node(7);
    cout<<sumatk(root,2);
    return 0;
}