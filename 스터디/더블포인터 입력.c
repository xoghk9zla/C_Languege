#include <stdio.h>
 
int main(void)
{
	int a;//b�� �ʱ�ȭ�� ���� ����
	int * b=&a;//c�� �ʱ�ȭ�� ���Ѻ���
	int **c=&b;
 
	scanf("%d", c); //c�ǰ��� �Է¹���
	printf("%d \n", *c); //c�ǰ� ���
 
	return 0;
}