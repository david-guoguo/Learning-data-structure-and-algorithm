#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 9
#define KEYTYPE int

typedef struct
{
	KEYTYPE key;
}RECORDNODE;

/* --------------------------------------------------- */
/* 插入排序算法									   	   */
/* 参数：RECORDNODE r[] 需要排序的记录集合			   */
/* int n 需要排序的元素个数						   	   */
/* 返回值：空                                          */
/* ----------------------------------------------------*/
void insertSort(RECORDNODE r[], int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		r[0]=r[i];           
		j=i-1;		/*j表示前面排好序序列的最后一个元素的位置*/
		while(r[0].key<r[j].key)	/*确定插入位置*/
		{
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=r[0];				/*元素插入*/
	}
}

/* ---------------------------------------------------*/
/* 主程序				      						  */
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
