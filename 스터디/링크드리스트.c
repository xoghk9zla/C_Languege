//2014182011 ����ȭ
//2014.06.06(��)
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>//

struct character//�ɸ��� ����ü ����
{
	char name[20];//�ɸ����� �̸�
	int atk;//���ݷ�, ����, ü��, �̵��ӵ�
	int def;
	int hp;
	int speed;
	int search;
};

typedef struct character CYPHERS;//����ü character�� Cyphers�� ����

CYPHERS cyphers[20]={{"�ù� ��", 416, 43.32, 4432, 513},{"�̱�", 446, 45.35, 4770, 461},{"����", 435, 56.91, 4850, 459}};

typedef struct Arrcharcter//���ó��
{
	char Name[20];//�����͸� ���� �ڷ���
	int Atk;//�����͸� ���� �ڷ���
	int Def;
	int Hp;
	int Speed;
	struct arrcharcter * next;//���� ��带 ����Ű�� ���� ������
}ArrCyphers;

ArrCyphers * init(char * name,int atk, int def, int hp, int speed, ArrCyphers * pArrCyphers)//���� ��ũ�帮��Ʈ ����
{
	if(pArrCyphers==NULL)
	{
		pArrCyphers=(ArrCyphers*)malloc(sizeof(ArrCyphers));//�޸𸮸� �̸������ʰ�, �ʿ��� ������ Ȯ����. �����޸� Ȯ�� | �����ͺ��� = (�����ͺ��� ��������*) malloc(�����ͺ��� ������ũ��*�ʿ��� ũ��)
		if(pArrCyphers==NULL)
		{
			exit(0);
		}
		pArrCyphers-> Atk = atk;//pArrCyphers-> A = a; A���� a�� �����͸� ����
		pArrCyphers->Def = def;
		pArrCyphers->Hp = hp;
		pArrCyphers->Speed = speed;
		strcpy(pArrCyphers->Name, name);
		pArrCyphers->next = NULL;
	}
	else
	{
		pArrCyphers->next = init(name, atk, def, hp, speed, pArrCyphers->next);//������ �� ��带 ����
	}

	return (pArrCyphers);
}

void printunit(char *pName, CYPHERS *pCyphers)
{
	int str;
	
	str=strcmp(pCyphers->name, pName);
	if(str==0)
	{
		system("cls");
		printf("�ɸ��� �̸� : %s \n", pCyphers->name);
		printf("�ɸ��� ���ݷ� : %d \n", pCyphers->atk);
		printf("�ɸ��� ���� : %.2f \n", pCyphers->def);
		printf("�ɸ��� ü�� : %d \n", pCyphers->hp);
		printf("�ɸ��� �̵��ӵ� : %d \n", pCyphers->speed);
	}
}

void insertunit(CYPHERS *pCyphers)
{
	char insName[20];
	int insAtk;
	int insDef;
	int insHp;
	int insSpeed;
	
	printf("�Է��� �ɸ��� �̸� : \n");
	scanf("%s", &insName);
	strcpy(pCyphers->name, insName);
	printf("�Է��� �ɸ����� ���ݷ� : \n");
	scanf("%d", &insAtk);
	pCyphers->atk = insAtk;
	printf("�Է��� �ɸ����� ���� : \n");
	scanf("%lf", &insDef);
	pCyphers->def = insDef;
	printf("�Է��� �ɸ����� ü�� : \n");
	scanf("%d", &insHp);
	pCyphers->hp = insHp;
	printf("�Է��� �ɸ����� �̵��ӵ� : \n");
	scanf("%d", &insSpeed);
	pCyphers->speed = insSpeed;
	pCyphers->search=1;
}

int deleteunit(char *pName, CYPHERS *pCyphers)
{
	int str;
	str=strcmp(pCyphers->name, pName);
	if(str==0)
	{
		pCyphers->search=0;
		return 1;		
	}
	return 0;
}

void printall(int total)
{
	int i;
	for(i=0; i<total; i++)
	{
		if(cyphers[i].search==1)
		{
			printf("�̸� : %s \n",cyphers[i].name);
			printf("���ݷ� : %d \n",cyphers[i].atk);
			printf("���� : %.2f \n",cyphers[i].def);
			printf("ü�� : %d \n",cyphers[i].hp);
			printf("�̵��ӵ� : %d \n",cyphers[i].speed);
		}
		else
			break;
	}
}
void main()
{
	int total=10;
	int i, input;//input �޴� ������ ���� ����
	char iname[20] = {NULL};
	int iatk;
	double idef;
	int ihp;
	int ispeed;
	int iStop=0;

	ArrCyphers * LinkCyphers;
	//head = init(cyphers[0].name, cyphers[0].atk, cyphers[0].def, cyphers[0].hp, cyphers[0].speed, LinkCyphers);
	for(i=0; cyphers[i].search!=1; i++)
	{
		LinkCyphers = init(cyphers[i].name, cyphers[i].atk, cyphers[i].def, cyphers[i].hp, cyphers[i].speed, LinkCyphers);
	}
	//��ũ�� ����Ʈ�� �迭 ������ �ʱ�ȭ
	while(1)
	{
		printf("-----------------------------------\n");
		printf(" 1) �˻� \n 2) �Է�\n 3) ����\n 4) print all\n 0) ����\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:

			printf("-----------------------------------\n");
			printf("�˻��Ͻ� ĳ���� �̸��� �Է��Ͻÿ� : ");
			scanf("%s",&iname);
			system("cls");
			for(i=0; cyphers[i].search!= NULL; i++)
			{
				if(cyphers[i].search == 1)
				{
					printunit(iname, &cyphers[i]);

				}
			}

			break;

		case 2:
			for(i=0; i<total; i++)
			{
				if(cyphers[i].search == 0)
				{
					insertunit(&cyphers[i]);
					break;
				}
			}

			break;

		case 3:
			printf("�����Ͻ� ĳ���� �̸��� �Է��Ͻÿ� :");
			scanf("%s",&iname);


			for(i=0; i<total; i++)
			{
				if(cyphers[i].search==1)
				{
					iStop=deleteunit(iname, &cyphers[i]);
					if(iStop=1)
						break;
				}
			}
			getch();
			system("cls");
			break;
		case 4:
			system("cls");
			printf("��� ĳ���� ������ ����մϴ�.\n");
			printall(total);

			break;
		case 0:
			printf("���α׷��� �����մϴ�.\n");
			return;
			break;
		}
	}
}

