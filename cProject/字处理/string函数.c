#include<stdio.h>
#include<string.h>

char *strchr0(char *str,char ch);
int lenth(char *str);
char *strncpy0(char *str1,char *str2,int n); 
char *strncpy1(char *str1,char *str2,int n); 
	
int main(void){
	char string[20],ch,*result;
	//string=(char*)malloc(1024);
	while(1){
		printf("������һ�����֣�\n");	
		fgets(string,20,stdin);
		printf("\n������һ���ַ���\n");
		scanf("%c",&ch);
		result=strchr0(string,ch); //strchr����Ѱ��Ŀ���ַ��� 
		if(result==NULL)printf("δ�ҵ����ַ���");
		else printf("�ڵ�ַ%p�ҵ��ַ�%c",result,ch);
		do{
		ch=getchar();
		}while(ch!=EOF&&ch!='\n');//��ջ����� 
	}
} 

int lenth(char *str){
	char *p=str;int cnt=0;
	while(*p++!='\0')cnt++;
	return cnt;//����������ַ������� 
}

char *strchr0(char *str,char ch){
	char *p;
	for(p=str;*p!='\0';p++){
		if(*p==ch)break;
	};
	if(*p=='\0')return NULL;
	else return p;
}

char *strncpy0(char *str1,char *str2,int n){
	char *p=str1,*q=str2;
	while(*q!='\0'&&(q-str2)<n){
		*p=*q;
		p++;
		q++;
	}
	if(lenth(str2)<n){
		*(q+1)='\0';
	}
	return str1;
} 


char *strstr0(char *str1,char *str2){
	char *p=str1;int cnt=0;
//	printf("%d,%d,%p,%p",lenth(str1),lenth(str2),p,str1+sizeof(char)*(lenth(str1)-lenth(str2)));
	if(lenth(str1)<lenth(str2));
	else{
		while(p<=(str1+sizeof(char)*(lenth(str1)-lenth(str2)))){
//			printf("��ʼ�ж�\n");
			for(cnt=0;cnt<=lenth(str2);cnt++){
//				printf("��ǰλ��%d��cnt=%d\n",p-str1,cnt);
				if(*(p+cnt)!=*(str2+cnt)){
//					printf("Ѱ�ҵ�%dλ�ý���\n",p-str1+1);
					break;//���ֲ�����ַ�������ֹ�ôαȽ� 
				}
			}
			if(cnt==lenth(str2)){
//				printf("�ɹ��ҵ�Ŀ��\n");
				return p; 
			}
			else p++;//str2ȫ���Ƚ�����򷵻�p�����������һ�ֱȽ� 
		}
	}
//	printf("δ�ҵ�Ŀ��");
	return NULL;
}


char *strstr1(char *str1,char *str2){
	int cnt=0;char *end=str1+sizeof(char)*(lenth(str1)-lenth(str2));
	printf("%d,%d,%p",lenth(str1),lenth(str2),str1+sizeof(char)*(lenth(str1)-lenth(str2)));
	if(lenth(str1)<lenth(str2));
	else{
		while(str1<end&&cnt<lenth(str2)){
			printf("��ʼ�ж�\n");
			for(cnt=0;cnt<lenth(str2);cnt++){
				printf("��ǰλ��%d��cnt=%d\n",str1,cnt);
				if(*(str1+cnt)!=*(str2+cnt)){
				printf("Ѱ�ҵ�%dλ�ý���\n",str1);
					break;//���ֲ�����ַ�������ֹ�ôαȽ� 
				}
			}
			str1++;
		}
	}
	if(cnt=lenth(str2)){
		printf("�ҵ�Ŀ��");
		return str1;
	}
	printf("δ�ҵ�Ŀ��");
	return NULL;
}


	
