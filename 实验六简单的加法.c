#include<stdio.h>
#define N 20
#define M 10
int main()
{
	char num1[N+M+1]={0};
	char num2[N+M+1]={0};
	char num3[N+M+2]={0};
	int i = N+M;
	char temp;
	printf("请输入一个整数部分有二十位，小数部分有十位的整数\n");
	printf("不遵守规则导致的崩溃后果自负！\n"); 
	printf("00000000000000000000.0000000000\n");
	while(i>=0)
	{
		num1[i] = getchar();
		i--;
	}
	getchar();
	i = N+M;
	while(i>=0)
	{
		num2[i] = getchar();
		i--;
	}
	getchar(); 
	i = 0;
	while(i<M+N+1)
	{
		if(num1[i]!='.')
		{
			temp = num1[i] + num2[i] + num3[i];
			if(temp>=106)
			{
				num3[i] =temp - 58;
				if(num1[i+1]=='.'&&temp)
				{
					num3[i+2]++;
				}
				else
				{
					num3[i+1]++;
				}
			}
			else
			{
				num3[i] = temp - 48;
			}

		}
		else
		{
			num3[i] = '.';
			
		}
		i++;
		if(num3[N+M+1]==1)
			num3[N+M+1]+=48;
	}
	i = M+N+1;
	while(i>=0)
	{
		printf("%c",num3[i]);
		i--;
	}
}
