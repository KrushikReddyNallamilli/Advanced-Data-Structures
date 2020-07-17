#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int size=0,heap[11];

void percolatedown(int);
void display();
void insert()
{
	int hole,x;
	if(size>11) printf("Heap is full \n");
	else{
		hole=++size;
		printf("enter the element  to be inserted");
		scanf("%d",&x);
		for(;hole>1&&heap[hole/2]>x;hole/=2)
		heap[hole]=heap[hole/2];
		heap[hole]=x;
	}
}
void deletemin()
{
	int x=heap[1];
	if(size==0) printf("heap is empty \n");
	else
	{
		heap[1]=heap[size--];
		percolatedown(1);
		printf("min element %d is deleted successfully \n",x);
	}
}
void display()
{
	int i;
	if(size==0) printf("Heap is empty \n");
	else
	{
		printf("Binary heap\n");
		for(i=1;i<=size;i++)
		printf("%5d\n",heap[i]);
	}
}
void percolatedown(int hole)
{
	int left,right,temp,min,target;
	min=heap[hole];
	while(2*hole<=size)
	{
		left=2*hole;
		right=left+1;
		if(right<=size&&heap[right]<heap[left])
		target=right;
		else
		target=left;
		if(heap[target]<min)
		{
			temp=heap[hole];
			heap[hole]=heap[target];
			heap[target]=temp;
			hole=target;
		}
		else
		break;
	}
	heap[hole]=min;
}
int main()
{
	int op;
	while(1)
	{
		printf
		("\n1.Insert\t2.Deletemin\t3.Display\t4.exit\n");
		printf("Enter your choice:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:insert(); break;
			case 2:deletemin(); break;
			case 3:display(); break;
			case 4:exit(0);
			default:printf("\n choose a valid option");
		}
	}
}
