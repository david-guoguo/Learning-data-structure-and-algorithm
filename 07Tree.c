#include <stdio.h>
#include <stdlib.h>

#define dep 3			/* �������Ķ� */
#define STACKMAXSIZE 10	/* �����ڽ������Ĵ洢�ṹʱ��ջ�ռ��С */
#define QUEUEMAXSIZE 10	/* ���������İ�������㷨�еĶ��пռ��С */

typedef char ElemtType;	/* ElemtType���͸���ʵ������������������Ϊchar */

struct GTreeNode{
    ElemtType data;
    struct GTreeNode *t[dep];
    struct GTreeNode *parent;
};

/* --------------------------------------------------- */
/* ������										   	   */
/* ������struct GTreeNode* *gt ��ָ��				   */
/* char *a ��������ַ���							   */
/* ����ֵ����                                          */
/* ----------------------------------------------------*/
void CreateTree(struct GTreeNode* *gt, char *a)
{
	/* ����s��Ϊ�洢���н��ָ���ջʹ�� */    
    struct GTreeNode *s[STACKMAXSIZE];	

	/* ����d��Ϊ�洢���ӽ�����ӵ�˫�׽��ָ��������ջʹ�� */
    int d[STACKMAXSIZE];	
    int top = -1;		/* top��Ϊ����ջ��ջ��ָ�룬��ֵΪ-1��ʾջ�� */
    struct GTreeNode *p;/* ����pΪָ��������ָ�� */
    int i = 0, j;		/* iָʾɨ���ַ���a�еĵ�ǰ�ַ�λ�� */
    *gt = NULL;			/* ��ʼ������ָ���ÿ� */
    
    while(a[i] != '\0'){  /* ÿ��ѭ������һ���ַ���ֱ���ַ�������Ϊֹ */
        switch(a[i]){
            /* �Կո������� */
		case ' ':    
			break;

            /* ����������ʱ����pָ���sջ������dջ��������ɨ��ĺ���
			��㽫�����ӵ�sջ��Ԫ����ָ���ĵ�һ��ָ����*/
		case '(':
			top++;
			s[top] = p;
			d[top] = 0;
			break;

            /* ����������ʱ����s��d��ջ */
		case ')':
			top--;
			break;

			/* ������ʱ���ô�����ĺ��ӵĽ�����ӵ�sջ��Ԫ����ָ���
			����һ��ָ����*/
		case ',':
			d[top]++;
			break;

            /* �����ַ�Ԫ�� */
		default:
			/* ����a[i]�ַ������½�� */
			p = malloc(sizeof(struct GTreeNode));
			p->data = a[i];
			for(j = 0; j < dep; j++)
			{/* ��dep��ʾ������� */
				p->t[j] = NULL;        
			}
			
			if(NULL == *gt   )
			{
				*gt = p;        /* ʹ���p��Ϊ���� */
			}
			else
			{
				s[top]->t[d[top]] = p;/* ���ӵ�˫�׽���Ӧ��ָ���� */ 
			}
			break;
		}    
		i++;	/* ׼��������һ���ַ� */
	}
    return;
}

/* --------------------------------------------------- */
/* �����в���ֵΪx�Ľ��Ԫ��						   */
/* ������struct GTreeNode *gt �������ָ��             */
/* ElemtType x ��Ҫ���ҵ�Ԫ��ֵ						   */
/* ����ֵ��ElemtType *								   */
/* �������򷵻�Ԫ�ش洢��ַ�����򷵻�NULL			   */
/* ----------------------------------------------------*/
ElemtType *findTree(struct GTreeNode *gt, ElemtType x)
{
    /* �������򷵻�NULL */
    if(gt == NULL){
        return NULL;
	}else{
		ElemtType *p;
        int i;
        /* �����ҳɹ����ؽ��ֵ��ĵ�ַ */
        if(gt->data == x){
            return &(gt->data);
		}
        /* ��ÿ�������������ң����صõ���ֵ���ַ */
        for(i = 0; i < dep; i++){
            if(p = findTree(gt->t[i], x)){
                return p;
			}
		}
        return NULL;        /* ���Ҳ��ɹ�����NULL */
	}
}

/* --------------------------------------------------- */
/* ���������									   	   */
/* ������struct GTreeNode *gt �������ָ��             */
/* ����ֵ��int �����                              	   */
/* ----------------------------------------------------*/
int TreeDepth(struct GTreeNode *gt)
{
    int i, max;
    /* ���������Ϊ0 */
    if(gt == NULL){
        return 0;
	}
    /* ��ǿ�������ȣ�max�ĳ�ֵΪ0 */
	max = 0;
    for(i = 0; i < dep; i++){
        int d = TreeDepth(gt->t[i]);/* �����һ����������Ȳ���ֵ��d */
        if(d > max){
			max = d;
		}
	}
    return max + 1;        /* ���طǿ�������ȣ������ڸ������������ȼ�1 */
}

