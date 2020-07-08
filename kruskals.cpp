#include<iostream>
#include<conio.h>
int u,v,a,b,n,i,j,ne=1;
int min,mincost=0,cost[10][10],parent[10];
int find(int);
int uni(int,int);
int main()
{
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
	printf("\n");
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++){
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					u=i;
					v=j;
				}
			}
		}
		a=find(u);
		b=find(v);
		if(uni(a,b))
		{
			printf("\n edge %d(%d,%d)cost is %d",ne++,u,v,min);
				mincost+=min;
		}	
		cost[u][v]=cost[v][u]=999;
	}
	printf("\n Minimum cost=%d",mincost);
	getch();
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if (i!=j)
	{
		parent[j]=i;
		return i;
	}
	return 0;
}
	
		
	
	
