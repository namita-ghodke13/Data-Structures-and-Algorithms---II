//Depth First Search
#include<stdio.h>
#include<stdlib.h>
void dfs(int a[10][10],int n,int i)
{
  int j;
  static int v[10]={0};
  v[i]=1;
  printf("v%d\t",i);
  for(j=1;j<=n;j++)
  {
    if(a[i][j]==1 && v[j]==0)
    {
      dfs(a,n,j);
    }
  }
}
int main()
{
  int i,j,n,a[10][10];
  printf("Enter Limit :");
  scanf("%d",&n);
  printf("Enter Graph Matrix :");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  dfs(a,n,1);
}