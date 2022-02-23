#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 9
#define KEYTYPE int

typedef struct
{
	KEYTYPE key;
}RECORDNODE;

/* --------------------------------------------------- */
/* ���������㷨									   	   */
/* ������RECORDNODE r[] ��Ҫ����ļ�¼����			   */
/* int n ��Ҫ�����Ԫ�ظ���						   	   */
/* ����ֵ����                                          */
/* ----------------------------------------------------*/
void insertSort(RECORDNODE r[], int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		r[0]=r[i];           
		j=i-1;		/*j��ʾǰ���ź������е����һ��Ԫ�ص�λ��*/
		while(r[0].key<r[j].key)	/*ȷ������λ��*/
		{
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=r[0];				/*Ԫ�ز���*/
	}
}

/* ---------------------------------------------------*/
/* ������				      						  */
/* ---------------------------------------------------*/
main()
{
	RECORDNODE r[MAXSIZE];
	int i;

	printf("Please input the number you want to sort:\n");
	for(i=1;i<=MAXSIZE-1;i++)
		scanf("%d",&r[i]);
	insertSort(r,MAXSIZE-1);
	
	for(i=1;i<=MAXSIZE-1;i++)
		printf("%d,",r[i]);
	printf("\n");
	
}
