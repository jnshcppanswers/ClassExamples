#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<string>
//^^^ Some are redundant


int n, m, i, j;
int map[102][102];

void Maze(int x, int y, int z);

int main(int argc, char **argv)
{
	freopen(argv[1],"r",stdin);
	
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	
	Maze(1,1, 1);
	
	return 0;
}

void Maze(int x, int y, int z)
{
	map[x][y]--;
	printf("(%d, %d)\n", x, y);
	if(map[x-1][y]==1)
	{
		Maze(x-1, y, z+1);
	}
	if(map[x+1][y]==1)
	{
		Maze(x+1, y, z+1);
	}
	if(map[x][y-1]==1)
	{
		Maze(x, y-1, z+1);
	}
	if(map[x][y+1]==1)
	{
		Maze(x, y+1, z+1);
	}
}
