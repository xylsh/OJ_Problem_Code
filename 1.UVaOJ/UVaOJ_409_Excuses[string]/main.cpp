#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX_K 25
#define MAX_K_LENGTH 25
#define MAX_E 25
#define MAX_E_LENGTH 80

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=96&page=show_problem&problem=350
 * 1.从左到右依次查找记录keyword出现次数，再找出次数最多的借口即可。
 * 2.keyword都是小写的，借口是大小写混合的，匹配keyword不分大小写。
 * 3.注意题中这句话：
 *       A keyword ``occurs" in an excuse if and only if it exists in the string in contiguous(连续的) form and is delimited(划界) by the beginning or end of the line or any non-alphabetic character or a space.
 *   所以"dogdog"是不算做匹配关键词"dog"的。
 *   我第一次实现这个条件时，没有计数"dogdog"中的第一个dog，却计数了第二个dog，结果也AC了，
 *   可见UVaOJ的测试数据不完善，由此推测网上的这道题的代码在这一点上可能是有问题的。
 */

char keywords[MAX_K][MAX_K_LENGTH];
char excuses[MAX_E][MAX_E_LENGTH];
char excuses_backup[MAX_E][MAX_E_LENGTH];
int count[MAX_E];

//获得数组a中最大的数
int get_max(int a[],int length){
    int max = a[0];
    for(int i=0; i<length; i++){  
        if( max < a[i] )
            max = a[i];
    }
    return max;
}

int main(){
    int k,e;
    int i,j,count_case = 0;
    while( scanf("%d %d", &k, &e) == 2 ){
        count_case++;

        //initial
        memset(keywords, 0, sizeof(keywords));
        memset(excuses, 0, sizeof(excuses));
        memset(excuses_backup, 0, sizeof(excuses_backup));
        memset(count, 0, sizeof(count));

        //input
        for(i=0; i<k; i++)
            scanf("%s", keywords[i]);
        getchar();
        for(i=0; i<e; i++)
            fgets(excuses[i], MAX_E_LENGTH, stdin);

        //backup
        memcpy(excuses_backup,excuses,sizeof(excuses));
        //excuses统一为小写
        for(i=0; i<e; i++){
            int length = strlen(excuses[i]);
            for(j=0; j<length; j++){  
                if( isupper(excuses[i][j]) )
                    excuses[i][j] = tolower(excuses[i][j]);
            }
        }
    
        //统计keyword出现次数
        for(i=0; i<e; i++){          //遍历所有借口
            for(j=0; j<k; j++){      //遍历所有keyword
                char *p = excuses[i];
                while( ( p = strstr(p,keywords[j]) ) != NULL ){
                    if( !isalpha(*(p+strlen(keywords[j]))) )      //下一个char非字母才算匹配
                        count[i]++;
                    while( isalpha(*p) )        //这样做是为了避免计数"dogdog"中的第二个dog
                        p++;
                }
            }
            /*for(int z=0; z<e; z++)
                printf("%d ",count[z]);
            printf("\n");*/
        }

        //output
        printf("Excuse Set #%d\n", count_case);
        int max = get_max(count,e);
        for(i=0; i<e; i++){  
            if( count[i] == max )
                printf("%s", excuses_backup[i]);
        }
        printf("\n");
    
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
