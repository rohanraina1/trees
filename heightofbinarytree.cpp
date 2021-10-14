#include<bits/stdc++.h>
using namespace std;
struct node{
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
int calcheight(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh = calcheight(root->left);
    int rh= calcheight(root->right);
    return max(lh,rh)+1;
}
int calcdiameter(node* root)
{
    if(root==NULL)
    {
        int* height;
        return 0;
    }
    int leftheight= calcdiameter(root->left);
    int rightheight = calcdiameter(root->right);
    int currdiameter= leftheight+ rightheight+1;
    int leftdia= calcdiameter(root->left);
    int rightdia= calcdiameter(root->right);
    int diameter = max(currdiameter,max( leftdia, rightdia));
    return diameter;
}
int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left= new node(3);
    root->left->right= new node(4);
    root->right = new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    cout<<calcheight(root)<<" "<<endl;
    int height= 0;
    cout<<calcdiameter(root,&height)<<" "<<endl;
    return 0;

}