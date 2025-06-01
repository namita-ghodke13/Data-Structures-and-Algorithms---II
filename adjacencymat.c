#include<stdio.h>
int main()
{
  int n,a[10][10],i,j;
  printf("Enter Limit :");
  scanf("%d",&n);
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
  printf("\nAdjacency Matrix :\n");
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
        printf("\t%d",a[i][j]);
     }
     printf("\n");
  }
  printf("\nVertex  SumInd  SumOut  Total\n");
  for(i=1;i<=n;i++)
  {
    int sumind=0,sumout=0;
    for(j=1;j<=n;j++)
    {
      sumout=sumout+a[i][j];
      sumind=sumind+a[j][i];
    }
    printf("\nV%d\t %d\t %d\t %d\t",i,sumind,sumout,sumind+sumout);
  }
}