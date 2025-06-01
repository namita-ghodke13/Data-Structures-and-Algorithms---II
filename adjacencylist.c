#include<stdio.h>
#include<stdlib.h>
#define memory (struct node *)malloc(sizeof(struct node))
struct node
{
  int data;
  struct node *next;
};
struct node *list[10];
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
  int a[10][10],n,i,j;
  printf("Enter Limit :");
  scanf("%d",&n);
  printf("\nEnter the Vertices as an Matrix :\n");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
  }
  createlist(a,n);
  displist(n);
}