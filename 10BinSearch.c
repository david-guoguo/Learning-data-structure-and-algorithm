#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

#define Max	11
/* ���ҵ����Ա� */
int	Data[Max] = {2,13,18,25,46,55,58,61,67,69,92};	

int Counter = 1;		/* ������ */


/* ----------------------------------------------------*/
/* ���ֲ��ҷ�                                          */
/* ������int key ��Ҫ���ҵ�keyֵ		   			   */				
/* ����ֵ��int �����Ƿ�ɹ�                            */
/* ----------------------------------------------------*/
int	BinarySearch(int Key)
{
	int	left;		/* ��߽���� */
	int	right;		/* �ұ߽���� */
	int	mid;		/* ��λ������ */

	left = 0;
	right = Max - 1;

	while ( left <= right )
	{
		mid = ( left + right ) / 2;
		if ( Key < Data[mid] )			/* ������ֵ��С */
			right = mid - 1;			/* ����ǰ���	*/
		else if ( Key > Data[mid] )		/* ������ֵ�ϴ� */
			left = mid + 1;				/* ���Һ���	*/
		else if ( Key == Data[mid] )	/* ���ҵ�����	*/
		{
			printf ("Data[%d] = %d\n",mid,Data[mid]);
			return SUCCESS;
		}
		Counter++;
	}
	return FAILURE;
}

/* ---------------------------------------------------*/
/* ������                                             */
/* ---------------------------------------------------*/
void main ()
{
	int	KeyValue;								/* ���������ݱ��� */
	
	printf("Please enter your key value : ");
	scanf("%d",&KeyValue);

	if ( BinarySearch(KeyValue) )
		printf("Search Time = %d\n",Counter);	/* ������Ҵ��� */
	else
		printf("No Found!!\n");					/* ���û���ҵ����� */
}
