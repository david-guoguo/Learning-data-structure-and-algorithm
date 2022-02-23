#include <stdlib.h>
#include <stdio.h>

/* --------------------------------------------------- */
/* Shell排序算法									   */
/* 参数：int *list 需要排序的数组		   			   */			
/* int index 需要排序的元素个数						   */		
/* 返回值：空                                          */
/* ----------------------------------------------------*/
void  ShellSort(int *list, int  index)
{
	int j,k;
	int change;                /*记录数值是否有交换位置*/
	int temp;                  /*于数值交换时的暂存变量*/
	int length;                /*分割集合的间隔长度*/
	int process;               /*进行处理的位置*/
	
	length=index / 2;          /*初始集合间隔长度*/
	
	while ( length != 0)       /*数值列仍可进行分割*/
	{
		/*对各个集合进行处理*/
		for ( j = length; j < index ; j++)
		{   
			change=0;
			temp=list[j];         /*暂存list[j]的值,待交换值时用*/
			process=j - length;   /*计算进行处理的位置*/
			
			/*进行集合内数值的比较与交换值*/
			while (temp < list[process] &&  process >= 0 &&  j <= index)
			{   
				list[process+length]=list[process];
				/*计算下一个欲进行处理的位置*/
				process=process-length;   
				change=1;
			}
			
			list[process+length]=temp;	/*与最后的数值交换*/
			
			
			if (change !=0) 
			{
				/***************打印目前排序结果****************/                 
				printf("\n Current sorting result:");
				for (k=0;k<index;k++)
				{  
					printf("%d ",list[k]);
				}
			}
		}
		length=length / 2;				/*计算下次分割的间隔长度*/
	}
}

/*------------------------------------------------------------*/
/* 主程序: 输入数值数据,进行Shell排序,打印排序结果		  	  */
/*------------------------------------------------------------*/
void main( )
{
	int list[20];                   /*设置数组最大长度为20*/
	int node;                       /*读入输入值所使用的暂存变量*/
	int i,index;
	
	printf("\n Please input the number you want to sort(Exit by 0):\n");
	
	index=0;
	
	/*--------------------读取数值存到数组中----------------------*/
	scanf("%d", &node);				/*读输入值存到变量node*/
	while (node != 0 )              /*数列尚未结束*/
	{
		list[index]=node;
		index=index+1;
		scanf("%d",&node);
	}
	
	/****************进行谢耳排序*****************/
	ShellSort(list,index);
	
	/*------------------打印最终的排序结果------------------*/
	printf("\n Final sorting result:");
	for (i=0;i<index;i++)
	{  
		printf("%d ",list[i]);
	}
}
