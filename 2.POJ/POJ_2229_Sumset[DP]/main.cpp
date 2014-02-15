#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAX_N 1000010

/*
 * URL:http://poj.org/problem?id=2229
 * 1.DP.
 * 2.dp[i]:= 当N=i时共有多少种方法
 *   递推式: N为奇数时，dp[i] = dp[i-1].因为i-1是偶数，i中多出来的那个1不能凑成新的2的整数次幂
 *           N为偶数时，dp[i] = dp[i-2] + dp[i/2]. 假设多出来的2个1均以1的形式出现在加法式子中，则构成了dp[i]的一部分，是dp[i-2]
 *                                                 假设多出来的2个1不再以1的形式出现在加法式子中，则构成了dp[i]的一部分,是dp[i/2]
 * 3.取最后9个数字只需模1000000000即可。
 *
 */

int dp[MAX_N];   //dp[i]表示N=i时共有多少种方法
int N;

int main(){
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=N; i++){
        if( i % 2 == 1 )
            dp[i] = dp[i-1] % 1000000000;
        else
            dp[i] = ( dp[i-2] + dp[i/2] ) % 1000000000;
    }

    printf("%d\n", dp[N]);
    
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
