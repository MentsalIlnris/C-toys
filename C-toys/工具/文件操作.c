#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define BUFFER_SIZE 16

int main(int argc,char *argv[]){
	FILE *fp1,*fp2; 
	char *buff,ch;
	buff=malloc(BUFFER_SIZE);
	printf("%d",argc);
	if(argc!=3){
		fprintf(stderr,"Error:������ƥ�䣬����������������%s\n",argv[1]);
		exit(-1);
	}
	if((fp1=fopen(argv[1],"rb"))==NULL){
		fprintf(stderr,"Error:��%sʧ��\n",argv[1]);
		exit(-1);
	}
	//ʵ�ָ��� 
	if((fp1=fopen(argv[2],"wb"))==NULL){
		fprintf(stderr,"Error:��%sʧ��\n",argv[2]);
		exit(-1);
	}
	size_t bytes;
	while((bytes=fread(buff,sizeof(char),BUFFER_SIZE,fp1))>0){
		fwrite(buff,sizeof(char),BUFFER_SIZE,fp2);
	}
	
	//ʵ���������ַ�����
	while((ch=getc(fp1))!=EOF){
		fseek(fp1,-sizeof(char),SEEK_CUR);
		putc(toupper(ch),fp1);
		//putchar(ch);
	}
	//ʵ���ļ��о��Ӵ���
	char line[BUFFER_SIZE];
	while(fgets(line,BUFFER_SIZE,fp1)!=NULL){
		char *p=line;
		while(*p!='\0'){
			p++;
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

//#define N 100
//int main() {
//    FILE *fp;
//    char str[N + 1];
//    //�ж��ļ��Ƿ��ʧ��
//    if ( (fp = fopen("d:\\demo.txt", "rt")) == NULL ) {
//        puts("Fail to open file!");
//        exit(0);
//    }
//    //ѭ����ȡ�ļ���ÿһ������
//    while( fgets(str, N, fp) != NULL ) {
//        printf("%s", str);
//    }
//   
//    //����������ر��ļ�
//    fclose(fp);
//    return 0;
//}


