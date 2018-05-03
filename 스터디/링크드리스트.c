//2014182011 김태화
//2014.06.06(금)
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>//

struct character//케릭터 구조체 선언
{
	char name[20];//케릭터의 이름
	int atk;//공격력, 방어력, 체력, 이동속도
	int def;
	int hp;
	int speed;
	int search;
};

typedef struct character CYPHERS;//구조체 character을 Cyphers로 선언

CYPHERS cyphers[20]={{"시바 포", 416, 43.32, 4432, 513},{"이글", 446, 45.35, 4770, 461},{"휴톤", 435, 56.91, 4850, 459}};

typedef struct Arrcharcter//스택노드
{
	char Name[20];//데이터를 담을 자료형
	int Atk;//데이터를 담을 자료형
	int Def;
	int Hp;
	int Speed;
	struct arrcharcter * next;//다음 노드를 가리키기 위한 포인터
}ArrCyphers;

ArrCyphers * init(char * name,int atk, int def, int hp, int speed, ArrCyphers * pArrCyphers)//단일 링크드리스트 생성
{
	if(pArrCyphers==NULL)
	{
		pArrCyphers=(ArrCyphers*)malloc(sizeof(ArrCyphers));//메모리를 미리잡지않고, 필요할 때마다 확보함. 동적메모리 확보 | 포인터변수 = (포인터변수 데이터형*) malloc(포인터변수 데이터크기*필요한 크기)
		if(pArrCyphers==NULL)
		{
			exit(0);
		}
		pArrCyphers-> Atk = atk;//pArrCyphers-> A = a; A에다 a의 데이터를 저장
		pArrCyphers->Def = def;
		pArrCyphers->Hp = hp;
		pArrCyphers->Speed = speed;
		strcpy(pArrCyphers->Name, name);
		pArrCyphers->next = NULL;
	}
	else
	{
		pArrCyphers->next = init(name, atk, def, hp, speed, pArrCyphers->next);//꼬리에 새 노드를 연결
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
		printf("케릭터 이름 : %s \n", pCyphers->name);
		printf("케릭터 공격력 : %d \n", pCyphers->atk);
		printf("케릭터 방어력 : %.2f \n", pCyphers->def);
		printf("케릭터 체력 : %d \n", pCyphers->hp);
		printf("케릭터 이동속도 : %d \n", pCyphers->speed);
	}
}

void insertunit(CYPHERS *pCyphers)
{
	char insName[20];
	int insAtk;
	int insDef;
	int insHp;
	int insSpeed;
	
	printf("입력할 케릭터 이름 : \n");
	scanf("%s", &insName);
	strcpy(pCyphers->name, insName);
	printf("입력한 케릭터의 공격력 : \n");
	scanf("%d", &insAtk);
	pCyphers->atk = insAtk;
	printf("입력한 케릭터의 방어력 : \n");
	scanf("%lf", &insDef);
	pCyphers->def = insDef;
	printf("입력한 케릭터의 체력 : \n");
	scanf("%d", &insHp);
	pCyphers->hp = insHp;
	printf("입력한 케릭터의 이동속도 : \n");
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
			printf("이름 : %s \n",cyphers[i].name);
			printf("공격력 : %d \n",cyphers[i].atk);
			printf("방어력 : %.2f \n",cyphers[i].def);
			printf("체력 : %d \n",cyphers[i].hp);
			printf("이동속도 : %d \n",cyphers[i].speed);
		}
		else
			break;
	}
}
void main()
{
	int total=10;
	int i, input;//input 메뉴 선택을 위한 변수
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
	//링크드 리스트에 배열 데이터 초기화
	while(1)
	{
		printf("-----------------------------------\n");
		printf(" 1) 검색 \n 2) 입력\n 3) 삭제\n 4) print all\n 0) 종료\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:

			printf("-----------------------------------\n");
			printf("검색하실 캐릭터 이름을 입력하시오 : ");
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
			printf("삭제하실 캐릭터 이름을 입력하시오 :");
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
			printf("모든 캐릭터 정보를 출력합니다.\n");
			printall(total);

			break;
		case 0:
			printf("프로그램을 종료합니다.\n");
			return;
			break;
		}
	}
}

