#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 110

/*
 * 1.这是一道字符串相关的题目。
 * 2.分别找到s1,s2,s3,s4的结尾，然后拼凑在第二行诗的结尾即可（要先去除"..."）
 */

char line1[MAX_LINE];
char line2[MAX_LINE];

int main(){
    int test_case;
    scanf("%d", &test_case);
    getchar();         //skip '\n'
    for(int k=0; k<test_case; k++){  
        //initial
        memset(line1, 0, sizeof(line1));
        memset(line2, 0, sizeof(line2));

        fgets(line1, MAX_LINE, stdin);
        fgets(line2, MAX_LINE, stdin);
        line1[ strlen(line1)-1 ] = '\0';     //去掉末尾的'\n'
        line2[ strlen(line2)-1 ] = '\0';     //去掉末尾的'\n'

        char *s1_over = strchr(line1, '<');         //找到s1的末尾
        char *s2_over = strchr(s1_over, '>');       //找到s2的末尾
        char *s3_over = strchr(s2_over, '<');       //找到s3的末尾
        char *s4_over = strchr(s3_over, '>');       //找到s4的末尾

        //去掉"..."
        int len = strlen( line2 );
        line2[len-1] = line2[len-2] = line2[len-3] = '\0';
    
        //在第二行诗末尾添加s4
        int i = 1;
        while( s3_over+i != s4_over ){
            line2[ strlen(line2) ] = *(s3_over + i);
            i++;
        }
        //在第二行诗末尾添加s3
        i = 1;
        while( s2_over+i != s3_over ){
            line2[ strlen(line2) ] = *(s2_over + i);
            i++;
        }
        //在第二行诗末尾添加s2
        i = 1;
        while( s1_over+i != s2_over ){
            line2[ strlen(line2) ] = *(s1_over + i);
            i++;
        }
        //在第二行诗末尾添加s5
        i = 1;
        while( *(s4_over+i) != '\0' ){
            line2[ strlen(line2) ] = *(s4_over + i);
            i++;
        }

        //output
        len = strlen(line1);
        for(i=0; i<len; i++){  
            if( line1[i] == '<' || line1[i] == '>' )
                continue;
            printf("%c",line1[i]);
        }

        printf("\n%s\n",line2);
    }

    return 0;
}
