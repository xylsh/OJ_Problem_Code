#include <stdio.h>
#include <string.h>
#include <time.h>

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=398
 * 1.这是一道简单模拟题，题目有些难读，这里有翻译：http://www.nocow.cn/index.php/UVA/457
 * 2.模拟细菌密度变化即可。
 */

char convert(int a){
    char c;
    switch(a){
        case 0: c = ' ';  break;
        case 1: c = '.';  break;
        case 2: c = 'x';  break;
        case 3: c = 'W';  break;
    }
    return c;
}
int main(){
    int test_case,i,j;
    int dna[10], dish[42], mid[42];
    scanf("%d",&test_case);

    while( test_case-- ){
        for(i=0; i<10; i++)
            scanf("%d", &dna[i]);
        //initial
        memset(dish, 0, sizeof(dish));
        dish[20] = 1;

        for(int d=1; d<=50; d++){
            //打印第d天
            for(i=1; i<=40; i++)
                printf("%c", convert(dish[i]));
            printf("\n");
            //模拟第d天的密度变化
            memcpy(mid,dish,sizeof(dish));
            for(i=1; i<=40; i++)
                dish[i] = dna[ mid[i-1] + mid[i] + mid[i+1] ];
        }
        if( test_case != 0 ) printf("\n");
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
