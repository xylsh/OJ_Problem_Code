#include <stdio.h>
#include <string.h>
/*#include <queue>*/
#include <algorithm>
#define MAX_LINE 60
using namespace std;

char line[MAX_LINE];
int main(){

    while( fgets(line,MAX_LINE,stdin) != NULL && line[0] != '#' ){  
        line[strlen(line)-1] = '\0';
        if( next_permutation(line,line+strlen(line)) )
            printf("%s\n",line);
        else
            printf("No Successor\n");
    }
    
    return 0;
}
