#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right ;
    node(int val)
    {
        data= val;
        left = NULL;
        right= NULL;
    }
};
int search(int inorder[],int start, int end, int curr)
{
    for(int i=start ; i<=end; i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
node* buildtree(int preorder[],int inorder[],int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    static int  idx= 0;
    int curr = preorder[idx];
    idx++;
    node* Node = new node(curr);
    if(start==end)
    {
        return Node;
    }
    int pos = search(inorder,start,end,curr);
    Node->left= buildtree(inorder, preorder,start,pos-1);
    Node->right= buildtree(inorder,preorder,pos+1,end);
    return Node;
}
void inorderprint(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
int main()
{
    int preorder[]= {1,2,4,5,3,6,7};
    int inorder[]= {4,2,5,1,6,3,7};
    node* root = buildtree(preorder,inorder,0,6);
    inorderprint(root);



    return 0;
}
