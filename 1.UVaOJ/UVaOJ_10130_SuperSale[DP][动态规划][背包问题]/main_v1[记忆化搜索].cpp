#include <stdio.h>
//#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//#include <queue>
//#include <vector>
//#include <set>
//#include <map>
#include <algorithm>
//#include <utility>
//#include <functional>
using namespace std;
#define MAX_N 1010
#define MAX_G 110
#define MAX_WEIGHT 35

int v[MAX_N];
int w[MAX_N];
int group[MAX_G];
int dp[MAX_N][MAX_WEIGHT];
int N,G;

//从第i个物品开始，挑选总重小于j的部分
int rec(int i,int j){  
    if( dp[i][j] >= 0 ){  
        return dp[i][j];
    }
    int res;
    if( i == N ){  
        res = 0;
    }else if( j < w[i] ){  
        res = rec(i+1, j);
    }else{  
        res = max(rec(i+1,j), rec(i+1,j-w[i])+v[i]);
    }
    
    return dp[i][j] = res;
}

int main(){
    int test_case,i;
    scanf("%d", &test_case);
    while( test_case-- ){  
        scanf("%d", &N);
        for(i=0; i<N; i++)
            scanf("%d %d", &v[i], &w[i]);
        scanf("%d", &G);
        for(i=0; i<G; i++)
            scanf("%d", &group[i]);
    
        //initial
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(i=0; i<G; i++){  
            ans += rec(0,group[i]);
        }
    
        printf("%d\n", ans);
    
    }

    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
