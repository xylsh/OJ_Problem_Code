#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define MAX_VERTEX 220
#define MAX_Edge 5000
using namespace std;

/*
 * 用图的深度优先遍历遍历每一个结点，
 * 如果下一个结点未被访问过，则标记上与当前结点不同的颜色，
 * 如果下一个结点被访问过，则判断当前结点与下一个结点的颜色是否相同，相同则NOT BICOLORABLE.
 */

/* 用邻接矩阵存储图 */
int arc[MAX_Edge][MAX_Edge];     /* 边数组,-1表示无边,1表示有边 */
int vertex[MAX_VERTEX];   /* 结点数组,0表示未访问过，1表示颜色1,2表示颜色2 */
int n,bicolorable;

void dfs(int k,int color){   /* k表示第k个结点(从0开始计算) */  
    vertex[k] = color;
    int i;
    for(i=0; i<n; i++)
        if( arc[k][i] == 1 ){        /* 如果结点k与结点i有边 */
            if( vertex[i] == 0 ){    /* 如果结点i未被访问过 */
                if( vertex[k] == 1 )  dfs(i,2);
                else if( vertex[k] == 2 )  dfs(i,1);
            }else{                   /* 如果结点i被访问过 */
                if( vertex[k] == vertex[i] ) 
                    bicolorable = 0;
            }
        }
}

int main(){
    int l,a,b,i;
    scanf("%d",&n);
    while( n != 0){
        scanf("%d",&l);
        /* initial */
        bicolorable = 1;    /* 默认为真 */
        memset(vertex,0,sizeof(vertex));
        memset(arc,-1,sizeof(arc));

        /* get input */
        for(i=0; i<l; i++){
            scanf("%d %d",&a,&b);
            arc[a][b] = arc[b][a] = 1;
        }
        /* process */
        for(i=0; i<n; i++){
            if( vertex[i] == 0 )
                dfs(i,1);
        }
        /* output */
        printf("%s\n",bicolorable?"BICOLORABLE.":"NOT BICOLORABLE.");

        scanf("%d",&n);
    }
    
    return 0;
}

