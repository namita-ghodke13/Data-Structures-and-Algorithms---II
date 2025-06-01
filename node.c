#include<stdio.h>
#include"btree.h"
int main()
{
  int ans,ans1;
  Node *root=NULL;
  root=create(root);
  ans=countnode(root);
  printf("\nTotal Nodes = %d",ans);
  ans1=leafnode(root);
  printf("\nTotal Leaf Nodes = %d",ans1);      
}
