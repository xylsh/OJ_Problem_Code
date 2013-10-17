#include <stdio.h>
/*
 * 按照题目要求循环找出最大cycle即可
 * 要注意题目没有规定i和j谁大谁小
 */
int cal(int a){
    int count = 1;
    while( a != 1){
        if( a%2 ) a = 3*a + 1;
        else a = a/2;
        count++;
    }
    return count;
}

int main(){ 
    
    int a,b,count,i,tmp;
    while( scanf("%d %d",&a,&b) != EOF ){

        printf("%d %d ",a,b);

        if( a > b ){   /* 题目没有规定i和j谁大谁小 */
            /* 交换两个变量 */
            a = a+b;
            b = a-b;
            a = a-b;
        }

        count = 0;
        for(i=a; i<=b; i++){  
            tmp = cal(i);
            if(tmp > count) count = tmp;
        }
        printf("%d\n",count);
    }

    return 0;
}
