#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct hash
{
	int k,v;
}a[10];
int insert(int key,int val)
{
	int h,i;
	h=key%10;
	if(a[h].k==-1)
	{
		a[h].k=key;
		a[h].v=val;
		return 1;
	}
	else
	{
		for(i=h+1;i<10;i++)
		if(a[i].k==-1)
		{
			a[i].k=key;
			a[i].v=val;
			return 1;
		}
		for(i=0;i<h;i++)
		if(a[i].k==-1)
		{
			a[i].k=key;
			a[i].v=val;
			return 1;
		}
	}
	return -1;
}
int Delete(int key)
{
	int  h,i;
	h=key%10;
	if(a[h].k==key)
	{
		a[h].k=-1;
		a[h].v=-1;
		return 1;
	}
	for(i=0;i=h;i++)
	if(a[i].k==key)
	{
		a[i].k=-1;
		a[i].v=-1;
		return 1;
	}
	return -1;
}
int search(int key)
{
	int h,i,b;
	h=key%10;
	if(a[h].k==key){
		return a[h].v;
	    for(i=h+1;i<10;i++)
        if(a[i].k==key)
        return a[i].v;
        for(i=0;i<h;i++)
        if(a[i].k==key)
        return a[i].v;
	    return -1;
	}
            
}
void display()
{
	int j=0;
    printf("Dictionary\n");
    printf("key | value\n");
    for(j=0;j<10;j++)
    if(a[j].k!=-1)
    printf("%3d|%5d\n",a[j].k,a[j].v);
    else
    printf("-1|-1\n");
}
int main()
{
	int j,key,val,opt,result;
	for(j=0;j<10;j++)
	{
		a[j].k=-1;
	}
	while(1)
	{
		printf("1.insert\n2.delete\n3.search\n4.display\n5.exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:printf("enter key and value\n");
			scanf("%d%d",&key,&val);
			result=insert(key,val);
			if(result==1)
			printf("insertion is succesfull\n");
			else
			printf("failed to insert\n");
			break;
			case 2:printf("enter key to be delete\n");
			scanf("%d",&key);
			result=Delete(key);
			if(result==1)
			printf("deletion completed\n");
			else
			printf("deletion failed\n");
			break;
			case 3:printf("enter key to be search\n");
			scanf("%d",&key);
			result=search(key);
			if(result==-1)
			printf("failed to search\n");
			else
			printf("the value in the entered key is %d\n",result);
			break;
			case 4:display();
			break;
			case 5:exit(0);
			default:printf("option invalid\n");
			break;
		}
	}
}
