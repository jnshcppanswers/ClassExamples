#include<stdio.h>

int A[100];

int main(int argc, char **argv)
{
	/*
	int n;
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d", &A[i]);
	}
	*/
	int n = argc-1;
	for(int i = 1 ; i <= n ; i++)
	{
		sscanf(argv[i], "%d", &A[i]);
	}
	for(int i = 1; i <= n ; i++)
	{
		for(int j = i ; j > 1 ; j--)
		{
			printf("%d %d\n", A[j-1], A[j]);
			if(A[j]<A[j-1])
			{
				int t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
			}
			else break;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		printf("%d ", A[i]);
	}
}
