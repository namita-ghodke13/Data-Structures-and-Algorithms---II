#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
#define MAX 20
typedef struct node 
{
  int data;
  struct node *left,*right;
}Node;
struct queue 
{
  Node *data1[MAX];
  int front,rear;
};
struct queue q;
void initq()
{
  q.front=q.rear=-1;
}
int isempty()
{
  return (q.front==q.rear);
}
int isfull()
{
  return (q.rear==MAX-1);
}
void add(Node *temp)
{
  q.data1[++q.rear]=temp;
}
Node *removeq()
{
  return q.data1[++q.front];
}
Node *create(Node *root)
{
  Node *newnode,*temp,*parent;
  int i,n,num;
  printf("Enter Limit :");
  scanf("%d",&n);
  printf("\nEnter the %d Elements -",n);
  for(i=1;i<=n;i++)
  {
    newnode=memory;
    printf("\nEnter Element :");
    scanf("%d",&num);
    newnode->data=num;
    newnode->left=newnode->right=NULL;
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
void levelorder(Node *root)
{
  int level=0;
  Node *temp,*M=NULL;
  initq();
  add(root);
  add(M);
  printf("\nLevel %d -->\t",level);
  while(!isempty())
  {
    temp=removeq();
    if(temp==M)
    {
      level++;
      if(!isempty())
      {
        add(M);
        printf("\nLevel %d -->\t",level);
      }
    }
    else
    {
      printf("%d\t",temp->data);
      if(temp->left)
         add(temp->left);
      if(temp->right)
         add(temp->right);
    }
  }
}
int main()
{
  Node *root=NULL;
  root=create(root);
  printf("\nLevel Order Traversal :\t");
  levelorder(root);
}