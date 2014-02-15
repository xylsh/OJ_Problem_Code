#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_K 15

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=115&page=show_problem&problem=1046
 * 1.排列组合问题。
 * 2.从n个(X1+X2+X3+...+Xk)中选k_value[1]个X1出来参与相乘，
 *   然后从n-k_value[1]个(X1+X2+X3+...+Xk)中选k_value[2]个X2出来参与相乘
 *   ......
 *   依次类推。
 */

int k_value[MAX_K];
long long c[MAX_K];

//计算组合,c[r]表示从a个中挑选出r个的方法数
long long cal_c(int a,int r){  
    c[0] = 1;
    for(int i=1; i<=r; i++)             //递推法
        c[i] = c[i-1] * (a-i+1) / i;
    
    return c[r];
}

int main(){
    int n,k,i;
    long long coef;      //系数
    while( scanf("%d %d", &n, &k) == 2 ){  
        for(i=1; i<=k; i++)
            scanf("%d", &k_value[i]);

        coef = 1;
        int remain = n;
        for(i=1; i<=k; i++){
            coef *= cal_c(remain,k_value[i]);
            remain -= k_value[i];
        }

        printf("%lld\n",coef);
    
    }

    return 0;
}
