#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 1000010

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1345
 * 1.DP问题，用了递推法。
 * 2.dp[i]表示当前有i个石头，该当前玩家拿走石头，值为1:当前玩家赢，值为0:当前玩家输
 */

int dp[MAX];  //dp[i]表示有i个石头，值为1:先手者赢
                                  //值为0:先手者输
int a[15];

int main(){
    int n,m,i,j;
    while( scanf("%d %d",&n,&m) == 2 ){  
        for(i=0; i<m; i++)
            scanf("%d", &a[i]);

        //initial
        memset(dp, 0, sizeof(dp));

        for(i=1; i<=n; i++)        //假设当前有i个石头，一直增加到n个石头
            for(j=0; j<m; j++){    //遍历尝试每一种拿法
                /*if( i == a[j] ){     //如果当前石头数==可拿走的石头数，那么当前玩家赢定了
                    dp[i] = 1;
                    break;
                }else if( i > a[j] && dp[i-a[j]] == 0 ){    //如果当前石头数>可拿走的石头数，
                                                            //且拿走这么多石头后，下一个拿石头的玩家输，那么当前玩家赢
                    dp[i] = 1;
                    break;
                }*/
                if( i >= a[j] && dp[i-a[j]] == 0 ){      //上面的2中情况可以综合为这一种情况
                    dp[i] = 1;
                    break;         //如果已经找到一种当前玩家赢的方法就不用再尝试别的拿法了，
                                   //如果找不到当前玩家赢的方法,那么dp[i]就是默认值0,表示当前玩家输
                }
            }

        if( dp[n] == 1 )
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
