#include<stdio.h>
int cost[8][8]={
{0,999,999,999,999,999,999,999},
{30,0,999,999,999,999,999,999},
{100,80,0,999,999,999,999,999},
{999,999,120,0,999,999,999,999},
{999,999,999,150,0,25,999,999},
{999,999,999,100,999,0,90,140},
{999,999,999,999,999,999,0,100},
{170,999,999,999,999,999,999,0}
};
void dijkstra(int v,int n)
{
int i,j,u,w,count,min;
int dist[10],visited[10]={0};
visited[v]=1;
for(i=0;i<n;i++)
dist[i]=cost[v][i];
count=2;
while(count<n)
{
min=999;
for(i=0;i<n;i++)
if(visited[i]==0 && dist[i]<min)
{
min=dist[i];
u=i;
}
visited[u]=1;
for(w=0;w<n;w++)
if(dist[u]+cost[u][w]<dist[w])
dist[w]=dist[u]+cost[u][w];
count++;
}
printf("\n shortest distance from vertex %d are:\n",v);
for(i=0;i<n;i++)
printf("%d\t",dist[i]);
}
void main()
{
dijkstra(4,8);
}
