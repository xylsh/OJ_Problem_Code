#include <stdio.h>
#include <string.h>
#include <string>
#define MAX 1000000

/*
 * 1.从第3个样例输出得知，s中的字母不需要一定连续在t中出现，
 *   t中只要按顺序出现s中的字母就算s是t的"subsequence".
 * 2.从s的第一个字母开始，按顺序在t中寻找s的字母，如果能找到全部字母，
 *   那么s是t的subsequence,否则不是。
 */

char s[MAX],t[MAX];

int main(){
    int flag;
    char *ss,*tt;

    while( scanf("%s %s",s,t) == 2 ){  
        //initial
        flag = 0;
        ss = s;
        tt = t;

        //tt如果为NULL，那么执行strchr(tt,*ss)会导致段错误
        while( tt != NULL && *ss != '\0' && (tt = strchr(tt,*ss)) != NULL ){  
            tt++;
            ss++;
        }

        if( *ss == '\0' )
            flag = 1;

        //output
        if( flag )
            printf("Yes\n");
        else
            printf("No\n");

    }

    return 0;
}

