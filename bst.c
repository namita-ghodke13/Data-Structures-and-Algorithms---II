#include<stdio.h>
#include"btree.h"
int main()
{
  int ch,ans;
  Node *root=NULL;
  do
  {
    printf("\n1-Create \n2-Preorder \n3-Inorder \n4-Postorder \n5-Insert \n6-Search");
    printf("\nEnter Your Choice :");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:root=create(root);
             break;
      case 2:preorder(root);
             break;
      case 3:inorder(root);
             break;
      case 4:postorder(root);
             break;
      case 5:root=insert(root);
             break;
      case 6:ans=search(root);
             if(ans==-1)
                printf("\nNumber not Found");
             else 
                printf("\nNumber Found ");
             break;
      default:printf("Invalid Choice...");
              break;
    }
  } while (ch<7);
}