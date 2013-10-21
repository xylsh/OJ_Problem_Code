#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10020
typedef struct Node{  
    int value;
    int sum;             /* 保存从根结点到此节点的路径长度 */
    struct Node* lchild;
    struct Node* rchild;
}Node;

int inOrder[MAX],     /* 中序遍历 */
    postOrder[MAX];   /* 后序遍历 */

/* 根据题目,单个节点value最大为10000,每条路径长度最大为10000*10000,
 * 赋值为2^30足够大了。*/
int min_sum = 1<<30,min_value = 1<<30;

/* 重建二叉树（前提：节点value不重复） */
/* n表示元素总数,postOrder指向postOrder数组的最后一个元素 */
Node* rebuild(int n,int* postOrder,int* inOrder,Node* node,int sum){  
    if( n <= 0) return NULL;   /* 递归终止条件 */

    int i = 0;
    while( *(inOrder+i) != *postOrder ){    /* 在中序遍历中找到根结点(后续遍历的最后一个节点) */
        i++;
    }
    /*printf("i=%d\n",i);*/

    node = (Node*)malloc(sizeof(Node));
    node->value = *(inOrder+i);
    node->sum = sum + node->value;

    node->lchild = rebuild(i, postOrder-n+i, inOrder, 
            node->lchild, node->sum);
    node->rchild = rebuild(n-i-1, postOrder-1, inOrder+i+1,
            node->rchild, node->sum);

    if( node->lchild == NULL && node->rchild == NULL ){   /* 如果是叶子节点 */
        if( node->sum < min_sum ){
            min_sum = node->sum;
            min_value = node->value;
        }else if( node->sum == min_sum ){
            if( node->value < min_value ) min_value = node->value;
        }
    }

    return node;
}

/* 前序遍历 */
void preOrder(Node* node){
    if( node == NULL ) return;   /* 递归终止条件 */

    printf("%d ",node->value);
    preOrder(node->lchild);      /* 遍历左子树 */
    preOrder(node->rchild);      /* 遍历右子树 */
}

int main(){
    int tmp,count;
    char c;
    count = 0;
    
    while( scanf("%d",&tmp) == 1 ){  
        c = getchar();
        inOrder[count++] = tmp;
        if( c == '\n' ){  
            int i;
            for(i=0; i<count; i++)
                scanf("%d",&postOrder[i]);

            Node* root = rebuild(count,postOrder+count-1,inOrder,root,0);
            /*preOrder(root);
            printf("\n");*/
            printf("%d\n",min_value);

            /* 别忘了重置 */
            count = 0;
            min_sum = min_value = 1<<30;
        }
    }

    return 0;
}
