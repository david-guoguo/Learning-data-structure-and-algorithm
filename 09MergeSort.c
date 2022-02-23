#include <stdlib.h>
#include <stdio.h>

/* ---------------------------------------------------            */
/* 合并2个已排序好的数值数组						   */
/* 参数：											   */
/* int *source, int *distination 需要合并的两个数组	   */			
/* int left, int middle 需要合并的元素下标			   */
/* int n 元素个数									   */		
/* 返回值：空                                          */
/* ----------------------------------------------------*/
void MergeTwo (int *source, int *distination, int left, int middle, int n) 
{
	int  i,j,k,t;
	
	i=left; k=left; j=middle+1;			/*设置数组指针*/
	
	/*两个欲合并的数组均还有值尚未处理*/
	while ( (i<=middle) && (j<=n) ) 
	{
		if (source[i]<=source[j] )		/*将较小者先存到输出数组destination*/
		{
			distination[k]=source[i];
			i++;
		}
		else
		{
			distination[k]=source[j];
			j++;
		}
		k ++;
	}
	
	/*将尚未处理完的数组数值依序存入输出数组distination中*/
	if  ( i > middle )
	{
		for ( t=j ; t<=n; t++ )
			distination[k+t-j]=source[t];
	}
	else
	{
		for ( t=i ;t<=middle; t++ )
			distination[k+t-i]=source[t];
	}
}

/* --------------------------------------------------- */
/* 将所有partition array 分别两两合并				   */
/* 参数：											   */
/* int *source, int *distination 需要合并的两个数组	   */			
/* int n 元素个数									   */
/* int length 初始合并的长度						   */	
/* 返回值：空                                          */
/* ----------------------------------------------------*/
void  MergeAll (int *source, int *distination, int n,int length)
{
    int i,t;
	i=0;
	while  ( i<= (n-2*length+1)) /*还有两段长度为length的list可合并*/
	{
		MergeTwo(source,distination,i,i+length-1,i+2*length-1);
		i= i + 2*length;
	}
	
	if  ( i+length -1 < n )
	{
		/*合并两段list,一段长度为length,另一段长度不足length*/
		MergeTwo(source,distination,i,i+length-1,n);
	}
	else
	{
		/*将剩下一段不足length长的list中的值依序存到输出数组distination*/
		for (t=i; t<=n; t++)
			distination[t]=source[t];
	}
	
	/* 将distination中的值复制到source */
	for (t=0; t<=n; t++)
		source[t]=distination[t];
	
	/* 打印目前排序结果 */
	printf(" Current sorting result: ");
	for (i=0; i<=n; i++)
		printf("%d ",distination[i]);
	printf("\n");
}


/*--------------------------------------------------------------*/
/* 主程序: 输入数值数据,进行合并排序,打印排序结果               */
/*--------------------------------------------------------------*/
void main( )
{
	int list1[20],list2[20];	/*设置数组最大长度为20*/
	int node;					/*读入输入值所使用的暂存变量*/
	int length;					/*记录合并数组的长度*/
	int count;					/*记录整个数值数组的总个数*/
	int i ,index ;
	
	printf("\n Please input the number you want to sort(Exit by 0):\n");
	
	index=0;
	
	/*************读取数值存入数组中**************/
	scanf("%d", &node);			/*读输入值存到变量node*/
	while (node != 0 )			/*数列尚未结束*/
	{
		list1[index]=node;
		index=index+1;
		scanf("%d",&node);
	}
	
	/**************清除数组list2[]为0*************/
	for (i=0; i <= 19; i++)
		list2[i]=0;
	
	printf("\nSource values:");
	for (i=0; i<index; i++)
		printf("%d ",list1[i]);
	printf("\n\n");
	
	
	/******************进行合并排序*********************/
	length=1;					/*设置初始合并的长度*/
	count=index-1;
	
	while (length < index )		/*合并尚未结束*/
	{
		printf("*Merge length=%d \n",length);
		/* 将所有list两两合并 */
		MergeAll ( list1, list2, count, length);	
		length=2*length;		/* 将length变成两倍 */
		if (length < index)
		{
			printf("*Merge length=%d \n",length);
			MergeAll ( list2, list1, count, length);
			length=2*length;
		}
	}
	
	/*****************打印最终排序结果******************/
	printf("\n Final sorting result:");
	for (i=0; i<index; i++)
		printf("%d ",list1[i]);
	printf("\n");
}
