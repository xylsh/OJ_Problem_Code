#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAX_T 1010
#define MAX_W 35

/*
 * URL:http://poj.org/problem?id=2385
 * 1.DP,使用了记忆化搜索。
 * 2.思路已经在代码中注释得很详细了。
 */

int T,W;
int fall[MAX_T];       //fall[i]表示在第i分钟，落苹果的是哪一棵树
int dp[MAX_T][MAX_W];  //dp[i][j]表示第i分钟最多接到多少苹果，
                       //j表示剩余可转移树的次数

//rec(i,j)表示第i分钟最多接到多少苹果，j表示剩余可转移树的次数
int rec(int i, int j){  
    if( i<1 || i>T || j<0 || j>W )
        return 0;
    if( dp[i][j] >= 0 )    //如果已经计算过
        return dp[i][j];

    int ans = 0;
    if( j == 0 ){         //不能再转移到另一棵树下了
        ans = max(rec(i-1,j), rec(i-1,j+1) );      //前一分钟转移和没转移2种情况下能接到的苹果数量 的较大值
        if( (W % 2 == 0 && fall[i] == 1) ||
            (W % 2 == 1 && fall[i] == 2) ){        //如果第i分钟的苹果从自己所在的树落下
            ans++;
        }
    }else{
        ans = max( rec(i-1,j), rec(i-1,j+1) );     //前一分钟转移和没转移2种情况下能接到的苹果数量 的较大值
        if( (j % 2 == 0 && fall[i] == 1) ||
            (j % 2 == 1 && fall[i] == 2) ){        //如果第i分钟的苹果从自己所在的树落下
            ans++;
        }
    }

    return dp[i][j] = ans;
}

int main(){
    int i,j;
    scanf("%d %d", &T, &W);
    for(i=1; i<=T; i++ )
        scanf("%d", &fall[i]);

    memset(dp, -1, sizeof(dp));

    //找出第T分钟时最多能接的苹果数
    int max = -1;
    for(j=0; j<=W; j++){  
        int tmp = rec(T,j);
        if( max < tmp )
            max = tmp;
    }
    printf("%d\n", max);
    
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
