#include<stdio.h>
int A[100];

int main(int argc, char **argv)
{
	for(int i= 1; i <= argc-1 ; i ++)
	{
		sscanf(argv[i], "%d", &A[i]);
	}
	for(int i = argc-1; i>=1 ; i--)
	{
		for(int j = 1 ; j < i ; j++)
		{
			if(A[j] > A[j+1])
			{
				int t = A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
	for(int i = 1 ; i < argc ; i++) printf("%d ", A[i]);
	return 0;
}
