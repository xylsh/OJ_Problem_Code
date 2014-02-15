#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD 110
#define MAX_LETTER 110

/*
 * 1.要使按键次数最少，就要尽量利用语音“repeat”命令，
 *   所以，有重复字母的单词（从单词第一个字母算起，下同）要尽量安排在一起输出.
 * 2.为了实现上条的目标，先把所有单词排序，这样，有重复字母的单词就安排在一起了。
 * 3.与前一个单词有重复字母的单词的按键次数是： 单词字母数 - 单词重复字母数，依题意空格不算在内。
 * 4.与前一个单词没有重复字母的单词的按键次数是：该单词的字母数。
 * 5.注意观察：多个字符串是如何用qsort()进行排序的。
 */

char *words[MAX_WORD];

int comp(const void *a, const void *b){  
    return strcmp( *(char **)a , *(char **)b );      //从小到大排序
}

//获得2个单词的重复字母数(从单词第一个字母算起)
int get_repeat(char *a,char *b){  
    int i = 0;
    while( *a != '\0' && *b != '\0' && *a == *b ){   //别忘了判断字符串是否结束
        i++;
        a++;
        b++;
    }
    return i;
}

int main(){
    int test_case, word_amount, min_press, i;
    char *word;

    scanf("%d", &test_case);
    for(int k=0; k<test_case; k++){  
        scanf("%d", &word_amount);
        for(i=0; i<word_amount; i++){
            word = (char *)malloc(sizeof(char) * MAX_LETTER);
            scanf("%s",word);
            words[i] = word;
        }

        //initial
        min_press = 0;

        /*for(i=0; i<word_amount; i++)
            printf("%s\n",words[i]);*/
        qsort(words, word_amount, sizeof(char *), comp);         //注意观察多个字符串是如何用qsort()进行排序的。
        /*for(i=0; i<word_amount; i++)
            printf("%s\n",words[i]);
        printf("------------------\n");*/
        min_press += strlen(words[0]);       //第一个单词的字母一定会全部按键

        int repeat = 0;
        for(i=1; i<word_amount; i++){  
            repeat = get_repeat( words[i-1],words[i] );
            //printf("%d\n",repeat);
            if( repeat == 0 ){
                min_press += strlen( words[i] ) ;      //依据题意，空格不计算在内,所以没有加1
            }else{  
                min_press += (strlen( words[i] ) - repeat);
            }
        }

        //output
        printf("%d\n", min_press);
        for(i=0; i<word_amount; i++)
            printf("%s\n", words[i]);
    
    }
    
    return 0;
}

