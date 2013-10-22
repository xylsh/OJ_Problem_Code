#include <stdio.h>
#include <string.h>
#define MAX 120
/*
 * 1.通过观察输出元素的下标找规律即可
 * 2.输出格式有坑：换行符和'\0'要以空格输出，题目描述中的样例输出其实都是PE(Presentation error)的。
 */
char sentence[MAX][MAX];
int main(){ 
    /*freopen("out.out","w",stdout);*/
    memset(sentence,0,sizeof(sentence));
    int count = 0;
    int maxlength = 0;  /* 最长句子长度 */
    int length;
    while( fgets(sentence[count],MAX,stdin) != NULL ){  
        length = strlen(sentence[count]) -1;         /* 计算长度时去掉末尾的换行符的长度 */
        if( length>maxlength ) maxlength = length;
        count++;
    }
    int i,j;
    for(i=0; i<maxlength; i++){
        /*printf("%d : ",i);*/
        for(j=count-1; j>=0; j--){  
            if( sentence[j][i] =='\0' || sentence[j][i] == '\n' )
                printf(" ");
            else
                printf("%c",sentence[j][i]);            
        }
        printf("\n");
    }
   
    return 0;
}

