#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAX 1010

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1346
 * 1.这是最长公共子序列问题，使用DP解决。
 * 2.很多算法书在讲DP时都会把LCS作为例题来讲解, 百科也有详细解释。
 */

char seq1[MAX];
char seq2[MAX];
int dp[MAX][MAX];

int main(){
    int i,j;
    while( fgets(seq1,MAX,stdin) != NULL ){  
        fgets(seq2, MAX, stdin);
        seq1[ strlen(seq1) - 1 ] = '\0';
        seq2[ strlen(seq2) - 1 ] = '\0';

        memset(dp, 0, sizeof(dp));

        int seq1_len = strlen( seq1 );
        int seq2_len = strlen( seq2 );

        for(i=0; i<seq1_len; i++){
            for(j=0; j<seq2_len; j++){
                if( seq1[i] == seq2[j] ){  
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{ 
                    dp[i+1][j+1] = max( dp[i][j+1], dp[i+1][j] );
                }
            }
        }

        printf("%d\n", dp[seq1_len][seq2_len]);
    }
    
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
