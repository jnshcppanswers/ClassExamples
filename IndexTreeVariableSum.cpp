#include<stdio.h>

int tree[30001];

int N = 1;

int SUM(int l, int r);

void CHANGE(int i, int x);

int main (int argv, char **argc)
{
	int n, i, x, k;
	
	freopen("input.txt", "r", stdin);
	
	scanf("%d", &n);
	while(N<n) N *= 2;
	
	for(i=1;i<=n;i++)
	{
		scanf("%d", &x);
		CHANGE(i, x);
	}
	
	scanf("%d", &k);
	while(k--)
	{
		int p;
		scanf("%d", &p);
		if(p==0)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d\n", SUM(a, b));
		}
		else
		{
			scanf("%d %d", &i, &x);
			CHANGE(i,x);
		}
	}
	
	return 0;
	
}

int SUM(int l, int r)
{
	int sum = 0;
	l += N-1;
	r += N-1;
	
	while(l <= r)
	{
		if(l%2==1)
		{
			sum += tree[l];
			l++;
		}
		if(r%2==0)
		{
			sum += tree[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return sum;
}

void CHANGE(int i, int x)
{
	i += N-1;
	x -= tree[i];
	while(i>0)
	{
		tree[i] += x;
		i /= 2;
	}
	return;
}
