#include<stdio.h>
#include<conio.h>
int tsize;
int hasht(int key)
{
	int i;
	i=key%tsize;
	return i;
}
//-----LINEAR PROBING------
int rehash1(int key)
{
	int i;
	i=(key+1)%tsize;
	return i;
}
//-----QUADRATIC PROBING-----
int rehashq(int key,int j)
{
	int i;
	i=(key+(j*j)%tsize);
	return i;
}
int main()
{
	int key,arr[20],hash[20],i,n,s,op,j,k;
	printf("Enter size of hash table:");
	scanf("%d",&tsize);
	printf("\n Enter number of elementes :");
	scanf("%d",&n);
	for(i=0;i<tsize;i++)
	hash[i]=-1;
	printf("Enter Elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	do
	{
		printf("\n\n1.Linear Probing\n2.Quadratic Probing\n3.Exit\nEnter your option :");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				for(i=0;i<tsize;i++)
				hash[i]=-1;
				for(k=0;k<n;k++)
				{
					key=arr[k];
					i=hasht(key);
					while(hash[i]!=-1)
					{
						i=rehash1(i);
					}
					hash[i]=key;
				}
				printf("\nThe elements in the array are :");
				for(i=0;i<tsize;i++)
				{
					printf("\n Element at position %d:%d",i,hash[i]);
				}
				break;
				case 2:
					for(i=0;i<tsize;i++);
					hash[i]=-1;
					for(k=0;k<n;k++)
					{
						j=1;
						key=arr[k];
						i=hasht(key);
						while(hash[i]!=-1)
						{
							i=rehashq(i,j);
							j++;
						}
						hash[i]=key;
					}
					printf("\nThe elements in the array are :");
					for(i=0;i<tsize;i++)
					{
						printf("\nElement at position %d:%d ",i,hash[i]);
					}
					break;
		}
	}while(op!=3);
	getch();
}
