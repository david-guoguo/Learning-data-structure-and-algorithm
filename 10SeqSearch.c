#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

/* 查找的线性表 */
int	Data[20] = {  12,  76,  29,  22,  15,
				  62,  29,  58,  35,  67,
				  58,  33,  28,  89,  90,
				  28,  64,  48,  20,  77};	
int	Counter = 1;

/* --------------------------------------------------- */
/* 顺序查找                                            */
/* 参数：int key 需要查找的key值		   			   */				
/* 返回值：int 查找是否成功                            */
/* ----------------------------------------------------*/
int	SeqSearch (int Key)
{
	int	Index = 0;		                /* 计数变量 */

	while ( Index < 20 )
	{
		if ( Key == Data[Index] )		/* 查找到数据时 */
		{
			printf("Data[%d] = %d \n",Index,Key);
			return SUCCESS;
		}
		Index++;
		Counter++;
	}
	return FAILURE;
}

/* --------------------------------------------------- */
/* 主程序                                              */
/* --------------------------------------------------- */
void main ()
{
	int	KeyValue;								/* 欲查找数据变量 */

	printf("Please enter your key value : ");
	scanf("%d",&KeyValue);

	if ( SeqSearch (KeyValue) )
		printf("Search Time = %d\n",Counter);	/* 输出查找次数 */
	else
		printf("No Found!!\n");					/* 输出没有找到数据 */
}
