#include<stdio.h>
void recdfs(int a[10][10],int n,int i)
{
  int j;
  static int v[10]={0};
  v[i]=1;
  printf("v%d\t",v+1);
  for(j=0;j<n;j++)
  {
    if((a[i][j]==1)&&(v[j]==0))
    {
       recdfs(a,n,i);
    }
  }
}
int main()
{
  int a[10][10],n,i,j;
  printf("Enter no of Vertices :");
  scanf("%d",&n);
  printf("Enter Matrix :\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  recdfs(a,n,i);
}