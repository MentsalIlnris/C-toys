#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define fleet_SIZE 20
#define NSIZE 10

struct f_seat{
	int id;
	_Bool isblank;
	char name[NSIZE];
}; 

struct flight{
	char name[NSIZE];
	int s_amount;//s_amountΪ0��ʾ���಻���� 
	int empty;
	char infor[50];
	struct f_seat *seats;
}fleet[fleet_SIZE];



char buffer[50];

char show_menu_main(void);
int choose(void);
char show_menu_miner(int i);
int add(void);
int del(void);
void read(void);
void save(void);
	
int main(void){
	puts("���������");
	int i=0;char ch;
	for(i=0;i<fleet_SIZE;i++){
		fleet[i].s_amount=0;
		//strcpy(fleet[i].infor,"None");
	}
	while(ch!='q'&&ch!=EOF){
		switch (ch=show_menu_main()){
			case 'a':add();
			break;
			case 'd':del();
			break;
			case 'r':read();
			break;
			case 's':save();
			break;
			case 'c':choose();
			break;
			default:break;
		}
	}
	puts("�������");
	return 0; 
}


char show_menu_main(void){
	puts("\n____________________________________________________\n\n");
	puts("*****��ӭʹ�ú���λ�ΰ��ų���*****\n");
	puts("a)add���Ӻ���    d)delɾ������       c)chooseѡ�񺽰� \n"); 
	puts("s)save��������   r)read��������      q)quit�˳�\n"); 
	puts("______________________________________________________\n\n");
	char ch='0',c='0'; 
	ch=tolower(getchar());
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	//printf("%c %c",ch,c);
	return ch;
}

int choose(void) {
	int i=0,k=0;char ch,c;	struct flight *selected;
	while(i<fleet_SIZE){
		if(fleet[i].s_amount!=0){
			printf("flight %s��%s\n",fleet[i].name,fleet[i].infor);
		}
		i++;
	}
	puts("ȫ����������ʾ\n");
	puts("\n***�����뺽��������������***\n");
	scanf("%s",buffer);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("������"); 
	for(i=0;i<fleet_SIZE;i++){
		if(fleet[i].s_amount!=0){
			if(strcmp(fleet[i].name,buffer)==0) {
				printf("find flight %s��%s\n",fleet[i].name,fleet[i].infor);
				selected=&fleet[i];
				break;
			}
		}
	}
	if(i==fleet_SIZE){
		puts("û���ҵ�Ŀ�꺽��");
		return 1; 
	}

	while(ch!='q'&&ch!=EOF){
		switch (ch=show_menu_miner(i)){
			case 'b':book(selected);
			break;
			case 'c':cancel(selected);
			break;
//			case 'p':print(selected);
//			break;
//			default:break;
		}
	}
	puts("�������");
	return 0; 
}



char show_menu_miner(int i){
	puts("\n____________________________________________________\n\n");
	printf("flight %s ��ʣ%d��λ\n",fleet[i].name,fleet[i].empty);
	puts("*****�����*****\n");
	puts("   b)flightԤ����λ      c)cancelȡ��Ԥ��\n"); 
	puts("   p)print��ʾ��λ     q)quit�˳�\n"); 
	puts("______________________________________________________\n\n");
	char ch='0',c='0'; 
	ch=tolower(getchar());
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	//printf("%c %c",ch,c);
	return ch;
}


int add(void){
	int i=0,k=0;char c;
	for(i=0;i<fleet_SIZE;i++){
		if(fleet[i].s_amount==0)break;
	}
	if(i==fleet_SIZE){
		fputs("Error:Don't have enough space\n",stderr);
		return 1;
	}
	puts("�����뺽����\n");
	scanf("%s",buffer);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	if(strlen(buffer)>NSIZE){
		fputs("Error:Name too long\n",stderr);
		return 1;
	}
	strcpy(fleet[i].name,buffer);
	printf("�����뺽�� %s �������Ϣ\n",fleet[i].name);
	while(scanf("%s",fleet[i].infor)!=1) 
	{
		fputs("Error:������������������\n",stderr);
		while ((c = getchar()) != EOF && c != '\n');
	}
	printf("�����뺽�� %s ����λ����\n",fleet[i].name);
	while(scanf("%d",&fleet[i].s_amount)!=1||fleet[i].s_amount<=0) 
	{
		fputs("Error:������������������\n",stderr);
		while ((c = getchar()) != EOF && c != '\n');
	}
	fleet[i].seats=malloc(sizeof(struct f_seat)*fleet[i].s_amount);//Ϊseats����ռ� 
	for(k=0;k<fleet[i].s_amount;k++){
		fleet[i].seats[k].id=k;
		fleet[i].seats[k].isblank=1;
	}
	fleet[i].empty=fleet[i].s_amount;
	puts("�����\n");
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	return 0;
}


