#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int cost[10][10],visited[10]={0},i,j,n,ne=1,min,mincost=0,u,v;
	printf("Enter the no of vertives");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("Enter edge (%d,%d) cost",i,j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){	
				cost[i][j]==999;
			}
		}
	}
	visited[1]=1;
	printf("Minimum spanning tree");
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++){
			for(j=1;j<=n;j++){
			if(cost[i][j]<min&&visited[i]!=0)
			{
				min=cost[i][j];
				u=i;
				v=j;
			}
			if(visited[u]==0||visited[v]==0){
				printf("edge %d(%d,%d)cost:%d\n",ne++,u,v,min);
				visited[u]=1;
				mincost+=min;
				visited[v]=1;
			}
			
		}
		
			cost[u][v]=cost[v][u]=999;
		}	
	}
	printf("\n the cost of minimum spanning tree :%d",mincost);
	getch();
	
}
