#include <stdio.h>
#include <math.h>

int main(){ 

    double n,p;   /* double的数值范围为1.7E-308～1.7E+308 */
    int k;
    while( scanf("%lf %lf",&n,&p) == 2 ){  
        k = floor( pow(p,1/n)+0.5 );   /* 避免浮点运算可能产生的误差 */
        printf("%d\n",k);
    }

    return 0;
}
