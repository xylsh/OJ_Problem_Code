#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 10010
#define MAX_QUERY 30
#define MAX_SUM 1000000

/*
 * 1.这道题可以使用暴力枚举。
 * 2.先算出所有数字两两相加的和，再在所有和中查找最接近查询数的数即可。
 */

int num[MAX_NUM];
int query[MAX_QUERY];
long long sum[MAX_SUM];
int num_amount,query_amount,sum_amount;

//计算出所有数字两两相加的和
void cal_sum(){
    int i,j;
    sum_amount = 0;
    for(i=0; i<num_amount; i++)
        for(j=i+1; j<num_amount; j++)
            sum[sum_amount++] = num[i] + num[j];
}

//得到最接近的数
long long get_closest(int num){
    long long close = sum[0];
    long long cha = abs( sum[0] - num ) ;
    long long cha_tmp;
    for(int i=1; i<sum_amount; i++){ 
        cha_tmp = abs(sum[i] - num);
        if( cha > cha_tmp ){  
            close = sum[i];
            cha = cha_tmp;
        }
    }
    return close;
}

int main(){
    int i,case_count = 0;
    while( scanf("%d",&num_amount) == 1 && num_amount != 0 ){  
        for(i=0; i<num_amount; i++)
            scanf("%d", &num[i]);
        scanf("%d", &query_amount);
        for(i=0; i<query_amount; i++)
            scanf("%d", &query[i]);

        cal_sum();   //计算出所有数字两两相加的和
        
        printf("Case %d:\n",++case_count);
        long long result;
        for(i=0; i<query_amount; i++){
            result = get_closest(query[i]);
            printf("Closest sum to %d is %lld.\n", query[i], result);
        }
    
    }
    
    return 0;
}

