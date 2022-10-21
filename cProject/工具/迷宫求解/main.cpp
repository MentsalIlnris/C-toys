#include<stdio.h>
#include "head.h"

#define MAXLEN 50


int main()
{
 int BF(sstring S, sstring T, int pos);
 int KMP(sstring S, sstring T, int pos);
 sstring S;
 sstring T;
 int num1, num2;
 printf("����������");
 Initsstring(S);
 printf("������Ϊ��");
 printfsstring(S);
 printf("�������Ӵ�\n");
 Initsstring(T);
 printf("���Ӵ�Ϊ��");
 printfsstring(T);
 num1 = BF(S, T, 1);
 num2 = KMP(S, T, 1);
 if ((num1 == 0) || (num2 == 0))
  printf("�������Ҳ����ִ�");
 else if (num1 > num2)
  printf("BF�㷨Ч�ʵ���KMP�㷨");
 else
  printf("KMP�㷨Ч�ʵ���BF�㷨");
 return 0;
}


int BF(sstring S, sstring T, int pos)
{
 int i, j,count=0;
 i = pos;
 j = 1;
 while (i <= S.length && j <= T.length)
 {
  if (S.a[i] == T.a[j])
  {
   i++;
   j++;
   count++;//�Ƚϴ���
  }
  else
  {
   i = i - j + 2;
   j = 1;
  }
 }
 if (i > T.length)
  return count;
 else
  return 0;
}//BF


void getnext(sstring T, int next[])
{
 int i, j;
 i = 1;
 j = 0;
 next[1] = 0;
 while (i < T.length)
 {
  if (i == 0 || T.a[i] == T.a[j])
  {
   i++;
   j++;
   next[i] = j;
  }
  else
   j = next[j];
 }
}//�������next



int KMP(sstring S, sstring T, int pos)
{
 int i, j, num=0;
 int next[MAXLEN];
 i = pos;
 j = 1;
 getnext(T, next);
 while (i <= S.length && j <= T.length)
 {
  if (j == 0 || S.a[i] == T.a[j]) 
  {
   i++;
   j++;
   num++;
  }
  else
  {
   j = next[j];
  }
 }
 if (j > T.length)
  return num;
 else
  return 0;
}//KMP


