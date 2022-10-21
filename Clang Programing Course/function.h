#include"basic.h"



void add(void){
	guest *now=pguest;
	estate *finder=pestate;
	char c;
	if(now!=NULL)while(now->next!=NULL)now=now->next;
	now=newnode_guest(now);
	puts("������ͻ��ĵ绰");
	if(scanf("%s",now->p_number)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("������ͻ�������");
	if(scanf("%s",now->name)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("��������ͻ�ͨ���Ĵ���");
	if(scanf("%d",&now->call_number)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("���������һ����ͻ�ͨ����ʱ��(�������ÿո�������磺2020 12 31)");
	if(scanf("%d %d %d",&now->last_call[0],&now->last_call[1],&now->last_call[2])!=3){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	get_guest_order(now);
	printf("�����¿ͻ�%s�ɹ�",now->name);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
} 


void change(void){
	char ch='0',c;
	int i=0;
	guest *finder=pguest,*now;
	puts("������Ҫ�ı���Ϣ�ͻ�������\n");
	scanf("%s",buffer);
	if(pestate!=NULL){
		for(finder=pguest;(finder!=NULL);finder=finder->next)
			if(strcmp(finder->name,buffer)==0)break;
	}
	if(finder==NULL){
		puts("û���ҵ��ÿͻ���\n");
		while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
		return;
	}
	else {
		now=finder;
		printf("�ҵ��û���%s",finder->name);
		printf("�绰%9s\n",finder->p_number);
		printf("�绰����%2d\n",finder->call_number);
		printf("�ϴ�ͨ��ʱ��%4d��%2d��%2d��\n",finder->last_call[0],finder->last_call[1],finder->last_call[2]);
		for(i=0;i<3;i++){
			if(now->order[i]!=0)
				printf("���������Դ%d:%d\n",i+1,now->order[i]);
		}
		while(ch!='q'&&ch!=EOF){
			switch (ch=show_menu_change()){
				case '1':puts("������ͻ��ĵ绰");
					if(scanf("%s",now->p_number)!=1){
						WARN;
					}
					break;
				case '2':puts("��������ͻ�ͨ���Ĵ���");
					if(scanf("%d",&now->call_number)!=1){
						WARN;
						}
					break;
				case '3':puts("���������һ����ͻ�ͨ����ʱ��(�������ÿո�������磺2020 12 31)");
					if(scanf("%d %d %d",&now->last_call[0],&now->last_call[1],&now->last_call[2])!=3){
						WARN;
					}
					break;
				case '4':get_guest_order(now);
					break;
				case '5':del(now);
				default:break;
			}
			while ((c = getchar()) != EOF && c != '\n');//��ջ�����
			if(ch=='5')break;
		}
		printf("�޸Ŀͻ�%s�ɹ�",now->name);
	}
	return;
}
		
		


void source(void){
	char c;
	estate *finder=pestate;
	int token;
	if(pestate==NULL){
		puts("\nError:û�м�⵽�κη�Դ\n");
	}
	struct find_flag{
		int direction;
		int f_level[2];
		int size[2];
		int price[2];
	}flag;
	puts("\n��������ҷ�Դ��Χ��\n");
	puts("\n��������0-ȫѡ��1-�ϣ�2-����3-����4-��\n"); 
	scanf("%d",&flag.direction);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("\n¥�����������������ߣ���������5 10����������嵽ʮ��ķ�Դ��\n"); 
	scanf("%d %d",&flag.f_level[0],&flag.f_level[1]);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("\n����������������ߣ���������50 200�����������ʮ������ƽ���׵ķ�Դ��\n"); 
	scanf("%d %d",&flag.size[0],&flag.size[1]);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("\n�۸������������ߣ���������500 20000���������500��20000Ԫÿƽ���׵ķ�Դ��\n"); 
	scanf("%d %d",&flag.price[0],&flag.price[1]);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("\n������\n") ;
	for(finder=pestate;finder!=NULL;finder=finder->next){
		token=(finder->f_level>flag.f_level[0]&&finder->f_level<flag.f_level[1]);
		token=token&&(finder->size>flag.size[0]&&finder->size<flag.size[1]);
		token=token&&(finder->price>flag.price[0]&&finder->price<flag.price[1]);
		if(token==1){
			if(flag.direction==0||flag.direction==finder->direction)
				print_estate(finder);
		}
	}
}


void statistics(void){
	int i=0,max_sold=0,cnt=0;
	estate *now=pestate;
	while(now!=NULL){
		if(now->sold>max_sold){
			max_sold=now->sold;
			cnt++;
		}
		now=now->next;
	}
	printf("�ͻ�����Դ��%d��\n",cnt);
	for(i=max_sold;i>0;i--){
		for(now=pestate;now!=NULL;now=now->next){
			if(now->sold==i)print_estate(now);
		}
	}
}


void book(void){
	sold_estate *now=psold;
	char c;
	if(now!=NULL)while(now->next!=NULL)now=now->next;
	now=newnode_sold(now);
	puts("���������");
	if(scanf("%d",&now->size)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("������۸�");
	if(scanf("%d",&now->price)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("������ɽ�ʱ��(�������ÿո�������磺2020 12 31)");
	if(scanf("%d %d %d",&now->time[0],&now->time[1],&now->time[2])!=3){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("�����뵥��");
	if(scanf("%d",&now->id)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("������ͻ�������");
	if(scanf("%s",now->name)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	puts("������ͻ��ĵ绰");
	if(scanf("%s",now->p_number)!=1){
		WARN;
	}
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
	printf("�����º�ͬ%d�ɹ�",now->id);
	while ((c = getchar()) != EOF && c != '\n');//��ջ����� 
}

void read(){
	int i=0,k=0;
	FILE *fp;
	puts("\n���ڶ�ȡ����\n");
	
	//��ȡsource 
	
	estate *now=pestate;
	if((fp=fopen("source.txt","r"))==NULL){
		fprintf(stderr,"Error:���ļ�source.txtʧ��\n");
		exit(-1);
	}
	if(now!=NULL)while(now->next!=NULL)now=now->next;
	while(fscanf(fp,"%s",buffer)==1){
		if(!strcmp(buffer,"estate")){
			now=newnode_estate(now);
		}
		else{
			puts("fail on estate");
			WARN;
		}
		puts("success in estate");
		if(fscanf(fp,"%d",&now->id)!=1)
			WARN;
		printf("����%3d ",now->id);
		if(fscanf(fp,"%d",&now->sold)!=1)
			WARN;
		printf("����%2d�� ",now->sold);
		if(fscanf(fp,"%d",&now->direction) !=1&&!(now->direction>0&&now->direction<5))
			WARN;
		printf("��%s ",directions[now->direction-1]);
		if(fscanf(fp,"%d",&now->f_level) !=1)
			WARN;
		printf("%3d�� ",now->f_level);
		if(fscanf(fp,"%d",&now->size) !=1)
			WARN;
		printf("���%6d ",now->size);
		if(fscanf(fp,"%d",&now->price) !=1&&!(now->direction>0&&now->direction<5))
			WARN;
		printf("�۸�%6d ",now->price);
		if(fscanf(fp,"%s",now->infor)!=1)
			WARN;
		printf("��飺%s\n\n",now->infor);
	}
	fclose(fp);
	
	//��ȡguest 
	
	guest *guest_now=pguest;
	if((fp=fopen("guests.txt","r"))==NULL){
		fprintf(stderr,"Error:���ļ�guests.txtʧ��\n");
		exit(-1);
	}
	if(guest_now!=NULL)while(guest_now->next!=NULL)guest_now=guest_now->next;
	puts("yes");
	while(fscanf(fp,"%s",buffer)==1){
		if(!strcmp(buffer,"guest")){
			guest_now=newnode_guest(guest_now);
		}
		else{
			puts("fail on guest");
			WARN;
		}
		if(fscanf(fp,"%s",guest_now->p_number)!=1)
			WARN;
		printf("�绰%9s\n",guest_now->p_number);
		if(fscanf(fp,"%s",guest_now->name) !=1)
			WARN;
		printf("����%8s\n",guest_now->name);
		if(fscanf(fp,"%d",&guest_now->call_number)!=1)
			WARN;
		printf("�绰����%2d\n",guest_now->call_number);
		if(fscanf(fp,"%d %d %d",&guest_now->last_call[0],&guest_now->last_call[1],&guest_now->last_call[2]) !=3)
			WARN;
		printf("�ϴ�ͨ��ʱ��%4d��%2d��%2d��\n",guest_now->last_call[0],guest_now->last_call[1],guest_now->last_call[2]);
		if(fscanf(fp,"%d %d %d",&guest_now->order[0],&guest_now->order[1],&guest_now->order[2])!=3)
			WARN;
		for(i=0;i<3;i++){
			if(guest_now->order[i]!=0)
				printf("���������Դ%d:%d\n",i+1,guest_now->order[i]);
		}
		putchar('\n');
	}
	
	//��ȡsold
	
	sold_estate *sold_now=psold;
	if((fp=fopen("sold.txt","r"))==NULL){
		fprintf(stderr,"Error:���ļ�sold.txtʧ��\n");
		exit(-1);
	}
	if(sold_now!=NULL)while(sold_now->next!=NULL)sold_now=sold_now->next;
	while(fscanf(fp,"%s",buffer)==1){
		if(!strcmp(buffer,"sold")){
			sold_now=newnode_sold(sold_now);
		}
		else{
			puts("fail on sold");
			WARN;
		}
		if(fscanf(fp,"%d",&sold_now->size)!=1)
			WARN;
		printf("���%2d\n",sold_now->size);
		if(fscanf(fp,"%d",&sold_now->price)!=1)
			WARN;
		printf("�۸�%2d\n",sold_now->price);
		if(fscanf(fp,"%d %d %d",&sold_now->time[0],&sold_now->time[1],&sold_now->time[2]) !=3)
			WARN;
		printf("�ɽ�ʱ��%4d��%2d��%2d��\n",sold_now->time[0],sold_now->time[1],sold_now->time[2]);
		if(fscanf(fp,"%d",&sold_now->id)!=1)
			WARN;
		printf("��ͬ����%2d\n",sold_now->id);
		if(fscanf(fp,"%s",sold_now->name)!=1)
			WARN;
		printf("����%s\n",sold_now->name);
		if(fscanf(fp,"%s",sold_now->p_number)!=1)
			WARN;
		printf("�绰%9s\n",sold_now->p_number);
		putchar('\n');
	}
	
	fclose(fp);
	puts("\n��ȡ�ɹ�\n") ;
}


void save(){
	int i=0;
	FILE *fp;
	
	//����source 
	
	if((fp=fopen("source.txt","w"))==NULL){
		fprintf(stderr,"Error:���ļ�ʧ��\n");
		exit(-1);
	}
	estate *now=pestate;
	if(now!=NULL){
		fprintf(fp,"estate %d %d %d %d ",now->id,now->sold,now->direction,now->f_level);
		fprintf(fp,"%d %d %s\n",now->size,now->price,now->infor);
		while(now->next!=NULL){
			now=now->next;
			fprintf(fp,"estate %d %d %d %d ",now->id,now->sold,now->direction,now->f_level);
			fprintf(fp,"%d %d %s\n",now->size,now->price,now->infor);
		}
	}
	fclose(fp);
	
	//����guest
	
	if((fp=fopen("guests.txt","w"))==NULL){
		fprintf(stderr,"Error:���ļ�ʧ��\n");
		exit(-1);
	}
	guest *guest_now=pguest;
	if(guest_now!=NULL){
		fprintf(fp,"guest %s %s %d ",guest_now->p_number,guest_now->name,guest_now->call_number);
		fprintf(fp,"%d %d %d ",guest_now->last_call[0],guest_now->last_call[1],guest_now->last_call[2]);
		fprintf(fp,"%d %d %d\n",guest_now->order[0],guest_now->order[1],guest_now->order[2]);
		while(guest_now->next!=NULL){
			guest_now=guest_now->next;
			fprintf(fp,"guest %s %s %d ",guest_now->p_number,guest_now->name,guest_now->call_number);
			fprintf(fp,"%d %d %d ",guest_now->last_call[0],guest_now->last_call[1],guest_now->last_call[2]);
			fprintf(fp,"%d %d %d\n",guest_now->order[0],guest_now->order[1],guest_now->order[2]);
		}
	}
	fclose(fp);
	
	//����sold 
	
	if((fp=fopen("sold.txt","w"))==NULL){
		fprintf(stderr,"Error:���ļ�ʧ��\n");
		exit(-1);
	}
	sold_estate *sold_now=psold;
	if(sold_now!=NULL){
		fprintf(fp,"sold %d %d %d %d %d ",sold_now->size,sold_now->price,sold_now->time[0],sold_now->time[1],sold_now->time[2]);
		fprintf(fp,"%d %s %s\n",sold_now->id,sold_now->name,sold_now->p_number);
		while(sold_now->next!=NULL){
			sold_now=sold_now->next;
			fprintf(fp,"sold %d %d %d %d %d ",sold_now->size,sold_now->price,sold_now->time[0],sold_now->time[1],sold_now->time[2]);
			fprintf(fp,"%d %s %s\n",sold_now->id,sold_now->name,sold_now->p_number);
			
		}
	}
	fclose(fp);
	
	puts("\n����ɹ�\n");
}



void Auto_save_change(){
	if(Auto_save_mode==true){
		Auto_save_mode=false;
	}
	else Auto_save_mode=true;
}
	
