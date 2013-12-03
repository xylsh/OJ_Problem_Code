#include <stdio.h>
#include <string.h>
#include <time.h>

/* URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=115&page=show_problem&problem=1020
 * 关键是找出公式，记切的次数为n，pizza块数为f(n),则：
 *     f(n) = n*(n+1)/2 + 1; 
 */

int main(){
    long long n;
    while( scanf("%lld",&n) && n >= 0 )
        printf("%lld\n", n*(n+1)/2 + 1 );
    
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
