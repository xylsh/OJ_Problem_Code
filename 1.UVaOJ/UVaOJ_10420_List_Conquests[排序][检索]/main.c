#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRY 2010
#define MAX_LINE 80
typedef struct{  
    char country[MAX_LINE];
    int count;
}Node;

Node country[MAX_COUNTRY];

/* 没找到返回0,找到了返回所在下标(所以country数组是从下标1开始存放国家的) */
int find(int n, char* str){  /* n表示元素个数+1 */
    int i,found;
    found = 0;
    for(i=1; i<n; i++){
        if( strcmp(str, country[i].country) == 0 )
            found = i;
    }
    return found;
}
int main(){ 
     /*freopen("file.out","r",stdin);
     freopen("out.out","w",stdout);*/

    int n,i,j;
    scanf("%d",&n);

    memset(country,0,sizeof(country));

    int count = 1;           /* 从下标1开始存放(因为find()函数) */
    char tmp[MAX_LINE];
    for(i=0; i<n; i++){
        scanf("%s", tmp);
        int found = find(count,tmp);
        if( found == 0 ){   /* 如果没找到 */
            strcpy( country[count].country, tmp );
            country[count].count++;
            count++;
        }else{              /* 如果找到了 */
            country[found].count++;
        }
        
        while(getchar() != '\n') ;    /* 跳过名字 */
    }
    
    int tmp2;
    /* 冒泡排序 */
    for(i=1; i<count; i++){
        for(j=i; j<count; j++){
            if( strcmp(country[i].country,country[j].country) > 0 ){  
                /* 交换元素 */
                strcpy(tmp,country[i].country);
                tmp2 = country[i].count;
                strcpy(country[i].country,country[j].country);
                country[i].count = country[j].count;
                strcpy(country[j].country, tmp);
                country[j].count = tmp2;
            }
        }
    }

    for(i=1; i<count; i++){ 
        printf("%s %d\n",country[i].country, country[i].count);
    }
    
    return 0;
}
