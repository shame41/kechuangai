#include <stdio.h>
void Quicksort(int*a,int begin,int end)
{
    int i = begin, j = end;
    int temp;
    if(i < j)
	{
        temp = a[i];
        while (i != j)
        {
            while(j > i && a[j] > temp)
			-- j;
	            a[i] = a[j];
            while(i < j && a[i] < temp)
			++ i;
	        	a[j] = a[i];	
        }
        a[i] = temp;
        Quicksort(a, begin, i - 1);
        Quicksort(a, i + 1, end);
    }
}
int main()
{
	int a[] = {6,3,2,8,7,5,0,9,1};
	Quicksort(a,0,9);
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
}
