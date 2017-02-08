#include <stdio.h>
#include <string.h>
char s[50];
int stack[50];
int main()
{
	int opened=0;
	//closed = 0;
	int top=-1;
	scanf("%s", s);
	for(int i= 0; i < strlen(s); i++)
	{
		if(s[i]=='(')
		{
			opened++;
			stack[++top]=i;
			
		}
		else if(s[i]==')')
		{
			printf("", stack[top--], i);
			if(opened > 0)
			{
				opened--;
			}
		}
	}
	if(top != -1 || opened != 0)
	{
		printf("not match");
		return 0;
	}
	for(int i= 0; i < strlen(s); i++)
	{
		if(s[i]=='(')
		{
			stack[++top]=i;
		}
		else if(s[i]==')')
		{
			printf("%d %d\n", stack[top--], i);
		}
	}
	
}
