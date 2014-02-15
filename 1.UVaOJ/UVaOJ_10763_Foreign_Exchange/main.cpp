#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500010

/*
 * 1.将起点数组和目的地数组排序后比较是否相同即可。
 */

int origin[MAX];
int target[MAX];

int comp(const void *a, const void *b){  
    return *(int *)a - *(int *)b;          //从小到大排列
}

int main(){
    int n,i,j,flag;
    while( scanf("%d", &n) == 1 && n != 0 ){  
        for(i=0; i<n; i++)
            scanf("%d %d", &origin[i], &target[i]);

        //排序
        qsort(origin, n, sizeof(int), comp);
        qsort(target, n, sizeof(int), comp);
        
        if( memcmp(origin, target, sizeof(int) * n) == 0 )     //比较
            printf("YES\n");
        else
            printf("NO\n");
    
    }
    
    return 0;
}

