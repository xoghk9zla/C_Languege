#include <stdio.h>
 
void copy(int *src, int *dst, int len);
 
int main(void)
{
	int src[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int dst[3][4];
	int i,j;

	copy(*src, *dst, 12);
 
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d", src[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
 
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d", dst[i][j]);
		}
		printf("\n");
	}
	return 0;
 
}
void copy(int *src, int *dst, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		*(dst+i)=*(src+i);
	}
}