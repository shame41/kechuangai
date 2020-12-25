#include <stdio.h>
void swap(int*k,int*s)
{
	int t;
	t = *k;
	*k = *s;
	*s = t;
}
void Bobsort(int*a,int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
			}
		}
	}
}
int main()
{
	int i;
	int a[] = {3,4,5,2,1,8,44,23,123,3};
	Bobsort(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
} 
