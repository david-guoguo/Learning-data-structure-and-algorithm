#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
	int key;
}SEQLIST;

/* --------------------------------------------------- */
/* 改进的顺序查找                                      */
/* 如果查找命中，则将查找到的元素前移一位              */
/* 参数：SEQLIST *r 查找的顺序表					   */
/* int n 元素个数		   							   */
/* int key 需要查找的key值		   					   */				
/* 返回值：int 超找到的元素下标                        */
/* ----------------------------------------------------*/
int SeqSearch1(SEQLIST *r,int n,int key)
{
	int i=1;
	SEQLIST temp;
	while(r[i].key!=key)
		i++;
	if((i>1) && (i<n+1))
	{
		temp=r[i];
		r[i]=r[i-1];
		r[i-1]=temp;
	}
	return i;
}

/* --------------------------------------------------- */
/* 主程序                                              */
/* --------------------------------------------------- */
main()
{
	SEQLIST a[MAXSIZE];
	int n,k,i;
	printf("输入待查元素个数：");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个元素：", i);
		scanf("%d" ,&a[i].key);
	}
	
	while(1)
	{
		printf("输入待查元素关键字：");
		scanf("%d",&k);
		i=SeqSearch1(a,n,k);
		if (i>n)
			printf("表中待查元素不存在\n");
		else
			printf("表中待查元素的位置%d\n",i);
	}
}
