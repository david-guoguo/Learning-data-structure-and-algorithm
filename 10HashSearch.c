#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE	8
#define HashMax 5

/* 查找的数据数组 */
int Data[MAXSIZE] = { 1, 13, 20, 5, 12, 32, 59, 92};

struct List						/* 声明列表结构 */
{
	int		Key;				/* 键值 */
	struct  List	*Next;		/* 下一个节点 */
};
typedef struct List Node;
typedef Node *LinkNode;

Node	HashTab[HashMax];		/* 哈希表 */
int 	Counter = 1;			/* 查找次数计数器 */

/* ---------------------------------------------------*/
/* 哈希函数构造中采用除留余数法                       */
/* 参数：int key 关键字		   		  				  */				
/* 返回值：int 键值除以哈希表大小取余数               */
/* ---------------------------------------------------*/
int HashMod(int Key)
{
	return Key % HashMax ;	
}

/* ---------------------------------------------------*/
/* 将关键字插入哈希表                                 */
/* 参数：int key 关键字		   		  				  */				
/* 返回值：空										  */
/* ---------------------------------------------------*/
void InsertHash(int Key)
{
	LinkNode Pointer;					/* 列表指针 */
	LinkNode New;						/* 新列表指针 */
	int	Index;							/* 哈希索引 */
	
	New = ( LinkNode ) malloc(sizeof(Node));/* 内存分配 */
	New->Key = Key;						
	New->Next = NULL;					/* 指向结束指针 */
	
	Index = HashMod(Key);				/* 取得数据位置 */
	Pointer = HashTab[Index].Next;		/* 哈希表起始指针 */
	if ( Pointer != NULL )				/* 指针没指向结束指针时 */
	{
		New->Next = Pointer;			/* 指向上一个指针 */
		HashTab[Index].Next = New;		/* 哈希表指针指向此新指针 */
	}
	else
	{
		HashTab[Index].Next = New;		/* 哈希表指针指向此新指针 */
	}
}

/* ---------------------------------------------------*/
/* 哈希查找法                                         */
/* 参数：int key 关键字		   		  				  */				
/* 返回值：int 是否查找成功							  */
/* ---------------------------------------------------*/
int HashSearch(int Key)
{
	LinkNode Pointer;				/* 列表指针 */
	int	Index;						/* 哈希索引 */
	
	Counter = 0;
	Index = HashMod(Key);			/* 取得数据位置 */
	Pointer = HashTab[Index].Next;	/* 哈希表起始指针 */
	printf("Data[%d] : ",Index);
	
	while ( Pointer != NULL )		/* 指针指向结束指针时终止循环 */
	{
		Counter++;
		printf("[%d]",Pointer->Key);
		if ( Pointer->Key == Key )	/* 查找到数据 */
			return SUCCESS;
		else						/* 往下一个指针查找 */
			Pointer = Pointer->Next;/* 指向下一个指针 */
	}
	return FAILURE;
}

/* ---------------------------------------------------*/
/* 主程序                                             */
/* ---------------------------------------------------*/
void main ()
{
	int		KeyValue;				/* 欲查找数据变量 */
	int		Index;					/* 输入数据索引 */
	LinkNode    Pointer;
	int i;
	
	Index = 0;
	
	printf("查找的数据数组 : ");		
	for ( i=0;i<MAXSIZE;i++ )
		printf("[%d]",Data[i]);
	printf("\n");
	
	while ( Index < MAXSIZE )		/* 建立哈希表 */
	{
		InsertHash(Data[Index]);
		Index++;
	}
	
	for ( i=0;i<HashMax;i++ )		/* 输出哈希表数据 */
	{
		printf("HashTab[%d] : ",i);
		Pointer = HashTab[i].Next;
		while ( Pointer != NULL )
		{
			if ( Pointer->Key > 0 )
				printf("[%d]",Pointer->Key);
			Pointer = Pointer->Next;
		}
		printf("\n");
	}
	
	while ( KeyValue != -1 )		/* 输入-1结束程序 */
	{
		printf("请输入需要查找的值 : ");
		scanf("%d",&KeyValue);
		
		if ( HashSearch(KeyValue) )
			printf("\n查找次数 = %d\n",Counter);/* 输出查找次数 */
		else
			printf("\nNo Found!!\n");	/* 输出没有找到数据 */
	}
}
