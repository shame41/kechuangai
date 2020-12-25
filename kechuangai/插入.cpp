#include <stdio.h>
void Insertsort(int*a, int len)
{
	int i,j,temp;
    for(i= 1; i<len; i++)
	{
        if(a[i] < a[i-1])
		{
            j= i-1;
            temp = a[i];
            while(j>-1 &&temp< a[j])
			{
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = temp;
        }
    }
}

int main()
{
	int a[] = {99,23,4,2,66,44,23,75,43,12};
	Insertsort(a,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	
}
