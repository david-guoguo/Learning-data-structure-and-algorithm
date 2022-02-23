#include <stdio.h> 

#define MAXSIZE 100

typedef struct 
{
	char ch[MAXSIZE];
	int length;				/* 字符串的实际长度 */
}SString;

/* --------------------------------------------------- */
/* 获取字符串s中的单词数，以空格分隔		 		   */
/* 参数：SString *s 需要求单词数的字符串			   */
/* 返回值：int 单词数	                       		   */
/* ----------------------------------------------------*/
int getWordNum(SString s)
{
	char prec=' ';			/* 前一个字符 */
	char c;					/* 当前字符 */
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
