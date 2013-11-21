#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <queue>*/
#include <algorithm>
#define MAX_LINE 15
using namespace std;

char line[MAX_LINE];
int main(){
    int n,i,length;
    scanf("%d",&n);

    for(i=0; i<n; i++){  
        scanf("%s",line);
        length = strlen(line);
        sort(line,line+length);
        do{
            printf("%s\n",line);
        }while( next_permutation(line,line+length) );
        printf("\n");
    }
    
    return 0;
}
