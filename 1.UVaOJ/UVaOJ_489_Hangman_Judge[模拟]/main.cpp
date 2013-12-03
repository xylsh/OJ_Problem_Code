#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 10000

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=430
 * 1.这是一道模拟题。
 * 2.模拟游戏规则即可。
 * 3.注意，用同一个字母多次猜测，只算1次成功或失败，所以guess要去重
 * 3.注意，在比较guess和right的过程中，如果匹配成功，则即使guess没有遍历完也算作win,我在这里WA了很多次。
 */

char right[MAX];   //正确的word
char guess[MAX];   //猜测的word

//判断是否赢了
bool check_win(char a[]){
    int length = strlen(a);
    for(int i=0; i<length; i++){
        if( a[i] != -1 )
            return false;
    }
    return true;
}

//去掉重复,用-1标志重复了的字母
void del_repeat(char a[]){
    int length = strlen(a);
    for(int i=0; i<length; i++){
        char curr = a[i];
        for(int j=i+1; j<length; j++){  
            if( curr == a[j] ){  
                a[j] = -1;
            }
        }
    }
}

int main(){
    int round,i,j;
    int count_fault;

    while( scanf("%d",&round) == 1 && round != -1 ){  
        getchar();   //skip '\n'
        scanf("%s",right);
        getchar();   //skip '\n'
        scanf("%s",guess);
        count_fault = 0;

        del_repeat(guess);    //用同一个字母多次猜测，只算1次成功或失败，所以guess要去重

        int guess_length = strlen(guess);
        int right_length = strlen(right);
        for(i=0; i<guess_length; i++){  
            char cur_char = guess[i];

            if( cur_char == -1 )      //如果是与前面重复的字母，则直接跳过
                continue;

            int have_char = 0;
            for(j=0; j<right_length; j++){
                if( cur_char == right[j] ){  
                    right[j] = -1;
                    have_char = 1;
                }
            }
            if( !have_char )
                count_fault++;

            if( count_fault >= 7 
                    || check_win(right) ){   //如果已经匹配成功，则即使guess没有遍历完也算作win
                break;
            }
        }

        printf("Round %d\n",round);
        if(count_fault >= 7){
            printf("You lose.\n");
            continue;
        }
        if( check_win(right) ){  
            printf("You win.\n");
            continue;
        }
        printf("You chickened out.\n");
    
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
