#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>

int map[102][102], x[10001], y[10001], z[10001], path_x[10001], path_y[10001];

int main(int argv, char **argc)
{
	printf("BFS Maze Solver\n");
	printf("Copyright 2017 all rights reserved.\n");
	int n, m;
	int i, j, h, t, p, q, k=0;
	
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	
	for(j=1;j<=m/2-2;j++) printf(" ");
	printf("MAZE\n");
	for(j=1;j<=m;j++) printf("=");
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	for(j=1;j<=m;j++) printf("=");
	printf("\n");
	
	h = t = 1;
	x[1] = 1;
	y[1] = 1;
	map[1][1] = 0;
	
	while(h<=t)
	{
		p=x[h];
		q=y[h];
		
		if(p==n && q==m) break;

		if(map[p-1][q] == 1)
		{
			t++;
			x[t] = p-1;
			y[t] = q;
			z[t] = h;
			map[p-1][q] = 0;
		}
		if(map[p+1][q] == 1)
		{
			t++;
			x[t] = p+1;
			y[t] = q;
			z[t] = h;
			map[p+1][q] = 0;
		}
		if(map[p][q-1] == 1)
		{
			t++;
			x[t] = p;
			y[t] = q-1;
			z[t] = h;
			map[p][q-1] = 0;
		}
		if(map[p][q+1] == 1)
		{
			t++;
			x[t] = p;
			y[t] = q+1;
			z[t] = h;
			map[p][q-1] = 0;
		}
		h++;
	}
	
	while(h>=1)
	{
		k++;
		path_x[k] = x[h];
		path_y[k] = y[h];
		h = z[h];
	}
	
	for (i=k ; i >= 1 ; i--)
	{
		printf("(%d, %d) ", path_x[i], path_y[i]);
	}
	return 0;
}
