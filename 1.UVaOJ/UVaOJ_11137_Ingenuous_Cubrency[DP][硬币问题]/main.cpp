#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_AMOUNT 10010

/*
 * 动态规划问题
 */

int coin[22];
long long d[MAX_AMOUNT];

int main(){
    int amount;

    for(int i=1; i<=21; i++)
        coin[i] = i*i*i;         //存储硬币

    memset(d, 0, sizeof(d));

    d[0] = 1;
    for(int i=1; i<=21; i++)
        for(int j=1; j<10000; j++)
            if( j >= coin[i] )
                d[j] += d[ j-coin[i] ];

    while( scanf("%d", &amount) == 1 ){ 
        printf("%lld\n", d[amount] );  
    }

    return 0;
}

