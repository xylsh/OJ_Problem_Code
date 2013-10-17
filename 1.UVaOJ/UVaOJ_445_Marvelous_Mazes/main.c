#include <stdio.h>
/*
 * 1.因为迷宫个数和单行长度均无限制，所以不能用数组保存，
 * 而采用"马上读，马上输出"的方式。
 * 2.从题目描述来看，输入输出均被重定向到了文件。
 */
int main(){ 
    /*freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);*/

    int last_isdigit,last_digit,i;
    last_isdigit = 0;   /* 得到的上一个字符是否是数字 */
    last_digit = 0;     /* 保存上一个数字的值,如果前面有几个数字,那么该变量保存之前几个数字的和 */
    char c;
    while( (c = getchar()) != EOF ){  
        if(c == '\n'){ printf("%c",c); continue; }

        if( isdigit(c) ){
            if( !last_isdigit ){         /* 如果last_isdigit == 0 */
                last_isdigit = 1;
                last_digit = c - '0';
            }else if( last_isdigit ){    /* 如果last_isdigit == 1 */
                last_digit += (c - '0');
            }
        }else if( c != '!' ){      /* 如果c不是数字 且 c!='!' */
            if( c=='b' ) c = ' ';
            for(i=0; i<last_digit; i++){
                printf("%c",c);
            }
            last_isdigit = last_digit = 0;
        }else{                      /* 如果c=='!' */
            printf("\n");
        }

    }
   
    return 0;
}