int del(void){
	int i=0;char c;
	puts("�����뺽����\n");
	while(scanf("%s",buffer)!=1) 
	{
		fputs("Error:������������������\n",stderr);
		while ((c = getchar()) != EOF && c != '\n');
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	for(i=0;i<fleet_SIZE;i++){
		if(fleet[i].s_amount==0)continue;
		if(!strcmp(fleet[i].name,buffer)){
			fleet[i].s_amount=0;//s_amount==0��ʾ���಻���� 
			free(fleet[i].seats);
			break;
		} 
	}
	if(i==fleet_SIZE){
		fputs("�Ҳ���ָ������\n",stderr);
		return 1;
	} 
	puts("��ɾ��\n");
	return 0;
}


void read(void){
	int i=0,k=0,cnt=0;FILE *fp;
	if((fp=fopen("flights","r"))==NULL){
		fprintf(stderr,"Error:���ļ�ʧ��\n");
		exit(-1);
	}
	while(fscanf(fp,"%s",buffer)==1&&i<fleet_SIZE){
		if(strcmp(buffer,"flight"))continue;
		fscanf(fp,"%s",fleet[i].name);
		printf("��ȡ���� %s \n",fleet[i].name);
		if(fscanf(fp,"%d",&fleet[i].s_amount)!=1) 
		{
			fputs("Error:���ݸ�ʽ����\n",stderr);
			return;
		}
		fleet[i].empty=fleet[i].s_amount;
		fleet[i].seats=malloc(sizeof(struct f_seat)*fleet[i].s_amount);//Ϊseats����ռ� 
		for(k=0;k<fleet[i].s_amount;k++){
			printf("��λ%d\n",k);
			if(fscanf(fp,"%d ",&fleet[i].seats[k].isblank)!=1) 
			{
				fscanf(fp,"%s ");
				if(cnt>3){
					fputs("Error:id���ݸ�ʽ����\n",stderr);
					return;
				}
			}
			if(fleet[i].seats[k].isblank==0){
				if(fscanf(fp,"%s ",fleet[i].seats[k].name)!=1) 
				{
					fputs("Error:name���ݸ�ʽ����\n",stderr);
					return;
				}
				fleet[i].empty--;
			}
		}
		fscanf(fp,"%s",fleet[i].infor);
		printf("��ʣ%d��λ\n",fleet[i].empty);
		i++;
	}
	fclose(fp);
	puts("���ݶ���ɹ�\n");
}



void save(void){
	int i=0,k=0;FILE *fp;
	if((fp=fopen("flights","w"))==NULL){
		fprintf(stderr,"Error:���ļ�ʧ��\n");
		exit(-1);
	}
	while(i<fleet_SIZE){
		if(fleet[i].s_amount!=0){
			fprintf(fp,"flight %s\n %d\n",fleet[i].name,fleet[i].s_amount);
		}
		for(k=0;k<fleet[i].s_amount;k++){
			fprintf(fp," %d ",fleet[i].seats[k].isblank);
			if(fleet[i].seats[k].isblank==0){
				fprintf(fp," %s ",fleet[i].seats[k].name);
			}
		}
		fputs(fleet[i].infor,fp);
		fputc('\n',fp);
		i++;
	}
	puts("�ѱ���\n");
	fclose(fp);
}


int book(struct flight *selected){
	int i=0;char c;
	puts("����������\n");
	scanf("%s",buffer);
	if(strlen(buffer)>NSIZE){
		fputs("Error:Name too long\n",stderr);
		return 1;
	}
	puts("����������Ԥ����λ��\n");
	while(scanf("%d", &i)!=1||i<0||i>(*selected).s_amount){
		printf("������������������:");
		while ((c = getchar()) != EOF && c != '\n');
	}
	(*selected).seats[i].isblank=0;
	strcpy((*selected).seats[i].name,buffer);
	(*selected).empty--;
	puts("��Ԥ��\n");
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	return 0;
}

int cancel(struct flight *selected){
	int i=0;char ch,c;
	puts("��������Ԥ����λ��\n");
	while(scanf("%d", &i)!=1&&i<0&&i>(*selected).s_amount){
		printf("������������������:");
		while ((c = getchar()) != EOF && c != '\n');
	}
//	printf("ȷ��ȡ���˿�-%s-��Ԥ����\n",(*selected).seats[i].name);
//	ch=getchar();
//	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
//	if(ch!=1){
//		puts("ȡ��cancel\n");
//		return;
//	}
	(*selected).seats[i].isblank=1;
	(*selected).empty++;
	puts("��ȡ��\n");
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	return 0;
}
