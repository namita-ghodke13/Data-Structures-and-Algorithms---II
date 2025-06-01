#include<stdio.h>
int linearsearch(int a[50],int n,int key)
{
  int pos,i;
  printf("\nEnter Key Value :");
  scanf("%d",&key);
  for(i=0;i<n;i++)
  {
    if(a[i]==key)
      return i;
  }
  return -1;
}
int main()
{
  int n,i,a[50],key,pos;
  printf("Enter Limit :");
  scanf("%d",&n);
  printf("\nEnter n Numbers :");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("\nArray :");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  pos=linearsearch(a,n,key);
  if(pos==-1)
    printf("\nElement not Found");
  else
    printf("\nElement Found at Position %d",pos);
}