#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX_OBJECT 1010
#define MAX_PEOPLE 110
#define MAX_WEIGHT 35

/* url: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1071
 * 1.0-1背包问题。动态规划。
 * 2.详见<<算法竞赛入门经典>> Page167, 例题9-5
 */

int object_amount;
int value[MAX_OBJECT];
int weight[MAX_OBJECT];
int people_amount;
int people_max_weight[MAX_PEOPLE];
int people_max_value[MAX_PEOPLE];

/* 依次把第一个物品看成第1层，第二个物品看成第2层。
 * d[i][j]表示当前在第i层，背包剩余容量为j时接下来的最大价值和
 */
int d[MAX_OBJECT][MAX_WEIGHT];

int dp(int curr_people_max_weight){  
    //printf("curr_people_max_weight : %d\n", curr_people_max_weight);

    memset(d, 0, sizeof(d));
    //递推法
    for(int i = object_amount; i>=1; i--){     //逆序
        for(int j = 0; j <= curr_people_max_weight; j++){  
            d[i][j] = ( i==object_amount ? 0 : d[i+1][j] );
            if( j >= weight[i] )
                d[i][j] = max( d[i][j], d[i+1][j-weight[i]]+value[i] );   //考虑是否装第i个物品
        }
    }
    return d[1][curr_people_max_weight];
}

int main(){
    int test_case,i;
    scanf("%d", &test_case);
    for(int k=0; k<test_case; k++){  
        //get input
        scanf("%d", &object_amount);
        for(i=1; i<=object_amount; i++)
            scanf("%d %d", &value[i], &weight[i]);
        scanf("%d", &people_amount);
        for(i=0; i<people_amount; i++)
            scanf("%d", &people_max_weight[i]);
    
        int total = 0;
        for(i=0; i<people_amount; i++){  
            people_max_value[i] = dp(people_max_weight[i]);
            total += people_max_value[i];
            //printf("%d\n", people_max_value[i]);
        }
        //printf("total : %lld\n", total);
        printf("%d\n", total);
    }

    return 0;
}
