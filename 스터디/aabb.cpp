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

	struct Cyphers *next; // 다음 객체를 가르키는 포인터

};
typedef struct Cyphers CYP; //구조체 이름 간단히 선언하기

CYP* add_data(CYP*); //데이터를 추가하는 함수
void prt_all(CYP*); //데이터 전부 출력하는 함수
void search_data(CYP*); //검색 함수
CYP* delete_data(CYP*); //삭제 함수

void main()
{

	int key; //기능 선택 변수, 입력 값에 따라 기능 사용

	CYP *head, *tail; //처음과 끝 주소를 저장하는 포인터
	head=(CYP*)malloc(sizeof(CYP)); //메모리 공간을 생성하는 함수, 첫번째로 실행되므로 head포인터에 주소값 복사
	tail = head; //공간이 1개 이므로 시작과 끝이 같음
	head->next = NULL; //첫번째 객체의 다음에는 데이터가 없으므로 널값을 넣는다.


	//링크드 리스트에 배열 데이터 초기화
	
	while(1)
	{
		printf("-----------------------------------------------\n");
		printf("1) 검색 \n2) 입력\n3) 삭제\n4) print all\n0) 종료\n");
		scanf("%d",&key);
		printf("-----------------------------------------------\n");


		switch(key)
		{
		case 1:
			search_data(head); //데이터 찾기, 시작 위치 포인터를 전달한다.
			system("cls"); // 화면 클리어 함수
			break;
		case 2:
			tail = add_data(tail); //데이터 삽입, 마지막 위치 포인터를 전달하고, 마지막 위치를 반환한다.
			system("cls");
			break;
		case 3:
			head = delete_data(head); //데이터 삭제, 시작 위치를 전달하고, 시작위치를 반환한다.
			system("cls");
			break;
		case 4:
			system("cls");
			printf("모든 캐릭터 정보를 출력합니다.\n");
			prt_all(head); //모든 데이터 출력, 시작위치 전달
			getchar(); //화면 대기 함수, 아무키나 누르면 다음 진행
			system("cls");
			break;
		case 0:
			printf("프로그램을 종료합니다.\n");
			return;
			break;
		}
	}
}


CYP* add_data(CYP *pCYP)
{
	printf("입력할 케릭터 이름 : \n");
	fflush(stdin); //임시로 키보드 입력값을 받아논 데이터의 버퍼를 지우는 함수
	gets(pCYP->name); //현재 객체의 이름 부분에 데이터 입력
	printf("입력한 케릭터의 공격력 : \n");
	scanf("%d", &pCYP->att);
	printf("입력한 케릭터의 방어력 : \n");
	scanf("%d", &pCYP->arm);
	printf("입력한 케릭터의 체력 : \n");
	scanf("%d", &pCYP->HP);
	
	pCYP->next = (CYP*)malloc(sizeof(CYP)); //현재 객체에 데이터가 들어갔으므로 다음 객체의 공간을 생성한다.
	pCYP=pCYP->next; //반환할 꼬리포인터에 현 객체의 다음 객체 주소 복사
	pCYP->next=NULL; //다음 객체의 다음 객체 가르키는 위치에 널포인터 삽입

	return pCYP;
}

void prt_all(CYP *pCYP)
{
	while(pCYP->next != NULL) //마지막 객체가 없을때까지 반복
	{
		printf("이름 : %s\n",pCYP->name);
		printf("공격력 : %d\n",pCYP->att);
		printf("방어력 : %d\n",pCYP->arm);
		printf("체력 : %d\n",pCYP->HP);
		printf("-----------------------------------------------\n");
		pCYP = pCYP->next; //다음객체로 이동
	}
	getchar();
}

void search_data(CYP* pCYP)
{
	char iname[20]; //임시 문자열 저장공간

	printf("-----------------------------------\n");
	printf("검색하실 캐릭터 이름을 입력하시오 : ");
	fflush(stdin);
	gets(iname);
	system("cls");
	while(pCYP->next != NULL) 
	{
		if(0 == strcmp(pCYP->name, iname)) //문자열 비교 함수, 서로 같으면 0이 반환된다.아니면 1반환
		{
			printf("이름 : %s\n",pCYP->name);
			printf("공격력 : %d\n",pCYP->att);
			printf("방어력 : %d\n",pCYP->arm);
			printf("체력 : %d\n",pCYP->HP);
			printf("-----------------------------------------------\n");
			break;
		}
		pCYP = pCYP->next; //다음객체로 이동
	}
	getchar();
}

CYP* delete_data(CYP* pCYP)
{
	char iname[20]; //임시 이름 저장공간
	int count=1; //비교 위치를 가늠하는 카운터 변수

	printf("삭제하실 캐릭터 이름을 입력하시오 :");
	fflush(stdin);
	gets(iname);
	CYP *start=pCYP;
	CYP *tmp;

	while(pCYP->next != NULL)
	{
		if(0 == strcmp(pCYP->name, iname)) //찾았다 요놈
		{
			if(count==1) //맨처음 객체면
			{
				start = pCYP->next; //시작 포인터만 바꾸고
				free(pCYP); //메모리 해제
				break;
			}
			else
			{
				tmp->next = pCYP->next; //그게 아니면 이전 객체의 꼬리포인터에 다음 객체의 주소를 복사
				free(pCYP); // 현객체 메모리 해제
				break;
			}
		}
		count++; //카운터 증가
		tmp=pCYP; //임시공간에 현제 객체 주소 복사
		pCYP = pCYP->next; //다음객체로 넘어감
	}
	getchar();

	return start;
}