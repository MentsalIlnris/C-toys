#include<stdio.h>
#include<ctype.h>
#define STOP '|'
#define SIZE 8


void get_firstword(int len);
int sum(void);
int fun(char *s);

int main(){
	printf("%d",fun("hello,  asd world   "));
	//get_firstword(SIZE);
	return 0;
} 

int sum(void){
	char prev='\n',c;int word=0,count=0;
	printf("***��������������Ӣ�Ķε��������ַ���***\n");
	while((c=getchar())!=EOF){
		if((!ispunct(c)&&!isspace(c))&&(isspace(prev)||ispunct(prev)))word++;
		if(!ispunct(c)&&!isspace(c))count++;
		prev=c;
	}
	printf("��������Ϊ%d,�ַ�����Ϊ%d,ƽ��ÿ��������%lf���ַ�",word,count,(double)count/(double)word);
	
	return 0;

}


void get_firstword(int len){
	printf("***�����Ķζ�ȡ�׸�����***\n");
	char word[len],ch=0;int i=1;
	while(!isalpha(ch=getchar())); 
	word[0]=ch;
	while((isalpha(ch=getchar()))&&(i<len)){
		word[i]=ch;
		i++;
	}
	word[i]='\0' ;
	puts(word); 
} 

//int fun(char *s){
//	char c=*s,prev='\n';int word=0,i=0;
//	while(c!='\0'){
//		if(c>='a'&&c<='z'&&(prev<'a'||prev>'z'))word++;
//		prev=c;
//		i++;
//		c=*(s+i);
//	}
//	
//	return word;
//
//}

int fun(char *s)
{
  int i,j=0;
  for(i=0;s[i]!='\0';i++)
     if(s[i]!=' '&&(s[i+1]==' '||s[i+1]=='\0'))   /*���һ����ĸ����һ���ַ�Ϊ�ո���߽�����ǣ����ʾһ�����ʽ���*/
        j++;
  return j;           /*���ص��ʸ���*/
}

 
