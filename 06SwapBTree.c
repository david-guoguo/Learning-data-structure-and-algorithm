#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 20

struct Tree								/*�������Ľṹ*/
{
	struct  Tree *left;                 /*�����������ָ��*/
	int data;                           /*��Žڵ���������*/
	struct Tree *right;                 /*�����������ָ��*/
};
typedef struct Tree TreeNode;			/*�������������ṹ*/
typedef TreeNode *BTree;				/*����������������*/

/*----------------------------------------------------*/
/* ����������Ľڵ�									  */
/* ������BTree root ������               	      	  */
/* int node Ҫ����Ľ��							  */
/* ����ֵ��BTree ������ɺ�Ķ�����					  */
/*----------------------------------------------------*/
BTree InsertNode(BTree root, int node)
{
    BTree newnode;                        /*��������ָ��*/
    BTree currentnode;                    /*����Ŀǰ�ڵ�ָ��*/
    BTree parentnode;                     /*�������ڵ�ָ��*/
	
    /*�����½ڵ���ڴ�ռ�*/
    newnode=(BTree) malloc (sizeof(TreeNode));
	
    newnode->data =node;                   /*����ڵ�����*/
    newnode->right=NULL;                   /*������ָ���ֵ*/
    newnode->left=NULL;                    /*������ָ���ֵ*/
	
    if (root == NULL)
        return newnode;                    /*�����½ڵ��λ��*/
    else
    {
        currentnode=root;                  /*�洢Ŀǰ�ڵ�ָ��*/
        while ( currentnode !=NULL)
        {
			parentnode=currentnode;			/*�洢���ڵ�ָ��*/
			if (currentnode->data  > node)	/*�ȽϽڵ����ֵ��С*/
				currentnode=currentnode->left; /*������*/
			else
				currentnode=currentnode->right; /*������*/
        }
        if (parentnode->data > node)		/*�����ڵ���ӽڵ�������*/
			parentnode->left = newnode;		/*�ӽڵ�Ϊ���ڵ��������*/
        else
			parentnode->right= newnode;		/*�ӽڵ�Ϊ���ڵ��������*/
    }
    return root;		                  
}
/*----------------------------------------------------*/
/* ����������                                         */
/* ������int *data ���ڴ���������������               */
/* int len Ԫ�ظ���									  */
/* ����ֵ��BTree ������ɺ�Ķ�����					  */
/*----------------------------------------------------*/
BTree CreateBTree(int *data,int len)
{
	BTree root=NULL;                      /*���ڵ�ָ��*/
	int i;
	
	for (i=0; i <len; i++)	             /*������״�ṹ*/
		root=InsertNode(root,data[i]);
	return root;
}

/*----------------------------------------------------*/
/* ���ж�����ӳ��                                     */
/* ������BTree root ������               	      	  */
/* ����ֵ��BTree ӳ����ɺ�Ķ�����					  */
/*----------------------------------------------------*/
BTree SwapBTree(BTree root)
{
	BTree swaptree;	                       /*����ӳ���ָ��*/
	
	if (root!=NULL)
	{
		swaptree=(BTree) malloc (sizeof (TreeNode));
		swaptree->data=root->data;
		swaptree->left=SwapBTree(root->right);  /*��������������*/
		swaptree->right=SwapBTree(root->left);  /*��������������*/
		return swaptree;
	}
	else
		return NULL;
}


/* --------------------------------------------------- */
/* �������������	  								   */
/* ������BTree point ������                 		   */
/* ����ֵ����										   */
/* ----------------------------------------------------*/
void inOrder(BTree point)
{
	if (point!=NULL)				/*��������ֹ����*/
	{
		inOrder(point->left);		/*����������*/
		printf("%d ",point->data);	/*�����ӡ�ڵ�����*/
		inOrder(point->right);		/*����������*/
	}
}

/*---------------------------------------------------------*/
/* ������:����������,����ӳ���������������������ڵ�����  */
/*---------------------------------------------------------*/
void main( )
{
	BTree root=NULL;                /* ԭ���ڵ�ָ�� */
	BTree root2=NULL;
	
	int index;
	int value;	                    /* ��������ֵ��ʹ�õ��ݴ���� */
	int nodelist[MAXSIZE];			/* �����洢��������֮���� */
	
	
	printf("\n �����������Ԫ�أ���0������:\n");
	index=0;
	
	/*-----------��ȡ��ֵ�浽������-----------*/
	scanf("%d", &value);          /* ��ȡ����ֵ�浽����value�� */
	
	while (value != 0 )           /* ����ȡ��δ���� */
	{
		nodelist[index]= value;
	index=index+1;
	scanf("%d",&value);
	}
	
	/*------------------����������------------------*/
	root=CreateBTree(nodelist,index);
	printf(" \nThe inOrder traversal of original tree is [ ");
	inOrder(root);
	printf("]\n");
	
	/*-------------------����ӳ��--------------------*/
	root2=SwapBTree(root);
	printf(" \nThe inOrder traversal of swaping tree is [ ");
	inOrder(root2);
	printf(")\n");
}
