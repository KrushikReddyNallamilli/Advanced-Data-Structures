#include<stdio.h>
int top=-1,a[20][20],visit[20],stack[20];
void push(int ele)
{
	if(top==19)
		printf("Overflow");
	else
		stack[++top]=ele;
}
int pop()
{
	int key;
	if(top==-1)
		return(0);
	else
	{
		key=stack[top--];
		return(key);
	}
}
main()
{
	int i,j,n,s,k;
   	printf("Enter the no of vertices: ");
	scanf("%d",&n);
    for(i=1;i<=n;i++)
   {
        for(j=1;j<=n;j++)
        {
            printf("Enter the(%d,%d): ",i,j);
            scanf("%d",&a[i][j]);
        }
    } 
    printf("The adjacency matrix is: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           printf("%d",a[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    visit[i]=0;
    printf("Enter the source vector: ");
    scanf("%d",&s);
    printf("the DFS of graph is:\n");
    push(s);
    visit[s]=1;
    k=pop();
    if(k!=0){
    	printf("%d->",k);
	}
    while(k!=0)
    {
    	for(i=1;i<=n;i++)
    	if((a[k][i]!=0)&&(visit[i]==0))
    	{
    		push(i);
    		visit[i]=1;
		}
		k=pop();
		if(k!=0)
		printf("%d->",k);
	}
	printf("\n");
}

