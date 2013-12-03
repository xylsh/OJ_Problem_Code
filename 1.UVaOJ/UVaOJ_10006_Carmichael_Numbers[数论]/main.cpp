#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 65010

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=115&page=show_problem&problem=947
 * 1.如果 n 是素数，那么n一定不是Carmichael Number.
 *   如果n不是素数，且n满足题目中的 a^n%n == a,(2<=a<=n-1),那么n是Carmichael Number.
 * 2.判断n是否是素数，可以用筛法构造素数表来判断。
 * 3.求 a^n%n 的值即幂取模问题，参见pow_mod_v1()和pow_mod_v2()，其中pow_mod_v1()复杂度为O(n)，会超时。
 */

int prime[MAX];   //0表示素数，1表示不是素数

//O(n)
long long pow_mod_v1(int a,int n,int m){
    long long ans = a;
    for(int i=1; i<=n-1; i++){
        ans = ans*a % m;
    }
    return ans;
}

//O(logn)
long long pow_mod_v2(int a,int n,int m){  

    if( n == 0 )
        return 1;

    long long x = pow_mod_v2(a,n/2,m);
    long long ans = x * x % m;
    if( n%2 == 1 )
        ans = ans * a % m;
    return ans;
}

int main(){
    int n,is_carmi;

    //构造素数表
    memset(prime, 0, sizeof(prime));
    for(int i=2; i<MAX; i++)
        for(int j=2*i; j<MAX; j+=i)
            prime[j] = 1;

    while( scanf("%d",&n) == 1 && n != 0 ){
        if( prime[n] == 0 ){           //n如果是素数
            printf("%d is normal.\n", n);
            continue;
        }
    
        is_carmi = 1;
        for(int a=2; a<n-1; a++){
            if( pow_mod_v2(a,n,n) != a ){  
                is_carmi = 0;
                break;
            }
        }

        if( is_carmi )
            printf("The number %d is a Carmichael number.\n",n);
        else
            printf("%d is normal.\n", n);
    
    }
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
