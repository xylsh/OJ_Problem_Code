#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=635
 * 1.按照题目中所描述的算法计算，记录步骤数量。
 * 2.A最大可能为2^31-1,在计算过程中极有可能溢出，所以要用long long类型。
 */

int fun(long long A,long long L){  
    int term = 1;

    while( A != 1 && A <= L ){
        if( A % 2 == 0 )
            A = A/2;
        else
            A = A*3 + 1;
        
        if( A <= L )
            term++;
    }
    return term;
}

int main(){
    int test_case = 1,term;
    long long A,L;
    while( scanf("%lld %lld", &A, &L) == 2 && A != -1 && L != -1 ){  

        term = fun(A,L);    
    
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",
                test_case++, A, L, term);
    
    }

    return 0;
}
