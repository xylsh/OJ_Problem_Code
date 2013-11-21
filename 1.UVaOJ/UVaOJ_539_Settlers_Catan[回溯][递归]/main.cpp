#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

/*
 * 用回溯法/图的深度优先遍历。
 * 依次以每一个结点为起点，
 * 从起点出发，依次遍历该结点的每一条边。
 * 遍历到一个结点时，只要下一条边未走过，就一直走下去，
 * 直到走到不能再走了为止，这条path的长度与目前保存的最大长度比较，如果更大，就保存为目前的最大长度。
 */

int edge[MAX][MAX];  /* 边数组。0:无边；1:有边且未访问过；2:有边且访问过 */
int max_road;
int n,m;

/* 图的深度优先搜索 */
void dfs(int curr,int num){     /* curr表示当前结点编号 */
    int i;

    for(i=0; i<n; i++){         /* 遍历curr结点的所有边 */
        if( edge[curr][i] == 1 ){
            edge[curr][i] = edge[i][curr] = 2;      /* 标志该边已访问过 */
            dfs(i,num+1);
            edge[curr][i] = edge[i][curr] = 1;      /* 假设不走这条边（走该结点的下一条边） */
        }
    }

    if( num > max_road )
        max_road = num;

}
int main(){
    int i;
    while( scanf("%d %d",&n,&m) == 2 && n != 0 ){  
        /* initial */
        max_road = 0;
        memset(edge,0,sizeof(edge));

        int a,b;
        for(i=0; i<m; i++){
            scanf("%d %d",&a,&b);
            edge[a][b] = edge[b][a] = 1;    /* 建立边数组 */
        }

        /* 依次以每一个结点为起点 */
        for(i=0; i<n; i++){
            dfs(i,0);
        }

        printf("%d\n",max_road);

    }
    return 0;
}
