#include <stdio.h>
#include <math.h>

typedef struct point
{
	double xPos;
	double yPos;
	double dx, dy;
}pos;

int main(void)
{
	pos p1;
	pos p2;
	pos Result;
	double result;
	int i;

	printf("x1 y1�� ��ǥ���� �Է��ϼ���",i,i);
		scanf("%lf %lf", &p1.xPos, &p1.yPos);
	printf("x2 y2�� ��ǥ���� �Է��ϼ���",i,i);
		scanf("%lf %lf", &p2.xPos, &p2.yPos);

	Result.dx=p2.xPos-p1.xPos;
	Result.dy=p2.yPos-p1.yPos;
	result=sqrt(Result.dx*Result.dx+Result.dy*Result.dy);

	printf("(x1, y1) �� (x2, y2)������ ���̴� %.2lf�Դϴ�. \n", result);
	return 0;
}