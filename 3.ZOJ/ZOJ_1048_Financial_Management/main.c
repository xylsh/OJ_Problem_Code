#include <stdio.h>

int main(){ 

    float money,sum = 0;
    while( scanf("%f", &money) == 1 ){  
        sum += money;
    }
    printf("$%.2f\n",sum/12);
    
    return 0;
}

