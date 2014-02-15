#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAX 110

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1226
 * 1.动态规划类题目，使用记忆化搜索。
 * 2.dp[r][c]表示从点(r,c)出发的最大路径长度。
 * 3.依次以每个点为起点，找出路径长度最大的点。
 * 4.对DP还不熟练，参考了http://blog.csdn.net/cc_again/article/details/8618700
 */

int area[MAX][MAX];     //地图
int R,C;
int dp[MAX][MAX];
char name[MAX];

//移动的向量
const int dx[4] = { -1,1,0, 0 };
const int dy[4] = {  0,0,1,-1 };

//深度优先遍历
int dfs(int r,int c){  
    if( dp[r][c] > 0 )          //如果已经计算过
        return dp[r][c];
    
    int m = 0;
    for(int i=0; i<4; i++){  
        int dr = r + dx[i];  int dc = c + dy[i];    //向4个方向移动
        if(dr>=0 && dr<R && dc>=0 && dc<C && area[r][c]>area[dr][dc]){    //如果可以走
            if( dp[dr][dc] > 0 )             //本来不判断直接调用m = max(m,dfs(dr,dc));也是可以的，
                m = max(m,dp[dr][dc]);       //但是增加的函数调用开销反而使程序比判断时更慢了。下同.
            else
                m = max(m,dfs(dr,dc));
        }
    }

    dp[r][c] = m+1;         //格子自己要算一步
    return dp[r][c];
}

int main(){
    int tcase,i,j;
    scanf("%d", &tcase);
    while( tcase-- ){  
        //get input
        scanf("%s %d %d", name, &R, &C);
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
                scanf("%d", &area[i][j]);

        //initial
        memset(dp, 0, sizeof(dp));
        
        int ans = 0;
        for(i=0; i<R; i++)
            for(j=0; j<C; j++){  
                if( dp[i][j] == 0 )
                    ans = max(ans, dfs(i,j));
                else
                    ans = max(ans, dp[i][j]);
            }
        
        printf("%s: %d\n",name,ans);

    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
