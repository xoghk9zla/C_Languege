//2014182011����ȭ
//2014.5.29(��)
#include <stdio.h>
struct charcter{
	char name[10];//ĳ�����̸�
	double hp=0,speed=0;//ü��, �̵��ӵ�
	float atk=0,def=0;//���ݷ�, ����
};

void scan(struct charcter *pst, int n);//ĳ�����̸�,ü��, �̵��ӵ�, ���ݷ�,������ �Է¹ޱ� ���� �Լ�
void print(struct charcter *pst, int n);//����� ���� �Լ�

int main(void)
{
	struct charcter ch[5];//��ü����

	scan(ch,5); //�Լ��� ȣ��
	print(ch,5);

	return 0;
}

void scan(struct charcter *pst, int n)//ĳ�����̸�,ü��, �̵��ӵ�, ���ݷ�,������ �Է¹ޱ� ���� �Լ�
{
	int i;
	printf("�̸� : ü�� , �̵��ӵ� , ���� �� �Է��ϼ���. \n");
	for(i=0;i<n;i++)
	{
		scanf("%s %f %f %f %f", pst[i].name, &pst[i].hp, &pst[i].speed, &pst[i].atk, &pst[i].def);//��ü�ϳ��ϳ��� ĳ�����̸�,ü��, �̵��ӵ�, ������ �Է�
	}
	printf("\n");
}
void print(struct charcter *pst, int n)//����� ���� �Լ�
{
	int i;
	printf("�̸� : ü�� , �̵��ӵ� , ���� \n\n");
	for(i=0;i<n;i++)
	{
		printf("%s : %lf , %lf , %lf, %lf \n", pst[i].name, pst[i].hp, pst[i].speed, pst[i].atk, pst[i].def);//��ü�� �� ������ �ϳ��� ���
	}
}