/* --------------------------------------------------- */
/* ����������н�㣬ʹ֮��Ϊһ�ÿ���  				   */
/* ������struct GTreeNode* *gt �������ָ��            */
/* ����ֵ����										   */
/* ----------------------------------------------------*/
void clearTree(struct GTreeNode* *gt)
{
    if(*gt != NULL){
        int i;
        for(i = 0; i < dep; i++){
			clearTree(&((*gt)->t[i]));
		}
		free(*gt);
        *gt = NULL;
	}
    return;
}

/* --------------------------------------------------- */
/* �ȸ�������	  								   	   */
/* ������struct GTreeNode *gt �������ָ��             */
/* ����ֵ����										   */
/* ----------------------------------------------------*/
void preRoot(struct GTreeNode *gt)
{
    int i;
    if(gt != NULL){
		printf("%c ", gt->data);	/* ���ʸ���� */
        for(i = 0; i < dep; i++){
			preRoot(gt->t[i]);		/* �ݹ����ÿһ������ */
		}
	}
    return;
}

/* --------------------------------------------------- */
/* ���������	  								   	   */
/* ������struct GTreeNode *gt �������ָ��             */
/* ����ֵ����										   */
/* ----------------------------------------------------*/
void postRoot(struct GTreeNode *gt)
{
    int i;
    if(gt != NULL){
        for(i = 0; i < dep; i++){
			postRoot(gt->t[i]);	/* �ݹ����ÿһ������ */
		}
		printf("%c ", gt->data);	/* ���ʸ���� */
	}
	
}

/* --------------------------------------------------- */
/* ���������	  								  	   */
/* ������struct GTreeNode *gt �������ָ��             */
/* ����ֵ����										   */
/* ----------------------------------------------------*/
void levelOrder(struct GTreeNode *gt)
{
    struct GTreeNode *p;
    int i;
    struct GTreeNode *q[QUEUEMAXSIZE];    /* �����õ�����q����Ÿ���� */
    int front = 0, rear = 0;
    /* ��������������ָ����� */
    if(gt != NULL){
		rear = (rear + 1 % QUEUEMAXSIZE);
		q[rear] = gt;
	}
    /* �����зǿ�ʱִ��ѭ�� */
    while(front != rear){
		front = (front + 1) % QUEUEMAXSIZE;        /*  */
        /* ɾ������Ԫ�أ��������Ԫ����ָ����ֵ */
		p = q[front];
		printf("%c ", p->data);
        /* �ǿյĺ��ӽ���ָ�����ν��� */
        for(i = 0; i < dep; i++){
            if(p->t[i] != NULL){
				rear = (rear + 1) % QUEUEMAXSIZE;
				q[rear] = p->t[i];
			}
		}
	}
    return;
}

/* --------------------------------------------------- */
/* ��ӡ��������  							   		   */
/* ������struct GTreeNode *gt �������             	   */
/* ����ֵ����										   */
/* ----------------------------------------------------*/
void printTree(struct GTreeNode *gt)
{
    if(gt != NULL){
        int i;
		printf("%c", gt->data);
        /* �ж�gt����Ƿ��к��� */
        for(i = 0; i < dep; i++){
            if(gt->t[i] != NULL){
                break;
			}
		}
        /* �к���ʱ��ִ���������������µݹ���� */
        if(i < dep){
			printf("(");
			printTree(gt->t[0]);        /* �����һ������ */
            /* �������������� */
            for(i = 1; i < dep; i++){
				printf(",");
				printTree(gt->t[i]);
			}
			printf(")");
		}
	}
    return;
}

/* ---------------------------------------------------*/
/* ���������ڲ���ʵ�ֵĻ�����������			      */
/* ---------------------------------------------------*/
int main()
{
    char ch;
    struct GTreeNode *gt = NULL;
    char b[50];	/* ���ڴ���k�����������ַ����� */
	
	printf("����һ��%d�����Ĺ�����ַ����� ", dep);
	scanf("%s", b); /* ���� a (b,c (d,e,f)) */
	
	CreateTree(&gt, b);
	printf("�ȸ�������");
	preRoot(gt);
	printf(" ");

	printf("���������");
	postRoot(gt);
	printf(" ");

	printf("���������");
	levelOrder(gt);
	printf(" ");

	printf("����������ʽ�����");
	printTree(gt);
	printf(" ");

	printf("�������Ϊ��%d ", TreeDepth(gt));
	printf("��������ҵ��ַ���");
	scanf(" %c", &ch);

    if(findTree(gt, ch)){
		printf("���ҳɹ��� ");
	}else{
		printf("����ʧ�ܣ� ");
	}

	clearTree(&gt);
    return 0;
}
