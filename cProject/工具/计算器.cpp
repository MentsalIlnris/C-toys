
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkout(int *p) {
	int c;
	while(scanf("%d", p)!=1){
		printf("������������������:");
		while ((c = getchar()) != EOF && c != '\n');
	}
}

int add() {
	//int a,i;
	//for(i=0;i<10;i++){
	//a=rand()%3;
	//printf("%d  ",a);
	//}
    printf("ʹ�üӷ������밴1��ʹ�ü��������밴2\n");
    int n=0;
    scanf("%d", &n);
    if (n==2){
    int a;
    int b;
    printf("�����뱻������");
    scanf("%d", &a);
    printf("�����������");
    scanf("%d", &b);
    int change = a-b;
    printf("�õ�%d��\n", change);
    }
    if(n==1){
    int a;
    int b;
    printf("�����뱻������");
	checkout(&a);
    printf("�����������");
    checkout(&b);
    int change = a+b;

    printf("�õ�%d��\n", change);
    }
    getchar();
    return 0;
}

int analyze(){
	printf("***���������жϹ���***\n"); 
	printf("����-1�������\n");
int a,x=0,RESULT;
while(1){
    a=2;RESULT=1;
    printf("������\n");
    checkout(&x);
    if(x==-1)break;
	if(x==1)printf("error:����Ϊ1\n");
    else if(x<9999) {
        while((a<x)&&(RESULT!=0)){
	    	RESULT=x%a;
	    	a++;
        } 
		if(a==x)printf("��%dΪ����\n",x);
    	else(printf("��%dΪ����\n",x)) ;
    }
    else{
		printf("error:��ֵ�����޷�����\n");
    };
   
    }
 	printf("����\n") ;
    return 0;
}

int main()

{
	printf("***��ӭʹ�ü�����***\n");
	printf("�����������밴1�������ж��밴2��\n");
	analyze();
	
	return 0;
}

