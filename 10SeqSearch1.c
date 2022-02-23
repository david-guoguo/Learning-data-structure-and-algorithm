#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
	int key;
}SEQLIST;

/* --------------------------------------------------- */
/* �Ľ���˳�����                                      */
/* ����������У��򽫲��ҵ���Ԫ��ǰ��һλ              */
/* ������SEQLIST *r ���ҵ�˳���					   */
/* int n Ԫ�ظ���		   							   */
/* int key ��Ҫ���ҵ�keyֵ		   					   */				
/* ����ֵ��int ���ҵ���Ԫ���±�                        */
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
/* ������                                              */
/* --------------------------------------------------- */
main()
{
	SEQLIST a[MAXSIZE];
	int n,k,i;
	printf("�������Ԫ�ظ�����");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("�����%d��Ԫ�أ�", i);
		scanf("%d" ,&a[i].key);
	}
	
	while(1)
	{
		printf("�������Ԫ�عؼ��֣�");
		scanf("%d",&k);
		i=SeqSearch1(a,n,k);
		if (i>n)
			printf("���д���Ԫ�ز�����\n");
		else
			printf("���д���Ԫ�ص�λ��%d\n",i);
	}
}
