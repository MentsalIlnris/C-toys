#include<stdio.h>
#include<string.h>
#define CSIZE 3
#define YEARS 2

struct stu_name {
	char first[5];
	char last[5];
};


struct student {
	struct stu_name name;
	float grade[YEARS];
	float score;
};

void scan(struct student target[CSIZE]);
void print (struct student target[CSIZE]);


int main () {
	int i=0,k=0;
	struct student stu[CSIZE];
	scan(stu);
	print(stu);
	return 0;
}

void scan(struct student target[CSIZE]){
	int i=0,k=0;float sum=0;
	printf("������%dλѧ����������%d��ÿ��ĳɼ�\n",CSIZE,YEARS);
	for(i=0;i<CSIZE;i++){
		scanf("%s %s",target[i].name.first,target[i].name.last);
		for(k=0,sum=0;k<YEARS;k++){
			scanf("%f",&target[i].grade[k]);
			sum+=target[i].grade[k];
		}
		target[i].score=sum/YEARS;
	}
}


void print (struct student target[CSIZE]){
		int i=0,k=0,sum=0;
	for(i=0;i<CSIZE;i++){
		printf("ѧ��%s %s\n",target[i].name.first,target[i].name.last);
		for(k=0,sum=0;k<YEARS;k++){
			scanf("��%d��ɼ�Ϊ%f\n",i,target[i].grade[k]);
		}
		printf("��ƽ������Ϊ%f\n",target[i].score);
	}
}

