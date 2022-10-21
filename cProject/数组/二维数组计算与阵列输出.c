#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define ROWS 4
#define COLS 4

double average(int *target,int n);
void print(int m,int n,int target[m][n]);
void fileprint(int m,int n,int target[m][n]);
int calculate(int m,int n,int target[m][n]);

int main(){
	int tower[ROWS][COLS],i;
	int m=3,n=4;
	for(i=0;i<ROWS*COLS;i++)scanf("%d",tower[0]+i);
	calculate(ROWS,COLS,tower);
	printf("\n������ʾ���£�\n");
	print(ROWS,COLS,tower);//�������Ļ�� 
	fileprint(ROWS,COLS,tower);//������ļ��� 
	
	return 0; 
	
}


double average(int *target,int n){
	int i,sum=0;
	for(i=(n-1)*COLS;i<n*COLS;i++)sum=sum+*(target+i);
	printf("��%d�е�ƽ����Ϊ%lf",n,(double)sum/COLS);
	return (double)sum/COLS;
}

int calculate(int m,int n,int target[m][n]){
	int i,total=0;
	for(i=1;i<=m;i++){
		total+=average(target[0],i);
	}
	printf("��ƽ����Ϊ%lf",(double)total/(i-1));
	return 0;
}

void print(int m,int n,int target[m][n]){
	int i,k;
	for(i=0;i<m;i++){
		for(k=0;k<n;k++)printf("%5d",target[i][k]);
		putchar('\n');
	}
}

void fileprint(int m,int n,int target[m][n]){
	FILE *fp;char *name=(char*)malloc(100);
	printf("������һ���ı�����");
	scanf("%s",name);
	if((fp=fopen(name,"a"))==NULL){
		fprintf(stderr,"Error:��Ŀ���ļ�ʧ��");
		exit(1); 
	} 
	int i,k;
	char convert[]={' ','.',',','*','!','|','^','%','#','&','@'};
	for(i=0;i<m;i++){
		for(k=0;k<n;k++){
			fprintf(fp,"%5c",convert[target[i][k]]);
		}
		fputs("\n",fp);
	}
	fclose(fp); 
}

