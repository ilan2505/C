#include "my_mat.h"
#include <stdbool.h>
#include <stdio.h>
#define N 10
int min(int x,int y)
{
	if (x<=y)
	{
		return x;
	}
	return y;
}
int fastest(int *mat)
{
	int c;
	int x[N][N];
	int x2[N][N];
		for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&c);
			x[i][j]=c;
			if(i!=j&&x[i][j]==0)
			{
				x[i][j]=1000000;
			}
		}
	}
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				x2[i][j]=min(x[i][j],x[i][k]+x[k][j]);		
			}

		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				x[i][j]=x2[i][j];
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(x[i][j]!=1000000)
			{
	 			*mat= x[i][j];
				mat++;
			}else
			{
				*mat=0;
				mat++;
			}
		}
	}
	
	return 0;
}

int f2(int *mat)
{
	int i;
	int j;
	scanf("%d",&i);
	scanf("%d",&j);
	if(*(mat+N*i+j)==0){
		printf("False\n");
	}else
	{
		printf("True\n");
	}
	return 0;

	
}
int f3(int *mat)
{
	int i;
	int j;
	scanf("%d",&i);
	scanf("%d",&j);
	int val=*(mat+N*i+j);
	if(val!=0)
	{
		printf("%d\n",val);
	}else
	{
		printf("-1\n");
	}
	return 0;
}
