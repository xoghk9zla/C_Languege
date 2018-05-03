//2014182011김태화
//2014.5.29(목)
#include <stdio.h>
struct charcter{
	char name[10];//캐릭터이름
	double hp,speed;//체력, 이동속도
	float atk,def;//공격력, 방어력
};

void scan(struct charcter *pst, int n);//캐릭터이름,체력, 이동속도, 공격력,방어력을 입력받기 위한 함수
void print(struct charcter *pst, int n);//출력을 위한 함수

int main(void)
{
	struct charcter ch[5];//객체선언

	scan(ch,5); //함수의 호출
	print(ch,5);

	return 0;
}

void scan(struct charcter *pst, int n)//캐릭터이름,체력, 이동속도, 공격력,방어력을 입력받기 위한 함수
{
	int i;
	printf("이름 : 체력 , 이동속도 , 방어력 을 입력하세요. \n");
	for(i=0;i<n;i++)
	{
		scanf("%s %lf %lf %f %f", pst[i].name, &pst[i].hp, &pst[i].speed, &pst[i].atk, &pst[i].def);//객체하나하나에 캐릭터이름,체력, 이동속도, 방어력을 입력
	}
	printf("\n");
}
void print(struct charcter *pst, int n)//출력을 위한 함수
{
	int i;
	printf("이름 : 체력 , 이동속도 , 방어력 \n\n");
	for(i=0;i<n;i++)
	{
		printf("%s : %.2f , %.2f , %.2lf, %.2lf \n", pst[i].name, pst[i].hp, pst[i].speed, pst[i].atk, pst[i].def);//객체에 들어간 내용을 하나씩 출력
	}
}

