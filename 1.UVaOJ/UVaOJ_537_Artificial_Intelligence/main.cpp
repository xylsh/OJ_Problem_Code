#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX 100000

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=96&page=show_problem&problem=478
 * 1.在句子中查找"I="即可找到I。U,P类似。
 * 2.没在句子中找到哪个就计算哪个。
 * 3.stdlib.h中的strtod()可以把字符串转换为double数
 * 4.每一组输出都要跟一个空行，包括最后一组数据。如果最后一组数据没有跟一个空行，UVaOJ会提示WA，而不是PE。
 */

char sentence[MAX];

//字符串转换为double数
double get_data(char *p){  
    char tmp[20] = { 0 };
    int length = 0;
    while( *p != 'W' && *p != 'A' && *p != 'V' ){
        tmp[length] = *p;
        length++;
        p++;
    }
    float number = strtod(tmp, NULL);

    if( tmp[length-1] == 'm' )
        number /= 1000;
    else if( tmp[length-1] == 'k' )
        number *= 1000;
    else if( tmp[length-1] == 'M' )
        number *= 1000000;

    return number;
}

int main(){
    int test_case;
    double P,I,U;
    bool lack_P, lack_I, lack_U;
    scanf("%d", &test_case);
    getchar();    //skip '\n'
    for(int k=1; k<=test_case; k++){
        fgets(sentence, MAX, stdin);

        //initial
        lack_P = lack_I = lack_U = true;

        char *pI = strstr(sentence, "I=");
        char *pU = strstr(sentence, "U=");
        char *pP = strstr(sentence, "P=");
        if( pI != NULL ){  
            I = get_data(pI+2);
            lack_I = false;
        }
        if( pU != NULL ){  
            U = get_data(pU+2);
            lack_U = false;
        }  
        if( pP != NULL ){  
            P = get_data(pP+2);
            lack_P = false;
        }  
        //printf("%f %f %f\n",I,P,U);

        printf("Problem #%d\n", k);

        if( lack_P ){  
            P = U * I;
            printf("P=%.2fW\n", P);
        }else if( lack_I ){
            I = P/U;
            printf("I=%.2fA\n", I);
        }else if( lack_U ){
            U = P/I;
            printf("U=%.2fV\n", U);
        }
    
        printf("\n");
    
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
