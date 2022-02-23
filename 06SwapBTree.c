#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 20

struct Tree								/*声明树的结构*/
{
	struct  Tree *left;                 /*存放左子树的指针*/
	int data;                           /*存放节点数据内容*/
	struct Tree *right;                 /*存放右子树的指针*/
};
typedef struct Tree TreeNode;			/*声明新类型树结构*/
typedef TreeNode *BTree;				/*声明二叉树的链表*/

/*----------------------------------------------------*/
/* 插入二叉树的节点									  */
/* 参数：BTree root 二叉树               	      	  */
/* int node 要插入的结点							  */
/* 返回值：BTree 插入完成后的二叉树					  */
/*----------------------------------------------------*/
BTree InsertNode(BTree root, int node)
{
    BTree newnode;                        /*声明树根指针*/
    BTree currentnode;                    /*声明目前节点指针*/
    BTree parentnode;                     /*声明父节点指针*/
	
    /*建立新节点的内存空间*/
    newnode=(BTree) malloc (sizeof(TreeNode));
	
    newnode->data =node;                   /*存入节点内容*/
    newnode->right=NULL;                   /*设置右指针初值*/
    newnode->left=NULL;                    /*设置左指针初值*/
	
    if (root == NULL)
        return newnode;                    /*返回新节点的位置*/
    else
    {
        currentnode=root;                  /*存储目前节点指针*/
        while ( currentnode !=NULL)
        {
			parentnode=currentnode;			/*存储父节点指针*/
			if (currentnode->data  > node)	/*比较节点的数值大小*/
				currentnode=currentnode->left; /*左子树*/
			else
				currentnode=currentnode->right; /*右子树*/
        }
        if (parentnode->data > node)		/*将父节点和子节点做连结*/
			parentnode->left = newnode;		/*子节点为父节点的左子树*/
        else
			parentnode->right= newnode;		/*子节点为父节点的右子树*/
    }
    return root;		                  
}
/*----------------------------------------------------*/
/* 创建二叉树                                         */
/* 参数：int *data 用于创建二叉树的数组               */
/* int len 元素个数									  */
/* 返回值：BTree 创建完成后的二叉树					  */
/*----------------------------------------------------*/
BTree CreateBTree(int *data,int len)
{
	BTree root=NULL;                      /*根节点指针*/
	int i;
	
	for (i=0; i <len; i++)	             /*建立树状结构*/
		root=InsertNode(root,data[i]);
	return root;
}

/*----------------------------------------------------*/
/* 进行二叉树映像                                     */
/* 参数：BTree root 二叉树               	      	  */
/* 返回值：BTree 映像完成后的二叉树					  */
/*----------------------------------------------------*/
BTree SwapBTree(BTree root)
{
	BTree swaptree;	                       /*进行映像的指针*/
	
	if (root!=NULL)
	{
		swaptree=(BTree) malloc (sizeof (TreeNode));
		swaptree->data=root->data;
		swaptree->left=SwapBTree(root->right);  /*右子树变左子树*/
		swaptree->right=SwapBTree(root->left);  /*左子树变右子树*/
		return swaptree;
	}
	else
		return NULL;
}


/* --------------------------------------------------- */
/* 中序遍历二叉树	  								   */
/* 参数：BTree point 二叉树                 		   */
/* 返回值：空										   */
/* ----------------------------------------------------*/
void inOrder(BTree point)
{
	if (point!=NULL)				/*遍历的终止条件*/
	{
		inOrder(point->left);		/*处理左子树*/
		printf("%d ",point->data);	/*处理打印节点内容*/
		inOrder(point->right);		/*处理右子树*/
	}
}

/*---------------------------------------------------------*/
/* 主程序:建立二叉树,进行映像以中序遍历输出二叉树节点内容  */
/*---------------------------------------------------------*/
void main( )
{
	BTree root=NULL;                /* 原根节点指针 */
	BTree root2=NULL;
	
	int index;
	int value;	                    /* 读入输入值所使用的暂存变量 */
	int nodelist[MAXSIZE];			/* 声明存储输入数据之数组 */
	
	
	printf("\n 请输入二叉树元素（以0结束）:\n");
	index=0;
	
	/*-----------读取数值存到数组中-----------*/
	scanf("%d", &value);          /* 读取输入值存到变量value中 */
	
	while (value != 0 )           /* 若读取尚未结束 */
	{
		nodelist[index]= value;
	index=index+1;
	scanf("%d",&value);
	}
	
	/*------------------建立二叉树------------------*/
	root=CreateBTree(nodelist,index);
	printf(" \nThe inOrder traversal of original tree is [ ");
	inOrder(root);
	printf("]\n");
	
	/*-------------------进行映像--------------------*/
	root2=SwapBTree(root);
	printf(" \nThe inOrder traversal of swaping tree is [ ");
	inOrder(root2);
	printf(")\n");
}
