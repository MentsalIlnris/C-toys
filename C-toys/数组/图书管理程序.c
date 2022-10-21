#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define BSIZE 20
#define NSIZE 6


struct book{
	char name[NSIZE];
	_Bool isblank;
	char infor[100];
};


char buffer[50];

char show_menu(void);
int add(struct book books[]);
int del(struct book books[]);
void read(struct book target[]);
void print(struct book target[]);
void save(struct book target[]);

struct book books[BSIZE];

int main(){
	puts("���������");
	int i=0;char ch;
	for(i=0;i<BSIZE;i++){
		books[i].isblank=1;
	}
	while(ch!='q'&&ch!=EOF){
		switch (ch=show_menu()){
			case 'a':add(books);
			break;
			case 'd':del(books);
			break;
			case 'r':read(books);
			break;
			case 's':save(books);
			break;
			case 'p':print(books);
			break;
			default:break;
		}
	}
	puts("�������");
	return 0; 
}


char show_menu(void){
	puts("\n____________________________________________________\n\n");
	puts("*****��ӭʹ��ͼ��������*****\n");
	puts("a)add����ͼ��    d)delɾ��ͼ��         r)read��������\n"); 
	puts("s)save��������   p)print��ʾ����ͼ��   q)quit�˳�\n"); 
	puts("______________________________________________________\n\n");
	char ch='0',c='0'; 
	ch=tolower(getchar());
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	//printf("%c %c",ch,c);
	return ch;
}


int add(struct book books[]){
	int i=0;char c;
	for(i=0;i<BSIZE;i++){
		if(books[i].isblank==1)break;
	}
	if(i==BSIZE){
		fputs("Error:Don't have enough space\n",stderr);
		return 1;
	}
	puts("����������\n");
	scanf("%s",buffer);
	if(strlen(buffer)>NSIZE){
		fputs("Error:Name too long\n",stderr);
		return 1;
	}
	strcpy(books[i].name,buffer);
	printf("�������鼮��%s���������Ϣ\n",books[i].name);
	while(scanf("%s",books[i].infor)!=1) 
	{
		fputs("Error:������������������\n",stderr);
		while ((c = getchar()) != EOF && c != '\n');
	}
	books[i].isblank=0;
	puts("�����\n");
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	return 0;
}


int del(struct book books[]){
	int i=0;char c;
	puts("����������\n");
	while(scanf("%s",books[i].name)!=1) 
	{
		fputs("Error:������������������\n",stderr);
		while ((c = getchar()) != EOF && c != '\n');
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	for(i=0;i<BSIZE;i++){
		if(books[i].isblank==1)continue;
		if(!strcmp(books[i].name,buffer)){
			books[i].isblank=1;
			break;
		} 
	}
	if(i==BSIZE){
		fputs("�Ҳ���ָ������\n",stderr);
		return 1;
	}
	puts("��ɾ��\n");
	return 0;
}


void read(struct book target[]){
	int i=0;FILE *fp;
	if((fp=fopen("library","r"))==NULL){
		fprintf(stderr,"Error:���ļ�ʧ��\n");
		exit(-1);
	}
	while(fscanf(fp,"%s",buffer)==1&&i<BSIZE){
		if(strcmp(buffer,"book"))continue;
		fscanf(fp,"%s",target[i].name);
		printf("��ȡͼ�顶%s��\n",target[i].name);
		fgets(target[i].infor,100,fp);
		target[i].isblank=0;
		i++;
	}
	fclose(fp);
	puts("���ݶ���ɹ�\n");
}


void print(struct book target[]){
	int i=0;
	puts("������"); 
	while(i<BSIZE){
		if(target[i].isblank==0){
		printf("book��%s����%s\n",target[i].name,target[i].infor);
		}
		i++;
	}
	puts("ȫ��ͼ������ʾ\n");
	
}


void save(struct book target[]){
	int i=0;FILE *fp;
	if((fp=fopen("library","w"))==NULL){
		fprintf(stderr,"Error:���ļ�ʧ��\n");
		exit(-1);
	}
	while(i<BSIZE){
		if(target[i].isblank==0){
			fprintf(fp,"book %s %s\n",target[i].name,target[i].infor);
		}
	i++;
	}
	puts("�ѱ���\n");
	fclose(fp);
}



