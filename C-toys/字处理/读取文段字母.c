#include<stdio.h>
#include<ctype.h>


int get_alpha(void);
char get_firstchar(void);

int main(void){

	return 0;
}

char get_firstchar(void){
	char ch,ret;short int haschange=0;
	printf("***�����Ķμ����׸��ǿ��ַ�***\n");
	while((ch=getchar())!=EOF){
		if(!ispunct(ch)&&!isspace(ch)&&haschange==0){
		ret=ch;
		haschange=1;
		}
	}
	printf("�׸��ǿ��ַ�Ϊ%c\n",ret);
	return ret;
}


int get_alpha(void){
	int ch;
	printf("***�����Ķμ������е���ĸ***/n");
	while((ch=getchar())!=EOF){
		if(isalpha(ch)){
			printf("��������ĸ%c\n",ch);
			if(isupper(ch))ch=ch-'A'+'a';
			printf("����ĸ����ĸ���д��ڵ�%dλ\n",ch-'a'+1);
		}
	}
	return 0;
}
