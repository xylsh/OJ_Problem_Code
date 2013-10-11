#include <stdio.h>
#include <string.h>
#define MAX 150
/*
 * 注意测试以下用例：
 * 1.若干个加数长度不等，如 123+4;
 * 2.和的最高位需要进位, 如 9+8;
 */
char num[MAX][MAX];
int sum[MAX];

/* 求出所有加数最大长度 */
int max_length(){  
    int i,maxlength = 0;
    for(i=0; i<MAX; i++){  
        if( strlen(num[i]) > maxlength)
            maxlength = strlen(num[i]);
    }
    return maxlength;
}

/* 反转字符串(避免测试1的问题) */
void reverse(char *str,int length){
    int i;
    char c;
    for(i=0; i<length-i-1; i++){
        c = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = c;
    }
}
int main(){ 
    /* freopen("in.in","r",stdin);*/
    /* freopen("out.out","w",stdout);*/
    memset(num,0,sizeof(num));
    memset(sum,0,sizeof(sum));

    int count = 0;
    while( scanf("%s",num[count]) && num[count][0] != '0' ){  
        reverse( num[count],strlen(num[count]) );
        count++;
    }

    int i,j,k,he;
    k = he = 0;
    int maxlength = max_length();
    /* 开始计算 */
    for(j=0; j<maxlength; j++){
        for(i=0; i<count; i++){
            if( num[i][j] != 0)  
                he += num[i][j] - '0';
        }
        sum[k++] = he%10;
        he = he/10;
    }
    if( he != 0 ){    /* 如果和的最高位需要进位(避免测试2的问题) */
        sum[k] = he;
    }

    /* output sum */
    for(i=MAX-1; i>=0; i--){   /* 寻找和的最高位(跳过前导0) */
        if( sum[i] != 0 )
            break;
    }
    for(j=i; j>=0; j--){
        printf("%d",sum[j]);
    }
    printf("\n");

    /*printf("Time: %f\ns", (double)clock() / CLOCKS_PER_SEC);*/
    return 0;
}

