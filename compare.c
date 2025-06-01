#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
typedef struct node
{
  int data;
  struct node *left,*right;
}Node;
Node *create1(Node *root1)
{
  int i,n,num;
  Node *newnode,*temp,*parent;
  printf("\nEnter Limit of Root 1 :");
  scanf("%d",&n);
  printf("\nEnter Values for Root 1 -");
  for(i=0;i<n;i++)
  {
    newnode=memory;
    printf("\nEnter Value :");
    scanf("%d",&num);
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root1==NULL)
    {
      root1=newnode;
      continue;
    }
    temp=root1;u
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
  return root1;
}
void preorder1(Node *root1)
{
  Node *temp=root1;
  if(temp!=NULL)
  {
    printf("%d\t",temp->data);
    preorder1(temp->left);
    preorder1(temp->right);
  }
}
Node *create2(Node *root2)
{
  int i,n,num;
  Node *newnode,*temp,*parent;
  printf("\nEnter Limit of Root 2 :");
  scanf("%d",&n);
  printf("\nEnter Values for Root 2 -");
  for(i=0;i<n;i++)
  {
    newnode=memory;
    printf("\nEnter Value :");
    scanf("%d",&num);
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root2==NULL)
    {
      root2=newnode;
      continue;
    }
    temp=root2;
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
  return root2;
}
void preorder2(Node *root2)
{
  Node *temp=root2;
  if(temp!=NULL)
  {
    printf("%d\t",temp->data);
    preorder2(temp->left);
    preorder2(temp->right);
  }
}
int compare(Node *root1,Node *root2)
{
  if(root1==NULL && root2==NULL)
     return 1;
  else 
  {
  	if(root1!=NULL && root2!=NULL)
  	{
  	  if(root1->data==root2->data)
	  {
	  	if(compare(root1->left,root2->left))
	  	   return compare(root1->right,root2->right);
	  }	
	}
  }
  return 0;
}
int main()
{
  int ans;
  Node *root1=NULL,*root2=NULL;
  root1=create1(root1);
  root2=create2(root2);
  printf("\nRoot 1 :");
  preorder1(root1);
  printf("\nRoot 2 :");
  preorder2(root2);
  ans=compare(root1,root2);
  if(ans==0)
    printf("\nNot Identical");
  else
    printf("\nIdentical");
}