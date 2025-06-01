#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
typedef struct node
{
  int data;
  struct node *next;
}Node;
Node *list[10];
void createmat(int a[10][10],int n)
{
  int i,j;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      a[i][j]=0;
      if(i!=j)
      {
        printf("\nEnter Edge Between v%d and v%d (0/1) :",i,j);
        scanf("%d",&a[i][j]);
      }
    }
  }
}
void dispmat(int a[10][10],int n)
{
  int i,j;
  printf("\nAdjacency Matrix :\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
}
void createlist(int a[10][10],int n)
{
   int i,j;
   struct node *temp,*new;
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       if(a[i][j]==1)
       {
         new=memory;
         new->next=NULL;
         new->data=j;
         if(list[i]==NULL)
         {
           list[i]=temp=new;
         }
         else
         {
           temp->next=new;
           temp=new;
         }
       }
     }
   }
}
void displist(int n)
{
  struct node *temp;
  int i;
  printf("\nAdjacency List :\n");
  for(i=1;i<=n;i++)
  {
    printf("\nv%d -->",i);
    for(temp=list[i];temp!=NULL;temp=temp->next)
    {
      printf("v%d-->",temp->data);
    }
    printf("NULL\n");
  }
}
int main()
{
  int a[10][10],n;
  printf("Enter Limit :");
  scanf("%d",&n);
  createmat(a,n);
  dispmat(a,n);
  createlist(a,n);
  displist(n);
}