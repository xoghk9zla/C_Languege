#include <stdio.h>

struct charcter{
	char name[10];
	int hp, speed, dp;
};

void scan(struct charcter *pst, int n);
void print(struct charcter *pst, int n);

int main(void)
{
	struct charcter ch[5];

	scan(ch,5);
	print(ch,5);

	return 0;
}

void scan(struct charcter *pst, int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%s", pst[i].name);
	}

}

void print(struct charcter *pst, int n)
{
	printf("이름 // 체력  // 이동속도 // 방어력 \n");
	printf("\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%s // %d // %d // %d \n", pst[i].name, pst[i].hp, pst[i].speed, pst[i].dp);
	}
}
