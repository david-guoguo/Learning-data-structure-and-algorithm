#include <stdio.h> 

#define MAXSIZE 100

typedef struct 
{
	char ch[MAXSIZE];
	int length;				/* �ַ�����ʵ�ʳ��� */
}SString;

/* --------------------------------------------------- */
/* ��ȡ�ַ���s�еĵ��������Կո�ָ�		 		   */
/* ������SString *s ��Ҫ�󵥴������ַ���			   */
/* ����ֵ��int ������	                       		   */
/* ----------------------------------------------------*/
int getWordNum(SString s)
{
	char prec=' ';			/* ǰһ���ַ� */
	char c;					/* ��ǰ�ַ� */
	int num=0;
	int i;
	for(i=0; (c=s.ch[i])!= '\0' ;i++)
	{
		if((c!=' ')&&(prec==' '))
			num++;
		prec=c;
	}
	return num;
}

main()
{
	SString s={"I am a student.",15};
	int wordCount=getWordNum(s);
	printf("word num= %d\n",wordCount);
}
