#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAX_MUSIC 22
#define MAX_N 10000

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=565
 * 1.动态规划，01背包问题。
 * 2.需要注意的是如何打印路径。白书上的01背包问题打印路径的方法依靠了图的边，不适用于本题。
 *   打印路径参考了参考博客。
 * 3.参考了http://www.cnblogs.com/shumj/p/3425208.html
 *
 */

int N,music_amount;
int tracks[MAX_MUSIC];
int dp[MAX_MUSIC][MAX_N];     //dp[i][j]表示当前在第i首歌曲，
                              //tape剩余j分钟时，最多能存多少分钟

//rec(i,j)表示当前在第i首歌曲，tape剩余j分钟时，最多能存多少分钟
/*int rec(int i,int j){
    if( dp[i][j] >= 0 )
        return dp[i][j];

    int ans = 0;
    if( i >= music_amount ){  
        ans = 0;
    }else if( j < tracks[i] ){  
        ans = rec(i+1, j);
    }else{
        ans = max(rec(i+1, j), rec(i+1, j-tracks[i]) + tracks[i] );
    }

    return dp[i][j] = ans;
}*/

//打印路径
void path(int music,int n){  
    if( music < 0 || music >= music_amount )
        return;

    if( dp[music][n] == dp[music+1][n] ){   //如果相等证明没有使用tracks[music]
        path(music+1,n);
    }else{  
        printf("%d ",tracks[music]);
        path(music+1, n-tracks[music]);
    }
}

int main(){
    int i,j;
    while( scanf("%d %d",&N,&music_amount) == 2 ){  
        for(i=0; i<music_amount; i++)
            scanf("%d", &tracks[i]);
    
        //initial
        memset(dp, 0, sizeof(dp));

        //dp
        for(i=music_amount-1; i>=0; i--)
            for(j=0; j<=N; j++){  
                if( j < tracks[i] )
                    dp[i][j] = dp[i+1][j];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i+1][j-tracks[i]]+tracks[i] );
            }

        path(0,N);
        //printf("sum:%d\n",rec(0,N));
        printf("sum:%d\n",dp[0][N]);
    
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
