#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SIZE 100
//#include"head.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0,cnt1=0,cnt2=0,cac,ch[SIZE];
	int *p;
	while(getchar()!=EOF&&i<SIZE){                                                                                        
		printf("���������%d",cac=product()%100);
		if(cac<50)cnt1++;
		else cnt2++;
		ch[i]=cac;
		i++;
	}
	printf("�������У�С����ʮ����ռ��%lf",(double)cnt1/(cnt1+cnt2));
	fopen(argv[1],"a+");
	for(p=ch;p<ch+sizeof(ch)/sizeof(int);p++)printf("%d\n",*p);
	rank(ch,ch+100);
	for(p=ch;p<ch+sizeof(ch)/sizeof(int);p++)printf("%d\n",*p);
	return 0;
}
