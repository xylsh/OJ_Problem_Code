#include <stdio.h>

/*
 * 解码方法：
 * decoded character的ASCII码 = coded characterASCII码 - 7
 */
int main(){ 
   
    char c;
    while( (c = getchar()) != EOF ){  
        if( c == '\n' )
            printf("\n");
        else
            printf("%c",c-7);
    }
    return 0;
}

