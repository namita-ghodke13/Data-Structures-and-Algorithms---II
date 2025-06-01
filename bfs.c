//Breadth First Search(BFS)
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
struct queue
{
  int data[MAX];
  int front,rear;
};
struct queue q;
void init()
{
  q.front=-1;
  q.rear=-1;
}
int isempty()
{
  return (q.front==q.rear);
}
int isfull()
{
  return (q.rear==MAX-1);
}
void add(int v)
{
  q.data[++q.rear]=v;
}
int rm()
{
  return (q.data[++q.front]);
}
void bfs(int a[10][10],int n)
{
  init();
  int v[10]={0},i,j;
  i=1;
  add(i);
  v[i]=1;
  while(!isempty())
  {
    i=rm();
    printf("v%d\t",i);
    for(j=1;j<=n;j++)
    {
      if((a[i][j]==1)&&(v[j]==0))
      {
        add(j);
        v[j]=1;
      }
    }
  }
}
int main()
{
  int a[10][10],n,i,j;
  printf("\nEnter no of Vertices :");
  scanf("%d",&n);
  printf("Enter Matrix :\n");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
  }
  bfs(a,n);
}