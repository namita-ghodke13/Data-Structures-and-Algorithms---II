#include<stdio.h>
void display(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
void Heapify(int A[],int top,int last)
{
  int j,temp,key;
  key=A[top];
  j=2*top+1;
  if((j<last)&&(A[j]<A[j+1]))
     j=j+1;
  if((j<=last)&&(key<A[j]))
  {
    temp=A[top];
    A[top]=A[j];
    A[j]=temp;
    Heapify(A,j,last);
  }
}
void BuildHeap(int A[],int n)
{
  int i;
  for(i=n/2-1;i>=0;i--)
    Heapify(A,i,n-1);
}
void HeapSort(int A[],int n)
{
  int i,temp,top=0,last;
  BuildHeap(A,n);
  printf("\nInitial Heap : ");
  display(A,n);
  for(last=n-1;last>=1;last--)
  {
    temp=A[top];
    A[top]=A[last];
    A[last]=temp;
    printf("\nAfter Iteration %d : ",n-last);
    display(A,n);
    Heapify(A,top,last-1);
  }
}
int main()
{
  int A[10],n,i;
  printf("Enter Limit :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nEnter Value :");
    scanf("%d",&A[i]);
  }
  HeapSort(A,n);
  printf("\nThe Sorted Elements are : ");
  display(A,n);
}