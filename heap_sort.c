#include<stdio.h>
#include<stdlib.h>
void accept(int a[],int n)
{
   for(int i=0;i<n;i++)
   {
     printf("\nEnter Value :");
     scanf("%d",&a[i]);
   }
}
void display(int a[],int n)
{
  for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
}
void heapify(int a[],int top,int last)
{
  int large=a[top];
  int j=(2*top)+1;
  if(j<=last && a[j]<a[j+1])
    j=j+1;
  if(j<=last && large<a[j])
  {
    int temp=a[top];
    a[top]=a[j];
    a[j]=temp;
    heapify(a,j,last);
  }
}
void buildheap(int a[],int n)
{
   for(int i=(n/2)-1;i>=0;i--)
   {
     heapify(a,i,n-1);
   }
}
void heapsort(int a[],int n)
{
   int last;
   int top=0;
   buildheap(a,n);
   printf("\nInitial Heap :\t");
   display(a,n);
   for(last=n-1;last>1;last--)
   {
     int temp=a[top];
     a[top]=a[last];
     a[last]=temp;
     printf("\nIteration %d :\t",n-last);
     display(a,n);
     heapify(a,top,last-1);
   }
}
void main()
{
   int n,a[20];
   printf("\nEnter Limit :");
   scanf("%d",&n);
   accept(a,n);
   heapsort(a,n);
}