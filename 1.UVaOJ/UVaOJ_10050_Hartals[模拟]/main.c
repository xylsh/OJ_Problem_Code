#include <stdio.h>
/* #include <stdlib.h>*/
#include <string.h>
/* #include <ctype.h> */
/*#include <math.h>*/
/* #include <time.h> */
/* #include <assert.h> */
#define MAX_PARTY 120
#define MAX_TESTCASE 100000
/*
 * 依次判断每一天有没有罢工即可.
 */
int parties[MAX_PARTY];
int result[MAX_TESTCASE];
int main(){ 
     /*freopen("file.out","r",stdin);
     freopen("out.out","w",stdout);*/

    int testcase_amount,days,party_amount,i,j,k;
    scanf("%d",&testcase_amount);
    memset(parties,0,sizeof(parties));

    for(k=0; k<testcase_amount; k++){
        memset(parties,-1,sizeof(parties));

        scanf("%d %d",&days,&party_amount);
        for(i=0; i<party_amount; i++)  
            scanf("%d",&parties[i]);

        for(i=1; i<=days; i++){
            if( i%7 == 0 || (i+1)%7 == 0 ){     /* 如果是周6周5 */  
                continue;
            }
            for(j=0; j<party_amount; j++){
                if( i%parties[j] == 0 ) { result[k]++; break; }  /* 如果有罢工 */
            }
        }
    }
    
    for(i=0; i<testcase_amount; i++){
        printf("%d\n",result[i]);
    }

    /*printf("Time: %f\ns", (double)clock() / CLOCKS_PER_SEC);*/
    return 0;
}
