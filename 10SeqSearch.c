#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

/* ���ҵ����Ա� */
int	Data[20] = {  12,  76,  29,  22,  15,
				  62,  29,  58,  35,  67,
				  58,  33,  28,  89,  90,
				  28,  64,  48,  20,  77};	
int	Counter = 1;

/* --------------------------------------------------- */
/* ˳�����                                            */
/* ������int key ��Ҫ���ҵ�keyֵ		   			   */				
/* ����ֵ��int �����Ƿ�ɹ�                            */
/* ----------------------------------------------------*/
int	SeqSearch (int Key)
{
	int	Index = 0;		                /* �������� */

	while ( Index < 20 )
	{
		if ( Key == Data[Index] )		/* ���ҵ�����ʱ */
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
/* ������                                              */
/* --------------------------------------------------- */
void main ()
{
	int	KeyValue;								/* ���������ݱ��� */

	printf("Please enter your key value : ");
	scanf("%d",&KeyValue);

	if ( SeqSearch (KeyValue) )
		printf("Search Time = %d\n",Counter);	/* ������Ҵ��� */
	else
		printf("No Found!!\n");					/* ���û���ҵ����� */
}
