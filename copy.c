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
  int i,n,num;
  Node *newnode,*temp,*parent;
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
Node *copy(Node *root)
{
  Node *temp=root,*newnode;
  if(temp!=NULL)
  {
    newnode=memory;
    newnode->data=temp->data;
    newnode->left=copy(temp->left);
    newnode->right=copy(temp->right);

    return newnode;
  }
  return NULL;
}
int sum(Node *root)
{
  Node *temp=root;
  int s=0;
  if(temp!=NULL)
  {
     if(temp->data%2==0)
     {
       s=s+temp->data;
       sum(temp->left);
       sum(temp->right);
     }
  }
  return s;
}
int main()
{
  int a;
  Node *root=NULL,*root2;
  root=create(root);
  printf("\nTree :");
  preorder(root);
  root2=copy(root);
  printf("\nCopied Tree :");
  preorder(root2);
  a=sum(root);
  printf("Sum =%d",a);
}