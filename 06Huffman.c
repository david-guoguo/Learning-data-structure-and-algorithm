#include <stdio.h>

#define MAXSIZE 100

/* ������������Ľ��ṹ */
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
/* ����Huffman��									   */
/* ������int n Huffman��������					   */
/* ����ֵ��HuffmanNode ���������ĸ����                */
/* ----------------------------------------------------*/
HuffmanNode *CreateHuffmanTree(int n)
{
	int m,i,j,count=0;
	Forest treeData[MAXSIZE];	/* ��������treeData����Ѱ����С������Ȩֵ */
	HuffmanNode *p,*q,*p1,*p2;
	for(i=1;i<=n;i++)			/* ����n������Ȩֵ */
	{
		printf("�����%d������Ȩֵ��", i);
		scanf("%d",&m);

		/* ��̬����������ڴ� */
		p=(HuffmanNode *)malloc(sizeof(HuffmanNode));	

		p->weight=m;
		p->lchild=NULL;
		p->rchild=NULL;
		treeData[i].weight=m;
		treeData[i].link=p;
		count++;		
	}
	
	/* ������treeData��Ȩֵ��С�������� */
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
				/* ȡ������СȨֵ */
				p1=treeData[1].link;p2=treeData[2].link;
				/* �����µĽ�� */
				q=(HuffmanNode *)malloc(sizeof(HuffmanNode));	
				/* �½���ȨֵΪ������СȨֵ�ĺ� */
				q->weight=p1->weight+p2->weight;	
				q->lchild=p1;q->rchild=p2;
				
				/*��������ɾ��������СȨֵ���������*/
				for(i=3;i<=count;i++){  
					treeData[i-2]=treeData[i];    
				}
				count=count-2;	/* ������Ԫ�ظ�����2 */
				i=1;

				while(treeData[i].weight<=q->weight && i<=count)
					i++;

				/*�������ɵĽ����뵽�����У�Ѱ�Ҳ���λ��*/
				for(j=count;j>=i;j--)     /*�����µĽ��*/
					treeData[j+1]=treeData[j];
				treeData[i].weight=q->weight;
				treeData[i].link=q;
				count++;
			}
			return treeData[1].link ;	/*���ػ��������ĸ�����ַ*/
}

/* --------------------------------------------------- */
/* ��������������� 								   */
/* ������HuffmanNode *t ������ͷ���				   */
/* ����ֵ����										   */
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
/* ������		                 					  */
/* ---------------------------------------------------*/
main()
{
	HuffmanNode *hmTree;
	int n;
	printf("������Huffman����������");
	scanf("%d",&n);
	
	hmTree=CreateHuffmanTree(n);
	InOrder(hmTree);
}
