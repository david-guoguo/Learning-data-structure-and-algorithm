#include <stdlib.h>
#include <stdio.h>

/* --------------------------------------------------- */
/* 快速排序法的递归处理								   */
/* 参数：int *list 需要排序的数组		   			   */			
/* int left, int right 需要排序的元素左右下标		   */
/* int index 需要排序的元素个数						   */		
/* 返回值：空                                          */
/* ----------------------------------------------------*/
void QuickSort(int *list, int left, int right, int index)
{
	int i,j,k;
	int pivot;     /* 轴指针 */
	int temp;      /* 于数值交换时的暂存变量 */
	
	i=left; j=right+1;		/*设置i , j分别为数组的左右指针*/
	pivot=list[left];		/*取最左边的元素*/
	
	if  ( i < j )
	{
		do
		{   /*从左往右找比pivot大的值*/
			do                        
			{
				i ++;
			} while (list[i] <= pivot && i <= right);
			
			/*从右往左找比pivot小的值*/
			do                        
			{
				j--;
			} while (list[j] >= pivot && j > left);
			
			if ( i < j )	/*交换list[i] . list[j]的值*/
			{	
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
				printf("\n *Current sorting result:");
				for (k=0;k<index;k++)
				{ printf("%d ",list[k]);
				}
			}
		}while ( i < j );
		
		temp=list[left];	/*交换list[left] . list[j]的值*/
		list[left]=list[j];
		list[j]=temp;
		
		/*------------------打印目前的排序结果------------------*/       
		printf("\n #Current sorting result:");
		for (k=0;k<index;k++)
		{  printf("%d ",list[k]);
		}
		
		QuickSort( list , left , j-1,index);	/*排序左半边*/
		QuickSort( list , j+1, right,index);	/*排序右半边*/
	}
}


/*----------------------------------------------------------*/
/* 主程序:输入数值数据,进行快速排序,打印排序结果			*/
/*----------------------------------------------------------*/
void main( )
{
	int list[20];		/*设置数组最大长度为20*/
	int node;			/*读入输入值所使用的暂存变量*/
	int i,index;
	
	printf("\n Please input the number you want to sort(Exit by 0):\n");
	
	index=0;
	
	/*--------------------读取数值存到数组中----------------------*/
	scanf("%d", &node);	/*读输入值存到变量node*/
	while (node != 0 )	/*数列尚未结束*/
	{
		list[index]=node;
		index=index+1;
		scanf("%d",&node);
	}
	
	/*--------------------进行快速排序----------------------*/
	QuickSort(list,0,index-1,index);
	
	/*------------------打印最终的排序结果------------------*/
	printf("\n Final sorting result:");
	for (i=0;i<index;i++)
	{ 
		printf("%d ",list[i]);
	}
}