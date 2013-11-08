#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

/*
 * 1.要使结果最小，就先计算式子中的所有乘法，最后计算所有加法。（因为乘法造成的结果涨幅比加法大。）
 * 2.要使结果最大，就先计算式子中的所有加法，最后计算所有乘法。（因为乘法造成的结果涨幅比加法大。）
 * 3.注意：要使用long long类型，OJ测试数据很大。
 */

char expre[MAX];
long long num[MAX];     //存放表达式数字
long long num_2[MAX];
char oper[MAX];         //存放运算符
char oper_2[MAX];
int num_count,oper_count;

long long get_min(){
    long long result = 0;
    //计算乘法
    for(int i=0; i<oper_count; i++){  
        if( oper[i] == '*' ){  
            num[i+1] = num[i] * num[i+1];
            num[i] = 0;
        }
    }    
    //计算加法
    for(int i=0; i<num_count; i++)
        result += num[i];

    return result;
}

long long get_max(){
    long long result = 1;
    //计算加法
    for(int i=0; i<oper_count; i++){  
        if( oper_2[i] == '+' ){
            num_2[i+1] = num_2[i] + num_2[i+1];
            num_2[i] = 1;
        }
    }
    //计算乘法
    for(int i=0; i<num_count; i++)
        result *= num_2[i];

    return result;
}

int main(){
    int test_case;
    scanf("%d", &test_case);
    getchar();                           //skip '\n'
    for(int k=0; k<test_case; k++){  
        fgets(expre,MAX,stdin);
        expre[strlen(expre)-1] = '\0';   //去掉末尾的'\n'

        //initial
        num_count = oper_count = 0;

        int length = strlen(expre);
        for(int i=0; i<length; i++){  
            if( expre[i] == '+' || expre[i] == '*' ){  
                oper[oper_count++] = expre[i];
            }else if( isdigit(expre[i]) ){ 
                int tmp = 0;
                do{  
                    tmp = tmp*10 + ( expre[i++] - '0' );
                }while( isdigit(expre[i]) );
                i--;
                num[num_count++] = tmp;
            }
        }
        memcpy(num_2, num, num_count*8);    //第3个参数是要拷贝的字节数
        memcpy(oper_2, oper, oper_count);

        /*for(int i=0; i<num_count; i++)
            printf("%d ",num_2[i]);
        printf("\n");
        for(int i=0; i<oper_count; i++)
            printf("%c ",oper_2[i]);
        printf("\n");*/

        /*for(int i=0; i<num_count; i++)
            printf("%d ",num[i]);
        printf("\n");
        for(int i=0; i<oper_count; i++)
            printf("%c ",oper[i]);
        printf("\n");*/
    
        printf("The maximum and minimum are %lld and %lld.\n", get_max(), get_min());
    }
    return 0;
}

