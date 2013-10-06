#include <stdio.h>

int main(){ 
    
    /* 因为The input numbers are not greater than 2^32，所以要选long long类型 */
    long long a,b;
    
    while( scanf("%lld %lld", &a, &b) != EOF ){  
        if(a>b)
            printf("%lld\n",a-b);
        else
            printf("%lld\n",b-a);
    }
    
    return 0;
}

