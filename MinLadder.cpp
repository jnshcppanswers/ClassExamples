#include<stdio.h>
int A[100];

int main(int argc, char **argv)
{
	int counter=0;
	for(int i= 1; i <= argc-1 ; i ++)
	{
		sscanf(argv[i], "%d", &A[i]);
	}
	for(int i = argc-1; i>=1 ; i--)
	{
		for(int j = 1 ; j < i ; j++)
		{
			//printf("%d %d\n", A[j], A[j+1]);
			//for(int i = 1 ; i < argc ; i++) printf("%d ", A[i]);
			//printf("\n");
			if(A[j] > A[j+1])
			{
				counter++;
				int t = A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
	//for(int i = 1 ; i < argc ; i++) printf("%d ", A[i]);
	printf("\n%d", counter);
	return 0;
}
