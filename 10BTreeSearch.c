#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE	10

/* 数据数组 */
int	Data[MAXSIZE] = {
	16,  1, 13,  5,  17,
	25, 37,  7,  3,  99};   
int Counter;			/* 计数器 */

/* 声明树状结构 */
struct Tree			               
{
	int		Key;				/* 数据变量 */
	struct	Tree	*Left;		/* 左子树指针 */
	struct	Tree	*Right;		/* 右子树指针 */
};
typedef struct Tree TreeNode;
typedef TreeNode *BTree;

BTree   Root = NULL;			/* 根部父节点 */

/* ---------------------------------------------------*/
/* 创建二叉查找树                                     */
/* 参数：int Data 用于创建二叉树的数据		   		  */				
/* 返回值：空                            			  */
/* ---------------------------------------------------*/
void CreateBTree(int *Data)
{
	BTree   New;		             /* 新指针变量 */
	BTree	Current;	             /* 目前指针 */
	BTree	Father;		             /* 父节点指针 */
	int	  	i;

	for ( i=0;i<MAXSIZE;i++ )
	{
		New = (BTree) malloc(sizeof(TreeNode));	/* 内存配置 */
		New->Key = Data[i];	/* 新指针为输入的数据 */
		New->Left = NULL;	/* 左子树节点 */
		New->Right = NULL;	/* 右子树节点 */
		if ( Root == NULL )	/* 当根节点未连结任何子树时 */
			Root = New;		/* 根节点为新节点 */
		else
		{
			Current = Root;				/* 目前的位置在根节点 */
			while ( Current != NULL )	/* 当目前的节点为最底端则结束循环 */
			{
				Father = Current;				/* 记录父节点 */

				/* 目前节点数据大于或等于输入数据 */
				if ( Current->Key >= Data[i] ) 	
					Current = Current->Left; 	/* 往左子树 */
				else	/* 目前节点数据小于输入数据 */
					Current = Current->Right;	/* 往右子树 */
			}
			if ( Father->Key > Data[i] )		/* 串连父与子节点 */
				Father->Left = New;
			else
				Father->Right = New;
		}
	}
}

/* ---------------------------------------------------*/
/* 二叉查找树                                         */
/* 参数：int key 需要查找的key值		   			  */				
/* 返回值：int 查找是否成功                           */
/* ---------------------------------------------------*/
int BTreeSearch(int Key)
{
	BTree	Pointer;
	Pointer = Root;		/* 查找节点为根节点 */
	Counter = 0;

	while ( Pointer != NULL )
	{
		Counter++;
		/* 查找节点的数据小于欲查找数据 */
		if ( Pointer->Key < Key )	
			Pointer = Pointer->Right;	/* 往右子树 */
		/* 查找节点的数据大于欲查找数据 */
		else if ( Pointer->Key > Key )
			Pointer = Pointer->Left;	/* 往左子树 */
		/* 查找节点的数据等于欲查找数据 */
		else if ( Pointer->Key == Key )
			return SUCCESS;				/* 找到数据 */
	}

	return FAILURE;	/* 未能查找到数据 */
}

/* ---------------------------------------------------*/
/* 主程序                                             */
/* ---------------------------------------------------*/
void main ()
{
	int KeyValue;						/* 欲查找数据变量 */
	int i;

	printf("Search Data : ");	          
	for ( i=0;i<MAXSIZE;i++ )
		printf("[%d]",Data[i]);
	printf("\n");

	Root = NULL;
	CreateBTree(Data);					/* 调用建立二叉查找树 */

	while ( KeyValue != -1 )			/* 输入-1结束程序 */
	{
	printf("Please enter your key value : ");
	scanf("%d",&KeyValue);

	if ( BTreeSearch(KeyValue) )
		printf("Search Time = %d\n",Counter);	/* 输出查找次数 */
	else
		printf("Data No Found!!\n");	/* 输出没有找到数据 */
	}
}
