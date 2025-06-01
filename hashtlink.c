#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
int key;
struct node *next;
}NODE;
NODE *HT[10]={NULL};
int hf(int key)
{
return(key%10);
}
void insert(int k)
{
int index;
NODE * newnode = NULL, *temp;
newnode = (NODE *)malloc(sizeof(NODE));
newnode->key=k;
newnode->next=NULL;
index=hf(k);
if(HT[index]==NULL)
HT[index]=newnode;
else
{
temp=HT[index];
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
}
}
void search(int key)
{
int index;
NODE * temp;
index=hf(key);
for(temp=HT[index]; temp!=NULL; temp=temp->next)
if(temp->key==key)
{
printf("%d found\n",key);
return;
}
printf("%d not found\n", key);
}
void deletekey(int key)
{
int index;
NODE *temp;
index=hf(key);
temp=HT[index];
if( (temp!=NULL) && (temp->key==key))
HT[index]=temp->next;
else
{
for(temp=HT[index]; temp!=NULL; temp=temp->next)
if(temp->next->key==key)
{
temp->next=temp->next->next;
return;
}
printf("%d not found\n",key);
}
}
void showtable()
{
int i,index;
NODE *temp;
for(i=0;i<10;i++)
{
printf("| %d | ",i);
for(temp=HT[i]; temp!=NULL; temp=temp->next)
printf("%d -> ",temp->key);
printf("NULL\n");
}
}
int main()
{
int choice,i, key;
 for(i=0;i<10;i++)
do
{
printf("\n1:Insert\n2:Delete");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: 
printf("\nEnter the key to be inserted :");
scanf("%d",&key);
insert(key);
showtable();
break;
case 2:
printf("\nEnter the key to be deleted :");
scanf("%d",&key);
deletekey(key);
showtable();
break;
default:printf("Invalid Choice...");
        break;
}
}while(choice!=2);
return 0;
}
