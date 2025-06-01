#include<stdio.h>
#include<stdlib.h>
struct queue
{
  int data;
  struct queue *next;
}*front,*rear;
void insertQ(int n)
{
  struct queue *temp;
  temp=(struct queue *)malloc(sizeof(struct queue));
  temp->data=n;
  temp->next=NULL;
  if(front==NULL)
    rear=front=temp;
  else
  {
    rear->next=temp;
    rear=temp;
  }
}
int deleteQ()
{
  int x;
  struct queue *temp=front;
  x=front->data;
  if(front==rear)
    front=rear=NULL;
  else
    front=front->next;

  free(temp);
  return(x);
}
void display()
{
  struct queue *temp=front;
  printf("\nQueue Contens are : \t");
  while(temp)
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  }
}
int main()
{
  int ch,x;
  do
  {
    printf("\n1-Insert \n2-Delete\n");
    printf("Enter Your Choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter Element to Insert :");
             scanf("%d",&x);
             insertQ(x);
             display();
             break;
      case 2:if(front==NULL)
                 printf("\nQueue is Empty");
             else
             {
               printf("\nDeleted Element : %d\n",deleteQ());
               display();
             }
             break;
      default:printf("\nInvalid Choice");
              break;
    }
  } while (ch>0 && ch<3); 
}