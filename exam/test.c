#include "student_info.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void judge(int n)
{

	char str[40]="0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39"
	int i;
	for(i=0;i<40;i++){
		
	}

}

int main()
{       int i,j,n,m;
	srand((unsigned)time(NULL));
	for (j = 0; j < sizeof(info)/sizeof(struct student); ++j) {
		printf("%d - %s\n", info[j].id, info[j].name);
	}
	while(1)	
	{	
        	for(n=1;n<11;n++){
			i=rand()%40; //产生0-39的随机数
			printf("第n组成员：%d - %s\n", info[i].id, info[i].name);
			
			printf("第n组成员：%d - %s\n", info[i2].id, info[i2].name);
			printf("第n组成员：%d - %s\n", info[i3].id, info[i3].name);
			printf("第n组成员：%d - %s\n", info[i4].id, info[i4].name);
		}
	}
}
