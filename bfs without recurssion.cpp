#include<stdio.h>
int front=-1,rear=-1,a[20][20],queue[20],visit[20];
void insert(int item);
int delete();
main(){
	int n,i,j,s,k;
	printf("Enter the number of vertices");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("enter edge (%d,%d):",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("The adjacency matrix is: \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<n;i++){
		visit[i]=0;
	}
	printf("Enter the source vertex:");
	scanf("%d",&s);
	printf("The Bfs of graph is:");
	insert(s);
	visit[s]=1;
	k=delete();
	if(k!=0){
		printf("%d",k);
	}
	while(k!=0){
		for(i=1;i<=n;i++)
		if(a[k][i]!=0 && visit[i]==0){
			insert(i);
			visit[i]=1;
		}
		k=delete();
		if(k!=0)
		printf("-> %d",k);
	}
	printf("\n");
}
void insert(int item){
	if(front==1)
		printf("Queue is full");
	else
		queue[++rear]=item;
}
int delete(){
	int k;
	if (front==rear){
		return 0;
	}
	else{
		k=queue[++front];
		return(k);
	}
}
