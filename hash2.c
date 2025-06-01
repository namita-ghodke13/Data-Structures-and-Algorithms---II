#include<stdio.h>
int ht[10];
void init()
{
 int i;
 for(i=0;i<10;i++)
 {
  ht[i]=-1;
 }
}  
int hash(int num,int i)
{
 return(num%10+i)%10;
}
void insert(int num)
{
 int i,index;
 for(i=0;i<10;i++)
 {
  index=hash(num,i);
  if(ht[index]==-1)
  {
   ht[index]=num;
   break;
  }
 }
}
void disp()
{
 int i;
 for(i=0;i<10;i++)
 {
  printf("%d\t",ht[i]);
 }
}
int search(int num)
{
 int i,index;
 for(i=0;i<10;i++)
 {
  index=hash(num,i);
  if(ht[index]==num)
  {
   return index;
  }
 }
 return -1;
}
void delete(int num)
{
 int index;
 index=search(num);
 if(ht[index]==-1)
  printf("\nNumber not Found");
 else
 {
  ht[index]=-1;
 }
 printf("\n%d Delete Successfully\n",num);
}
void main()
{
 int ch,num,index;
 init();
 do
 {
  printf("\nMENU");
  printf("\n1.Insert \n2.Display \n3.Search \n4.Delete");
  printf("\nEnter your Choice :");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter Number :");
          scanf("%d",&num);
          insert(num);
          break;
   case 2:disp();
          break;          
   case 3:printf("\nEnter no. to Search :");
          scanf("%d",&num);
          index=search(num);
          if(index==-1)
           printf("\nNumber not Found");
          else
           printf("\nNumber Found at Position = %d",index);
           break;
   case 4:printf("\nEnter Number :");
          scanf("%d",&num);
          delete(num);
          break;
   default:printf("\nInvalid Choice");
           break;
  }
 }while(ch<5);
}