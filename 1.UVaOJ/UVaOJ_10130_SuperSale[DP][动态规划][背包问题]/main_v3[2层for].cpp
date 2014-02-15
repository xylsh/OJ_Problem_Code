#include <stdio.h>
//#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//#include <queue>
//#include <vector>
//#include <set>
//#include <map>
#include <algorithm>
//#include <utility>
//#include <functional>
using namespace std;
#define MAX_N 1010
#define MAX_G 110
#define MAX_WEIGHT 35

/* url: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1071
 * 1.0-1背包问题。动态规划。
 * 2.上传代码发现记忆化搜索的版本比用双层循环的方式快许多。
 * 3.详见<<算法竞赛入门经典>> Page167, 例题9-5
 *   详见<<挑战程序设计竞赛>> Page51, 例题2.3.1
 */

int v[MAX_N];
int w[MAX_N];
int group[MAX_G];
int dp[MAX_N][MAX_WEIGHT];
int N,G;


int solve(int max_weight){  
    int i,j;
    for(i=N-1; i>=0; i--){  
        for(j=0; j<=max_weight; j++){  
            if( j < w[i] )
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = max( dp[i+1][j], dp[i+1][j-w[i]]+v[i] );
        }
    }
    return dp[0][max_weight];
}

int main(){
    int test_case,i;
    scanf("%d", &test_case);
    while( test_case-- ){  
        scanf("%d", &N);
        for(i=0; i<N; i++)
            scanf("%d %d", &v[i], &w[i]);
        scanf("%d", &G);
        for(i=0; i<G; i++)
            scanf("%d", &group[i]);
    
        //solve
        int ans = 0;
        for(i=0; i<G; i++){
            memset(dp, 0, sizeof(dp));
            ans += solve(group[i]);
        }
    
        printf("%d\n", ans);
    
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
