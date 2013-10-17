#include <stdio.h>

int main(){ 

    char c;
    int count,last;   /* last表示上一个char是否是字母 */
    count = last = 0;
    while( (c = getchar()) != EOF ){  
        if( c == '\n' ){ 
            printf("%d\n",count);
            count = 0;
        }else if( !isalpha(c) )
            last = 0;
        else if( !last ){   /* c是字母且读入的上一个字符不是字母 */
            count++;
            last = 1;
        }
    }
   
    return 0;
}

