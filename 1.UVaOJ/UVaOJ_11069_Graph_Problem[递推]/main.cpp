#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 80

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=115&page=show_problem&problem=2010
 * 1.递推式：f(n) = f(n-2) + f(n-3),边界为f(0) = 0,f(1) = 1,f(2) = 2,f(3) = 2.
 */

int subset[MAX_N];

void initial_subset(){  
    subset[0] = 0;
    subset[1] = 1;
    subset[2] = 2;
    subset[3] = 2;
    for(int i=4; i<MAX_N; i++)        //递推法
        subset[i] = subset[i-2] + subset[i-3];

}

int main(){
    int nodes;
    initial_subset();
    while( scanf("%d", &nodes) == 1 )
        printf("%d\n", subset[nodes]);
    
    return 0;
}
