#include <stdio.h>
#include <string.h>

#define MAX 80

char sentence[MAX][MAX];
int main(){ 

    int n,i,j;
    scanf("%d", &n);
    getchar();   /* 过滤n后面的回车 */
    for(i=0; i<n; i++){
        fgets(sentence[i],MAX,stdin);
    }

    for(i=0; i<n; i++){  
        for(j=strlen(sentence[i])-2; j>=0; j--) /* 字符串'\0'的前一个字符是换行,所以'-2' */
            printf("%c",sentence[i][j]);
        printf("\n");
    }
    
    return 0;
}

