#include<stdio.h>
#include<stdbool.h>
#include"function.h"



extern bool Auto_save_mode;


char show_menu_main(void);


int main(){
	puts("���������");
	int i=0;char ch;
	read();
	
	while(ch!='q'&&ch!=EOF){
		switch (ch=show_menu_main()){
			case '1':add();
			break;
			case '2':change();
			break;
			case '3':source();
			break;
			case '4':statistics();
			break;
			case '5':book();
			break;
			case '6':Auto_save_change();
			break;
			case '7':read();
			break;
			case '8':save();
			break;
			default:break;
		}
	}
	puts("�˳�ǰ�Ƿ񱣴棿�������밴һ,�����水�������\n"); 
	if(getchar()=='1')save();
	puts("�����������л����ʹ��\n");
	return 0; 
}

char show_menu_main(void){
	if(Auto_save_mode==1)save();
	puts("\n____________________________________________________\n\n");
	puts("*****��ӭʹ�÷��ز��������*****\n");
	puts("1)�¿ͻ��Ǽ�    2)�޸Ŀͻ�����   3)��Դ���� \n"); //add/change/source
	printf("4)ͳ��          5)Ԥ���Ǽ�       6)%s�Զ�����ģʽ\n\n",Auto_save_mode?"�ر�":"����"); //save/read/Autp_save_change
	puts("7)��ȡ����      8)��������       q)�˳�\n");
	puts("______________________________________________________\n\n");
	char ch='0',c='0'; 
	ch=tolower(getchar());
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	//printf("%c %c",ch,c);
	return ch;
}


