#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;
NODE *head[10];
void createmat(int a[10][10],int n)
{
  int i,j;
  for(i=1;i<n;i++)
  {
    for(j=1;j<n;j++)
    {
      a[i][i]=0;
      if(i!=j)
      {
        printf("\nEnter Edge Between v%d and v%d (1/0) : ",i+1,j+1);
        scanf("%d",&a[i][j]);
      }
    }
  }
}
void dispmat(int a[10][10],int n)
{
  int i,j;
  printf("\nThe Adjacency Matrix is :\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    printf("%d",a[i][j]);
    printf("\n");
  }
}
void createlist(int a[10][10],int n)
{
  int i,j;
  struct node *temp,*newnode;
  for(i=0;i<n;i++)
  {
    head[i]=NULL;
    for(j=0;j<n;j++)
    {
      if(a[i][j]==1)
      {
        newnode=(NODE *)malloc(sizeof(NODE));
        newnode->data=j+1;
        newnode->next=NULL;
        if(head[i]==NULL)
           head[i]=temp=newnode;
        else
        {
          temp->next=newnode;
          temp=newnode;
        }
      }
    }
  }
}
void displist(int n)
{
  struct node *temp;
  int i;
  printf("\nThe Adjacency List is :\n");
  for(i=0;i<n;i++)
  {
    printf("\nv%d -->",i+1);
    temp=head[i];
    while(temp)
    {
      printf("\tv%d -->",temp->data);
      temp=temp->next;
    }
    printf("NULL");
  }
}
void main()
{
  int a[10][10],n;
  printf("\nEnter the number of vertices :");
  scanf("%d",&n);
  createmat(a,n);
  dispmat(a,n);
  createlist(a,n);
  displist(n);
}