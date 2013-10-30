#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

/*
 * 先排序再搜索即可。
 */

int num[MAX];
int query[MAX];

/* 排序 */
void sort(int *nums,int length){  
    int i,j;
    for(i=0; i<length; i++)
        for(j=i; j<length; j++)
            if( nums[i] > nums[j] ){  
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
}

/* 找到:返回结果(从1开始算); 没找到:返回0 */
int search(int *source,int source_length,int que){
    int i;
    for(i=0; i<source_length; i++){
        if( source[i] == que )
            return i+1;
    }
    return 0;
}

int main(){
    int N,Q,i,j;
    int count = 0;
    while( scanf("%d %d",&N,&Q) == 2 && N!=0 ){  
        count++;

        /* get input */
        for(i=0; i<N; i++)
            scanf("%d",&num[i]);
        for(i=0; i<Q; i++)
            scanf("%d",&query[i]);
       
        sort(num,N);   /* 排序 */

        printf("CASE# %d:\n",count);

        int search_result;
        for(i=0; i<Q; i++){
            search_result = search(num,N,query[i]);
            if( search_result != 0 )
                printf("%d found at %d\n",query[i],search_result);
            else
                printf("%d not found\n",query[i]);
        }

    }

    return 0;
}
