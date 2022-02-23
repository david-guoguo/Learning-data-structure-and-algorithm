#include <stdlib.h>
#include <stdio.h>

/* --------------------------------------------------- */
/* �������򷨵ĵݹ鴦��								   */
/* ������int *list ��Ҫ���������		   			   */			
/* int left, int right ��Ҫ�����Ԫ�������±�		   */
/* int index ��Ҫ�����Ԫ�ظ���						   */		
/* ����ֵ����                                          */
/* ----------------------------------------------------*/
void QuickSort(int *list, int left, int right, int index)
{
	int i,j,k;
	int pivot;     /* ��ָ�� */
	int temp;      /* ����ֵ����ʱ���ݴ���� */
	
	i=left; j=right+1;		/*����i , j�ֱ�Ϊ���������ָ��*/
	pivot=list[left];		/*ȡ����ߵ�Ԫ��*/
	
	if  ( i < j )
	{
		do
		{   /*���������ұ�pivot���ֵ*/
			do                        
			{
				i ++;
			} while (list[i] <= pivot && i <= right);
			
			/*���������ұ�pivotС��ֵ*/
			do                        
			{
				j--;
			} while (list[j] >= pivot && j > left);
			
			if ( i < j )	/*����list[i] . list[j]��ֵ*/
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
		
		temp=list[left];	/*����list[left] . list[j]��ֵ*/
		list[left]=list[j];
		list[j]=temp;
		
		/*------------------��ӡĿǰ��������------------------*/       
		printf("\n #Current sorting result:");
		for (k=0;k<index;k++)
		{  printf("%d ",list[k]);
		}
		
		QuickSort( list , left , j-1,index);	/*��������*/
		QuickSort( list , j+1, right,index);	/*�����Ұ��*/
	}
}


/*----------------------------------------------------------*/
/* ������:������ֵ����,���п�������,��ӡ������			*/
/*----------------------------------------------------------*/
void main( )
{
	int list[20];		/*����������󳤶�Ϊ20*/
	int node;			/*��������ֵ��ʹ�õ��ݴ����*/
	int i,index;
	
	printf("\n Please input the number you want to sort(Exit by 0):\n");
	
	index=0;
	
	/*--------------------��ȡ��ֵ�浽������----------------------*/
	scanf("%d", &node);	/*������ֵ�浽����node*/
	while (node != 0 )	/*������δ����*/
	{
		list[index]=node;
		index=index+1;
		scanf("%d",&node);
	}
	
	/*--------------------���п�������----------------------*/
	QuickSort(list,0,index-1,index);
	
	/*------------------��ӡ���յ�������------------------*/
	printf("\n Final sorting result:");
	for (i=0;i<index;i++)
	{ 
		printf("%d ",list[i]);
	}
}