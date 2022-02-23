#include <stdlib.h>
#include <stdio.h>

/* --------------------------------------------------- */
/* Shell�����㷨									   */
/* ������int *list ��Ҫ���������		   			   */			
/* int index ��Ҫ�����Ԫ�ظ���						   */		
/* ����ֵ����                                          */
/* ----------------------------------------------------*/
void  ShellSort(int *list, int  index)
{
	int j,k;
	int change;                /*��¼��ֵ�Ƿ��н���λ��*/
	int temp;                  /*����ֵ����ʱ���ݴ����*/
	int length;                /*�ָ�ϵļ������*/
	int process;               /*���д����λ��*/
	
	length=index / 2;          /*��ʼ���ϼ������*/
	
	while ( length != 0)       /*��ֵ���Կɽ��зָ�*/
	{
		/*�Ը������Ͻ��д���*/
		for ( j = length; j < index ; j++)
		{   
			change=0;
			temp=list[j];         /*�ݴ�list[j]��ֵ,������ֵʱ��*/
			process=j - length;   /*������д����λ��*/
			
			/*���м�������ֵ�ıȽ��뽻��ֵ*/
			while (temp < list[process] &&  process >= 0 &&  j <= index)
			{   
				list[process+length]=list[process];
				/*������һ�������д����λ��*/
				process=process-length;   
				change=1;
			}
			
			list[process+length]=temp;	/*��������ֵ����*/
			
			
			if (change !=0) 
			{
				/***************��ӡĿǰ������****************/                 
				printf("\n Current sorting result:");
				for (k=0;k<index;k++)
				{  
					printf("%d ",list[k]);
				}
			}
		}
		length=length / 2;				/*�����´ηָ�ļ������*/
	}
}

/*------------------------------------------------------------*/
/* ������: ������ֵ����,����Shell����,��ӡ������		  	  */
/*------------------------------------------------------------*/
void main( )
{
	int list[20];                   /*����������󳤶�Ϊ20*/
	int node;                       /*��������ֵ��ʹ�õ��ݴ����*/
	int i,index;
	
	printf("\n Please input the number you want to sort(Exit by 0):\n");
	
	index=0;
	
	/*--------------------��ȡ��ֵ�浽������----------------------*/
	scanf("%d", &node);				/*������ֵ�浽����node*/
	while (node != 0 )              /*������δ����*/
	{
		list[index]=node;
		index=index+1;
		scanf("%d",&node);
	}
	
	/****************����л������*****************/
	ShellSort(list,index);
	
	/*------------------��ӡ���յ�������------------------*/
	printf("\n Final sorting result:");
	for (i=0;i<index;i++)
	{  
		printf("%d ",list[i]);
	}
}
