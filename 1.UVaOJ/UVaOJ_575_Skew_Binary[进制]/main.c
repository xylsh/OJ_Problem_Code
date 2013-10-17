#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50

char sb[MAX];
/* 反转字符串。str必须以'\0'结尾 */
void reverse(char* str){ 
    int length = strlen(str);
    int i,k = length/2;
    char c;
    for(i=0; i<k; i++){
        c = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = c;
    }
}
int main(){ 
     /*freopen("file.out","r",stdin);
     freopen("out.out","w",stdout);*/
    int i,c,decimal;

    scanf("%s",sb);
    while( sb[0] != '0' ){  
        reverse(sb);
        decimal = 0;
        c = 1;

        for(i=0; i<strlen(sb); i++){  
            decimal += ( pow(2,c)-1 ) * ( sb[i] - '0' );
            c++;
        }
        printf("%d\n",decimal);

        scanf("%s",sb);
    }

    /*printf("Time: %f\ns", (double)clock() / CLOCKS_PER_SEC);*/
    return 0;
}
