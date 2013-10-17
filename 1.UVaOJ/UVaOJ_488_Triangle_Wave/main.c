#include <stdio.h>
#define MAX 1000

int input_data[MAX][2];
int main(){ 
    /*freopen("in.in","r",stdin);*/
    /*freopen("out.out","w",stdout);*/

    int n;   /* 输入多少组数据 */
    scanf("%d",&n);
    int i,j,k,a;
    for(i=0; i<n; i++){  
        scanf("%d %d", &input_data[i][0], &input_data[i][1]);
    }

    for(i=0; i<n; i++){        /* 迭代每组数据 */
        for(k=0; k<input_data[i][1]; k++){           /* 输出Frequency个波浪 */
            for(j=1; j <= input_data[i][0]; j++){    /* 输出前半个三角形 */
                for(a=0; a<j; a++){
                    printf("%d",j);
                } 
                printf("\n");
            }
            for(j=input_data[i][0]-1; j>=1; j--){    /* 输出后半个三角形 */
                for(a=0; a<j; a++){  
                    printf("%d",j);
                } 
                printf("\n");
            }
            if( i!=n-1 || k!=input_data[i][1]-1 )    /* 如果是最后一组数据的最后一个波浪,则不换行 */
                printf("\n");
        }
    }
       
    return 0;
}

