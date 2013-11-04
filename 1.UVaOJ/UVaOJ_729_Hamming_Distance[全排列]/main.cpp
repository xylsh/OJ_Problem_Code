#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20

/*
 * 1.origin为全0，所以Hamming distance的值就是另一个数字中的1的个数。
 * 2.因为是按字典序排列，所以每组输入的第一个输出必定是前面全是0,最后H位为1,
 * 所以问题就转化为了对第一个输出行的全排列问题。
 */

int line[MAX_LENGTH];
int result[MAX_LENGTH];

void print_permutation(int length,int curr){  
    int i,j;
    if( curr == length ){         /* 递归边界 */
        for(i=0; i<length; i++)
            printf("%d",result[i]);
        printf("\n");
    }else
        for(i=0; i<length; i++){
            if( i==0 || line[i]!=line[i-1] ){  
                int c_line=0, c_result=0;
                for(j=0; j<length; j++)
                    if( line[j] == line[i] )
                        c_line++;
                for(j=0; j<curr; j++)
                    if( result[j] == line[i] )
                        c_result++;
                if( c_result < c_line ){
                    result[curr] = line[i];
                    print_permutation(length,curr+1);
                }
            }
        }
}

int main(){
    int amount,length,HD,i,j;
    scanf("%d",&amount);
    for(i=0; i<amount; i++){  
        scanf("%d %d",&length,&HD);
        /* initial */
        memset(line,0,sizeof(line));

        for(j=length-1; j>=length-HD; j--)
            line[j] = 1;

        print_permutation(length,0);
        if( i != amount-1 )  printf("\n");
    }
    
    return 0;
}
