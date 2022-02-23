#include <stdio.h>

#define MAXSIZE 100

/* 定义霍夫曼树的结点结构 */
typedef struct node
{
	int weight;
	struct node *lchild,*rchild;
}HuffmanNode;           

typedef struct
{
	int weight;
	HuffmanNode *link;
}Forest;

/* --------------------------------------------------- */
/* 构建Huffman树									   */
/* 参数：int n Huffman树结点个数					   */
/* 返回值：HuffmanNode 霍夫曼树的根结点                */
/* ----------------------------------------------------*/
HuffmanNode *CreateHuffmanTree(int n)
{
	int m,i,j,count=0;
	Forest treeData[MAXSIZE];	/* 辅助数组treeData用来寻找最小的两个权值 */
	HuffmanNode *p,*q,*p1,*p2;
	for(i=1;i<=n;i++)			/* 输入n个结点的权值 */
	{
		printf("输入第%d个结点的权值：", i);
		scanf("%d",&m);

		/* 动态分配树结点内存 */
		p=(HuffmanNode *)malloc(sizeof(HuffmanNode));	

		p->weight=m;
		p->lchild=NULL;
		p->rchild=NULL;
		treeData[i].weight=m;
		treeData[i].link=p;
		count++;		
	}
	
	/* 对数组treeData按权值从小到大排序 */
	for(i=1;i<count;i++)
		for(j=1;j<=count-i;j++)
			if(treeData[j].weight>treeData[j+1].weight)
			{
				treeData[0]=treeData[j];
				treeData[j]=treeData[j+1];
				treeData[j+1]=treeData[0];
			}
			while(count>1)
			{
				/* 取两个最小权值 */
				p1=treeData[1].link;p2=treeData[2].link;
				/* 生成新的结点 */
				q=(HuffmanNode *)malloc(sizeof(HuffmanNode));	
				/* 新结点的权值为两个最小权值的和 */
				q->weight=p1->weight+p2->weight;	
				q->lchild=p1;q->rchild=p2;
				
				/*从数组中删除具有最小权值的两个结点*/
				for(i=3;i<=count;i++){  
					treeData[i-2]=treeData[i];    
				}
				count=count-2;	/* 数组中元素个数减2 */
				i=1;

				while(treeData[i].weight<=q->weight && i<=count)
					i++;

				/*将新生成的结点插入到数组中，寻找插入位置*/
				for(j=count;j>=i;j--)     /*插入新的结点*/
					treeData[j+1]=treeData[j];
				treeData[i].weight=q->weight;
				treeData[i].link=q;
				count++;
			}
			return treeData[1].link ;	/*返回霍夫曼树的根结点地址*/
}

/* --------------------------------------------------- */
/* 中序遍历霍夫曼树 								   */
/* 参数：HuffmanNode *t 二叉树头结点				   */
/* 返回值：空										   */
/* ----------------------------------------------------*/
void InOrder(HuffmanNode *t)          
{
	if(t!=NULL)
	{
		InOrder(t->lchild);
		printf("%d\t",t->weight);
		InOrder(t->rchild);
	}
}

/* ---------------------------------------------------*/
/* 主程序，		                 					  */
/* ---------------------------------------------------*/
main()
{
	HuffmanNode *hmTree;
	int n;
	printf("请输入Huffman树结点个数：");
	scanf("%d",&n);
	
	hmTree=CreateHuffmanTree(n);
	InOrder(hmTree);
}
