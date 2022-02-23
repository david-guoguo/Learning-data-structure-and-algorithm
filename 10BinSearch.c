#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

#define Max	11
/* 查找的线性表 */
int	Data[Max] = {2,13,18,25,46,55,58,61,67,69,92};	

int Counter = 1;		/* 计数器 */


/* ----------------------------------------------------*/
/* 二分查找法                                          */
/* 参数：int key 需要查找的key值		   			   */				
/* 返回值：int 查找是否成功                            */
/* ----------------------------------------------------*/
int	BinarySearch(int Key)
{
	int	left;		/* 左边界变量 */
	int	right;		/* 右边界变量 */
	int	mid;		/* 中位数变量 */

	left = 0;
	right = Max - 1;

	while ( left <= right )
	{
		mid = ( left + right ) / 2;
		if ( Key < Data[mid] )			/* 欲查找值较小 */
			right = mid - 1;			/* 查找前半段	*/
		else if ( Key > Data[mid] )		/* 欲查找值较大 */
			left = mid + 1;				/* 查找后半段	*/
		else if ( Key == Data[mid] )	/* 查找到数据	*/
		{
			printf ("Data[%d] = %d\n",mid,Data[mid]);
			return SUCCESS;
		}
		Counter++;
	}
	return FAILURE;
}

/* ---------------------------------------------------*/
/* 主程序                                             */
/* ---------------------------------------------------*/
void main ()
{
	int	KeyValue;								/* 欲查找数据变量 */
	
	printf("Please enter your key value : ");
	scanf("%d",&KeyValue);

	if ( BinarySearch(KeyValue) )
		printf("Search Time = %d\n",Counter);	/* 输出查找次数 */
	else
		printf("No Found!!\n");					/* 输出没有找到数据 */
}
