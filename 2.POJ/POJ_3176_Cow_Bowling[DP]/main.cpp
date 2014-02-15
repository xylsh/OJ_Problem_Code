#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAX_N 360

/*
 * URL:http://poj.org/problem?id=3176
 * 1.DP，可以用记忆化搜索解决。
 */

int N;
int triangle[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];   //dp[i][j]表示走到(i,j)时最大的和

//rec(i,j)表示走到(i,j)时最大的和
int rec(int i,int j){
    if( i<1 || i>N || j<1 || j>i )
        return 0;
    if( dp[i][j] >= 0 )
        return dp[i][j];

    int ans = max(rec(i-1,j-1) + triangle[i][j], 
                  rec(i-1,j) + triangle[i][j] );   //上一行对应的2个点都试一试
    
    return dp[i][j] = ans;
}

int main(){
    int i,j;
    scanf("%d", &N);
    for(i=1; i<=N; i++)
        for(j=1; j<=i; j++)
            scanf("%d", &triangle[i][j]);

    //initial
    memset(dp, -1, sizeof(dp));

    //找到最后一行的最大的和
    int max = -1;
    for(i=1; i<=N; i++){
        int tmp = rec(N, i);
        if( max < tmp )
            max = tmp;
    }
    printf("%d\n", max);
    
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
/*
 * 还有一种写法：
 *  //初始化的值和上面的方法不一样
    memset(dp, 0, sizeof(dp));

    for(i=1; i<=N; i++){        //遍历行
        for(j=1; j<=i; j++){    //遍历列
            dp[i][j] = max( dp[i-1][j-1] + triangle[i][j],
                            dp[i-1][j]   + triangle[i][j]);
        }
    }
    int max = -1;
    for(i=1; i<=N; i++){
        int tmp = dp[N][i];;
        if( max < tmp )
            max = tmp;
    }
    printf("%d\n", max);
 *
 */
