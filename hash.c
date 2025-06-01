#include<stdio.h>
#include<stdlib.h>
int ht[100],key;
int num,ch,s,i,n;
int hash(int key,int i,int n)
{
  int index;
  index=((key%n)+1)%10;
  printf("%d",index);
  return index;
}
int insert(int key,int n)
{
  int index;
  for(i=0;i<n;i++)
  {
    index=hash(key,i,n);
    if(ht[index]==-1)
    {
      ht[index]=key;
      break;
    }
  }
  return 0;
}
int search(int s,int n)
{
  int index;
  for(i=0;i<n;i++)
  {
    index=hash(key,i,n);
    if(ht[index]==s)
     return index;
  }
  return 0;
}
int delete(int key,int n)
{
  int index;
  index=search(s,n);
  if(ht[index])
    ht[index]=-1;
  else  
    return -1;
}
int main()
{
  int in;
  printf("\nEnter Limit :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    ht[i]=-1;
  }
  for(i=0;i<n;i++)
  {
    printf("\n%d[%d]\n",i,ht[i]);
  }
  do
  {
    printf("\n1-Insert \n2-Search \n3-Delete");
    printf("\nEnter Your Choice :");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter Number :");
             scanf("%d",&num);
             in=insert(num,n);
             for(i=0;i<n;i++)
             {
               printf("\n%d[%d]\n",i,ht[i]);
             }
             break;
      case 2:printf("\nEnter Number :");
             scanf("%d",&num);
             in=search(num,n);
             break;
      case 3:printf("\nEnter Number :");
             scanf("%d",&num);
             in=delete(num,n);
             break;
      default :printf("\nInvalid Choice");
    }
  }while(ch<4);
}