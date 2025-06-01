#include<stdio.h>
#define MAX 20
void djks(int c[10][10], int n)
{ 
int i, j, v, w, u, count, min;
int dist[10];
int visited[10]={0};
printf("\nEnter the source vertex:");
scanf("%d", &v);
v=v-1;
for(i=0; i<n; i++)
dist[i] = c[v][i];
visited[v] = 1;
count = 1;
while(count < n)
{
min = 999;
for(i=0; i<n; i++)
if( (visited[i]==0) && (dist[i] < min)) 
{
min = dist[i];
u = i;
}
visited[u] = 1; 
for(w=0; w<n; w++)
{
if(!visited[w])
if(dist[u] + c[u][w] < dist[w])
dist[w] = dist[u] + c[u][w];
count++;
}
}
printf("\nThe shortest path are:\n");
for(i=0;i<n;i++)
printf("from v%d to v%d = %d\n",v+1,i+1,dist[i]);
}
int main()
{
int c[10][10]={0},n,i,j;
printf("\nHow many vertices:");
scanf("%d",&n);
printf("\nEnter the Adjacency cost matrix:\n");
for(i=0; i<n; i++)
for(j=0; j<n; j++)
{
if(i<j)
{
printf("\nEnter the cost of edge %d->%d :", i+1, j+1);
scanf("%d", &c[i][j]);
c[j][i]= c[i][j];
}
}
djks(c,n);
}