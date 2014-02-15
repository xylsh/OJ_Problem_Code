#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 600

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=97&page=show_problem&problem=1047
 * 1.这是一道高精度计算题目。
 * 2.总的思路就是模拟手算.
 *     (1).反转运算数
 *     (2).从低位到高位遍历num2的每一个数去乘num1的数。每乘一次都要检查一次保存进位的数c是否应该进位。
 *     (3).乘完之后检查乘积最高位是否要进位。
 *     (4).逆序输出乘积数组，如果乘积为0则输出0.
 * 3.实现过程中很容易考虑不全，要测试结果为0和最大值的情况。
 *
 */

char num1[260] = { 0 };
char num2[260] = { 0 };
int product[MAX] = { 0 };

//反转字符串
void reverse(char num[],int length){
    int l = length / 2;
    for(int i=0; i<l; i++){
        char c = num[i];
        num[i] = num[length-i-1];
        num[length-i-1] = c;
    }
}

int main(){
    
    while( scanf("%s", num1) == 1 ){  
        getchar();
        scanf("%s", num2);

        int num1_length = strlen(num1);
        int num2_length = strlen(num2);
        reverse(num1,num1_length);
        reverse(num2,num2_length);
        //printf("%s\n%s\n",num1,num2);

        int curr,c;
        for(int i=0; i<num1_length; i++){    //用num1的每一个数去乘num2
            curr = i;                        //curr会随i增长，因为每一个num1的数乘以num2后，相加时不是对齐个位来加的。
            c = 0;
            int n1 = num1[i]-'0';            //当前num1的数
            for(int j=0; j<num2_length; j++){
                int m = n1 * (num2[j]-'0') + c;
                product[curr] += m % 10;
                c = (m / 10) + (product[curr] / 10);    //c保存进位
                product[curr] %= 10;
                curr++;
            }
            while( c > 0 ){                //乘完之后如果要进位
                product[curr] = c % 10;
                c = c/10;
                curr++;
            }
        }
        while( product[curr] > 9 ){        //如果乘积最高位要进位
            int tmp = product[curr];
            product[curr] = tmp % 10;
            product[curr+1] = tmp / 10;
            curr++;
        }

        int i;
        for(i=MAX-1; i>=0; i--){  
            if( product[i] != 0 )
                break;
        }
        //printf("i = %d\n",i);
        if(i == -1)        //如果计算结果为0
            printf("0");
        else
            for(int j=i; j>=0; j--)
                printf("%d", product[j]);
        printf("\n");

        //initial
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(product, 0, sizeof(product));
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
