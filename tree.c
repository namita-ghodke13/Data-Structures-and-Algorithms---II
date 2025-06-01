#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node)) 
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *create(Node *root)
{
  Node *newnode,*temp,*parent;
  int i,n,num;
  printf("Enter Limit :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=memory;
    printf("Enter Value :");
    scanf("%d",&num);
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
      root=newnode;
      continue;
    }
    temp=root;
    while(temp!=NULL)
    {
      parent=temp;
      if(num<temp->data)
         temp=temp->left;
      else
         temp=temp->right;
    }
    if(num<parent->data)
      parent->left=newnode;
    else
      parent->right=newnode;
  }
  return root;
}
void preorder(Node *root)
{
  Node *temp=root;
  if(temp!=NULL)
  {
     printf("%d\t",temp->data);
     preorder(temp->left);
     preorder(temp->right);
  }
}
void inorder(Node *root)
{
  Node *temp=root;
  if(temp!=NULL)
  {
     inorder(temp->left);
     printf("%d\t",temp->data);
     inorder(temp->right);
  }
}
void postorder(Node *root)
{
  Node *temp=root;
  if(temp!=NULL)
  {
     postorder(temp->left);
     postorder(temp->right);
     printf("%d\t",temp->data);
  }
}
int main()
{
   Node *root=NULL;
   root=create(root);
   printf("\nPreorder :\t");
   preorder(root);
   printf("\nInorder :\t");
   inorder(root);
   printf("\nPostorder :\t",postorder(root));
}