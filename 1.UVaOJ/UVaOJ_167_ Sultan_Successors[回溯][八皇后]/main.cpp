#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

/*
 * 这是一道八皇后问题，用回溯法解决。
 * 1.每行放一个皇后，则皇后之间一定不会出现行冲突。
 * 2.依次尝试当前皇后放在所在行的第0列到第7列，一旦发现不冲突的列，则递归放下一个皇后。
 */

int board[MAX][MAX];
int queue[MAX];      /* 下标代表第几个皇后(也代表第几行)，值表示该行皇后放在第几列 */
int max_score;

/* 对解答树深度优先搜索 */
void dfs(int curr,int score){
    int i,j;
    if( curr == 8 ){   /* 递归边界 */  
        if( score > max_score )
            max_score = score;
    }else
        for(i=0; i<8; i++){
            queue[curr] = i;    /* 当前皇后如果放在第i列 */
            int ok = 1;
            for(j=0; j<curr; j++){
                if( queue[j] == queue[curr]                     /* 检查同列是否冲突 */
                        || curr-queue[curr] == j-queue[j]       /* 检查主对角线是否冲突 */
                        || curr+queue[curr] == j+queue[j] ){    /* 检查副对角线是否冲突 */
                    ok = 0;
                    break;
                }
            }
            if( ok )  dfs(curr+1,score+board[curr][i]);
        }
}

int main(){
    int k,a,i,j;
    scanf("%d",&k);
    for(a=0; a<k; a++){
        /* initial */
        max_score = 0;
        memset(board,0,sizeof(board));
        memset(queue,-1,sizeof(queue));

        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                scanf("%d",&board[i][j]);
            }
        }

        dfs(0,0);

        printf("%5d\n",max_score);
    }

    return 0;
}
