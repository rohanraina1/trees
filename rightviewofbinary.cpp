#include<bits//stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int value)
    {
        data=value;
        left = NULL;
        right = NULL;
    }
};
int  rightview(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    while(!q.empty())
    {
        node* Node = q.front();
        q.pop();
        if(Node!=NULL)
        {
            cout<<Node->data<<" ";
            sum+=Node->data;
            if(Node->right)
            {
                q.push(Node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
    return sum;

}
int main()
{
    node* root =  new node(1);
    root->left= new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    cout<<rightview(root);
    return 0;
}