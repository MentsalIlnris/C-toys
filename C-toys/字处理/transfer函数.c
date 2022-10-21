#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int string_to_int(char *p);
char *int_to_string(int number);

void transfer(double src[],double tar[],int n,double (*func)(double));
int bstoi(char *st);
char *itobs(int n);

int switch_count(int n);
int get_bit(int n,int pos);
int rotate_l(int n,int lenth);

long myatol (char *s); 


int main(int argc,char *argv[]){
	printf("%d\n",string_to_int("517771"));
	printf("%s\n",itobs(2147483644));
	printf("%d",bstoi("01001001"));
	return 0;
}

int string_to_int(char *p){
	//���ַ���ת��Ϊint���� 
	char ch='0';int i = 0,ret = 0;
	while(ch = *(p+i)){
		if(ch=='\0')break;
		//printf("������%d���ַ���\n",i+1);
		if(!isdigit(ch)){
			printf("error\n");
			return 0;
		}
		ret = ret*10 + (int)(ch-'0');
		i++;
	}
	printf("ret=%d\n",ret);
	return ret;
} 

char *int_to_string(int number){
	//��int����ת��Ϊ�ַ��� 
	int i = 1,buf = number,digit;char *ret;
	for(digit=1;buf>10;digit++){
		buf=buf/10;
	}
	//digit��¼Ŀ��������λ�� 
	//printf("%d",digit);
	ret=malloc((digit+1)*sizeof(char));
	ret[digit]='\0';
	while(i<=digit){
		ret[digit-i]=(char)(number%10+'0');
		number/=10;
		i++;
	}
	return ret;
}


void transfer(double src[],double tar[],int n,double (*func)(double)){
	//��Ŀ�������ÿһ��Ԫ������ͬһ������ 
	int i;
	for(i = 0;i < n;++i){
		tar[i]=func(src[i]);
	}
} 


int bstoi(char *st){
	//��������ת����int���� 
	int sum = 0;
	while(*st!= '\0'){
		sum <<= 1;
//		if(*st != '0' && *st != '1'){
//			printf("The argument should be a binary.\n");
//			exit(EXIT_FAILURE);
//		}
		sum += *st++ - '0';
	}
	//*2�൱����λ <<=1
	return sum;
}


char *itobs(int n){
	//int����ת���ɶ����� 
	const static int size = CHAR_BIT * sizeof(int);
	char *ps=malloc(size);
	int i;
	for(i = size-1 ;i >= 0; i-- ,n >>= 1){
		ps[i] = (01 & n) + '0';
	}
	ps[size] = '\0';
	return ps;
}


int switch_count(int n){
	//��¼Ŀ�����������1�ĸ��� 
	const static int size = CHAR_BIT * sizeof(int);
	int sum = 0,i;
	for(i = 0;i < size;i++){
		if(n & 1)  sum++;
		n >>= 1;
	}
	return sum;
}


int get_bit(int n,int pos){
	//��ȡĿ����n��posλ���ϵĴ洢 
	const static int size = CHAR_BIT * sizeof(int);
	if (pos > size || pos < 0){
		printf("Error position.\n");
		return(-1);
	}//����Ĳ���pos���벻�����жϷ�Χ 
	if(1 & (n>>pos))
		return 1;
	else return 0;
}


int rotate_l(int n,int length){
	//�������ƶ� 
	const static int size = CHAR_BIT * sizeof(int);
	int i;
	if(length > size || length < 0){
		printf("Error length.\n");
		return 0;
	}//����Ĳ���length���벻����������Χ
	for(i = 0; i < length; i++){
		if(n&(1<<(size - 1))){
			n<<=1;
			n |=1;
		}else{
			n<<=1;
		}
	}
	return n;
}

long myatol (char *s){
	long r = 0;
	int neg = 0;
	switch(*s){
	case '-':
		neg = 1;
		//�˴���break
	case '+':
		s++;
		break;
	}  
	while(*s >= '0' && *s <= '9'){
		int n = *s++ - '0';
		if(neg)
			n=-n;
		r = r * 10 + n;
	}
	return r;
}

