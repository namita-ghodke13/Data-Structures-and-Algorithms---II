#include<stdio.h>
int hf(int key, int i)
{
return (key%10 + i)%10;
}
void insert(int ht[10], int key)
{
int i, index;
for(i=0; i<10; i++)
{
index = hf(key,i);
if(ht[index] == -1)
{
ht[index] = key;
return;
}
}
printf("\ncould not insert key %d\n",key);
}
int search(int ht[10], int key)
{
int i, index;
for(i=0; i<10; i++)
{
index = hf(key,i);
if(ht[index] == key)
return index;
}
return -1;
}
void delkey(int ht[10], int key)
{
int index;
index = search(ht,key);
if(index == -1)
printf("\nkey %d not found\n",key);
else
ht[index] = -1;
}
void showtable(int ht[10])
{
int i;
for(i=0; i<10; i++)
printf("%d[%d]\n", i, ht[i]);
}
int main()
{
int ht[10], choice,i, key, index;
for(i=0; i<10; i++)
ht[i] = -1;
do
{
printf("\n1:Insert\n2:Search\n3:Delete\n4:exit");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: 
printf("\nEnter the key to be inserted :");
scanf("%d",&key);
insert(ht,key);
showtable(ht);
break;
case 2:
printf("\nEnter the key to be serched : ");
scanf("%d",&key);
index = search(ht,key);
if(index == -1)
printf("\nkey %d not found",key);
else
printf("\n%d found at position %d",key,index);
break;
case 3:
printf("\nEnter the key to be deleted :");
scanf("%d",&key);
delkey(ht,key);
showtable(ht);
}
}while(choice!=4);
return 0;
}