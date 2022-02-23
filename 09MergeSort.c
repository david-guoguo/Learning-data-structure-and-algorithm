#include <stdlib.h>
#include <stdio.h>

/* ---------------------------------------------------            */
/* �ϲ�2��������õ���ֵ����						   */
/* ������											   */
/* int *source, int *distination ��Ҫ�ϲ�����������	   */			
/* int left, int middle ��Ҫ�ϲ���Ԫ���±�			   */
/* int n Ԫ�ظ���									   */		
/* ����ֵ����                                          */
/* ----------------------------------------------------*/
void MergeTwo (int *source, int *distination, int left, int middle, int n) 
{
	int  i,j,k,t;
	
	i=left; k=left; j=middle+1;			/*��������ָ��*/
	
	/*�������ϲ������������ֵ��δ����*/
	while ( (i<=middle) && (j<=n) ) 
	{
		if (source[i]<=source[j] )		/*����С���ȴ浽�������destination*/
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
	
	/*����δ�������������ֵ��������������distination��*/
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
/* ������partition array �ֱ������ϲ�				   */
/* ������											   */
/* int *source, int *distination ��Ҫ�ϲ�����������	   */			
/* int n Ԫ�ظ���									   */
/* int length ��ʼ�ϲ��ĳ���						   */	
/* ����ֵ����                                          */
/* ----------------------------------------------------*/
void  MergeAll (int *source, int *distination, int n,int length)
{
    int i,t;
	i=0;
	while  ( i<= (n-2*length+1)) /*�������γ���Ϊlength��list�ɺϲ�*/
	{
		MergeTwo(source,distination,i,i+length-1,i+2*length-1);
		i= i + 2*length;
	}
	
	if  ( i+length -1 < n )
	{
		/*�ϲ�����list,һ�γ���Ϊlength,��һ�γ��Ȳ���length*/
		MergeTwo(source,distination,i,i+length-1,n);
	}
	else
	{
		/*��ʣ��һ�β���length����list�е�ֵ����浽�������distination*/
		for (t=i; t<=n; t++)
			distination[t]=source[t];
	}
	
	/* ��distination�е�ֵ���Ƶ�source */
	for (t=0; t<=n; t++)
		source[t]=distination[t];
	
	/* ��ӡĿǰ������ */
	printf(" Current sorting result: ");
	for (i=0; i<=n; i++)
		printf("%d ",distination[i]);
	printf("\n");
}


/*--------------------------------------------------------------*/
/* ������: ������ֵ����,���кϲ�����,��ӡ������               */
/*--------------------------------------------------------------*/
void main( )
{
	int list1[20],list2[20];	/*����������󳤶�Ϊ20*/
	int node;					/*��������ֵ��ʹ�õ��ݴ����*/
	int length;					/*��¼�ϲ�����ĳ���*/
	int count;					/*��¼������ֵ������ܸ���*/
	int i ,index ;
	
	printf("\n Please input the number you want to sort(Exit by 0):\n");
	
	index=0;
	
	/*************��ȡ��ֵ����������**************/
	scanf("%d", &node);			/*������ֵ�浽����node*/
	while (node != 0 )			/*������δ����*/
	{
		list1[index]=node;
		index=index+1;
		scanf("%d",&node);
	}
	
	/**************�������list2[]Ϊ0*************/
	for (i=0; i <= 19; i++)
		list2[i]=0;
	
	printf("\nSource values:");
	for (i=0; i<index; i++)
		printf("%d ",list1[i]);
	printf("\n\n");
	
	
	/******************���кϲ�����*********************/
	length=1;					/*���ó�ʼ�ϲ��ĳ���*/
	count=index-1;
	
	while (length < index )		/*�ϲ���δ����*/
	{
		printf("*Merge length=%d \n",length);
		/* ������list�����ϲ� */
		MergeAll ( list1, list2, count, length);	
		length=2*length;		/* ��length������� */
		if (length < index)
		{
			printf("*Merge length=%d \n",length);
			MergeAll ( list2, list1, count, length);
			length=2*length;
		}
	}
	
	/*****************��ӡ����������******************/
	printf("\n Final sorting result:");
	for (i=0; i<index; i++)
		printf("%d ",list1[i]);
	printf("\n");
}
