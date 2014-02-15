#include <stdio.h>
#include <math.h>
#include <time.h>

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=100&page=show_problem&problem=1051
 * 1.数论题目。
 * 2.直接枚举每一个数模仿开关灯会超时。
 * 3.假设n能整除a,设 n / a = b,则n = a * b,所以第a趟来回和第b趟对开关的操作抵消了。
 *   所以如果sqrt(n)是整数，则n是开着的，否则关着的。
 * 4.关于数据范围，题目中说的是:"Which is less then or equals 2^32-1"，不是2^31-1，所以int是放不下n的。
 */

int main(){
    long long n;
    while( scanf("%lld", &n) == 1 ){  
        if( n==0 )  break;

        long long k = (long long)sqrt(n);
        if( k * k == n )
            printf("yes\n");
        else
            printf("no\n");
        
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
