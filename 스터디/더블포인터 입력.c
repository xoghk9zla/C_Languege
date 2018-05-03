#include <stdio.h>
 
int main(void)
{
	int a;//b의 초기화를 위한 변수
	int * b=&a;//c의 초기화를 위한변수
	int **c=&b;
 
	scanf("%d", c); //c의값을 입력받음
	printf("%d \n", *c); //c의값 출력
 
	return 0;
}