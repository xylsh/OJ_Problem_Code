#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 7495

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=615
 * 1.动态规划题目，使用记忆化搜索。
 * 2.如果把dp数组定义为1维的话，那么会导致重复计算，这个问题参考博文讲的很清楚。
 *   所以把dp数组定义为2维的，另一维用来存放当前从第几个coin开始。
 *   综上，dp[a][b]表示当前兑换从coin[b]开始，a元共有dp[a][b]种兑换方式.
 * 3.参考了博文：http://blog.csdn.net/bluecat56/article/details/9772975
 */

int coin[] = { 50,25,10,5,1 };
int dp[MAX][5];   //dp[a][b]表示当前兑换从coin[b]开始，a元共有dp[a][b]种兑换方式

//返回从curr_coin开始，money有多少种兑换方法
int rec(int money,int curr_coin){  
    if( curr_coin > 4 )
        return 0;
    if( money == 1 || money == 0 )
        return 1;
    if( dp[money][curr_coin] > 0 )      //如果已经计算过
        return dp[money][curr_coin];

    int ans = 0;
    for(int i=curr_coin; i<5; i++){  
        if( money >= coin[i] ){
            ans = rec(money, i+1) + rec(money-coin[i], i);   //用不用当前coin都试一试
            break;     //不需要接着循环了，因为后面还未尝试的coin已经在上一行的"rec(money, i+1)"中计算过了。
        }
    }

    dp[money][curr_coin] = ans;    //别忘了保存结果
    return ans;
}

int main(){
    int money,i;

    /*for(i=1; i<MAX; i++)
        dp[i][0] = rec(i,0);*/

    while( scanf("%d",&money) == 1 ){  
        //printf("%d\n", dp[money][0]);
        printf("%d\n", rec(money,0));
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
