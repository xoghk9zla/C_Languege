#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct Cyphers
{
	char name[20];
	int att;
	int arm;
	int HP;

	struct Cyphers *next; // ���� ��ü�� ����Ű�� ������

};
typedef struct Cyphers CYP; //����ü �̸� ������ �����ϱ�

CYP* add_data(CYP*); //�����͸� �߰��ϴ� �Լ�
void prt_all(CYP*); //������ ���� ����ϴ� �Լ�
void search_data(CYP*); //�˻� �Լ�
CYP* delete_data(CYP*); //���� �Լ�

void main()
{

	int key; //��� ���� ����, �Է� ���� ���� ��� ���

	CYP *head, *tail; //ó���� �� �ּҸ� �����ϴ� ������
	head=(CYP*)malloc(sizeof(CYP)); //�޸� ������ �����ϴ� �Լ�, ù��°�� ����ǹǷ� head�����Ϳ� �ּҰ� ����
	tail = head; //������ 1�� �̹Ƿ� ���۰� ���� ����
	head->next = NULL; //ù��° ��ü�� �������� �����Ͱ� �����Ƿ� �ΰ��� �ִ´�.


	//��ũ�� ����Ʈ�� �迭 ������ �ʱ�ȭ
	
	while(1)
	{
		printf("-----------------------------------------------\n");
		printf("1) �˻� \n2) �Է�\n3) ����\n4) print all\n0) ����\n");
		scanf("%d",&key);
		printf("-----------------------------------------------\n");


		switch(key)
		{
		case 1:
			search_data(head); //������ ã��, ���� ��ġ �����͸� �����Ѵ�.
			system("cls"); // ȭ�� Ŭ���� �Լ�
			break;
		case 2:
			tail = add_data(tail); //������ ����, ������ ��ġ �����͸� �����ϰ�, ������ ��ġ�� ��ȯ�Ѵ�.
			system("cls");
			break;
		case 3:
			head = delete_data(head); //������ ����, ���� ��ġ�� �����ϰ�, ������ġ�� ��ȯ�Ѵ�.
			system("cls");
			break;
		case 4:
			system("cls");
			printf("��� ĳ���� ������ ����մϴ�.\n");
			prt_all(head); //��� ������ ���, ������ġ ����
			getchar(); //ȭ�� ��� �Լ�, �ƹ�Ű�� ������ ���� ����
			system("cls");
			break;
		case 0:
			printf("���α׷��� �����մϴ�.\n");
			return;
			break;
		}
	}
}


CYP* add_data(CYP *pCYP)
{
	printf("�Է��� �ɸ��� �̸� : \n");
	fflush(stdin); //�ӽ÷� Ű���� �Է°��� �޾Ƴ� �������� ���۸� ����� �Լ�
	gets(pCYP->name); //���� ��ü�� �̸� �κп� ������ �Է�
	printf("�Է��� �ɸ����� ���ݷ� : \n");
	scanf("%d", &pCYP->att);
	printf("�Է��� �ɸ����� ���� : \n");
	scanf("%d", &pCYP->arm);
	printf("�Է��� �ɸ����� ü�� : \n");
	scanf("%d", &pCYP->HP);
	
	pCYP->next = (CYP*)malloc(sizeof(CYP)); //���� ��ü�� �����Ͱ� �����Ƿ� ���� ��ü�� ������ �����Ѵ�.
	pCYP=pCYP->next; //��ȯ�� ���������Ϳ� �� ��ü�� ���� ��ü �ּ� ����
	pCYP->next=NULL; //���� ��ü�� ���� ��ü ����Ű�� ��ġ�� �������� ����

	return pCYP;
}

void prt_all(CYP *pCYP)
{
	while(pCYP->next != NULL) //������ ��ü�� ���������� �ݺ�
	{
		printf("�̸� : %s\n",pCYP->name);
		printf("���ݷ� : %d\n",pCYP->att);
		printf("���� : %d\n",pCYP->arm);
		printf("ü�� : %d\n",pCYP->HP);
		printf("-----------------------------------------------\n");
		pCYP = pCYP->next; //������ü�� �̵�
	}
	getchar();
}

void search_data(CYP* pCYP)
{
	char iname[20]; //�ӽ� ���ڿ� �������

	printf("-----------------------------------\n");
	printf("�˻��Ͻ� ĳ���� �̸��� �Է��Ͻÿ� : ");
	fflush(stdin);
	gets(iname);
	system("cls");
	while(pCYP->next != NULL) 
	{
		if(0 == strcmp(pCYP->name, iname)) //���ڿ� �� �Լ�, ���� ������ 0�� ��ȯ�ȴ�.�ƴϸ� 1��ȯ
		{
			printf("�̸� : %s\n",pCYP->name);
			printf("���ݷ� : %d\n",pCYP->att);
			printf("���� : %d\n",pCYP->arm);
			printf("ü�� : %d\n",pCYP->HP);
			printf("-----------------------------------------------\n");
			break;
		}
		pCYP = pCYP->next; //������ü�� �̵�
	}
	getchar();
}

CYP* delete_data(CYP* pCYP)
{
	char iname[20]; //�ӽ� �̸� �������
	int count=1; //�� ��ġ�� �����ϴ� ī���� ����

	printf("�����Ͻ� ĳ���� �̸��� �Է��Ͻÿ� :");
	fflush(stdin);
	gets(iname);
	CYP *start=pCYP;
	CYP *tmp;

	while(pCYP->next != NULL)
	{
		if(0 == strcmp(pCYP->name, iname)) //ã�Ҵ� ���
		{
			if(count==1) //��ó�� ��ü��
			{
				start = pCYP->next; //���� �����͸� �ٲٰ�
				free(pCYP); //�޸� ����
				break;
			}
			else
			{
				tmp->next = pCYP->next; //�װ� �ƴϸ� ���� ��ü�� ���������Ϳ� ���� ��ü�� �ּҸ� ����
				free(pCYP); // ����ü �޸� ����
				break;
			}
		}
		count++; //ī���� ����
		tmp=pCYP; //�ӽð����� ���� ��ü �ּ� ����
		pCYP = pCYP->next; //������ü�� �Ѿ
	}
	getchar();

	return start;
}