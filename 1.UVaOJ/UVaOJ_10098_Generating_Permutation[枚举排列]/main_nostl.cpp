#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <queue>*/
/*#include <algorithm>*/
#define MAX_LINE 15
/*using namespace std;*/

char line[MAX_LINE];
char result[MAX_LINE];

void print_permutation(int length,int curr){  
    int i,j;
    if( curr == length ){           /* 递归边界 */
        for(i=0; i<length; i++)
            printf("%c",result[i]);
        printf("\n");
    }else
        for(i=0; i<length; i++){
            if( i==0 || line[i]!=line[i-1] ){  
                int c1_result=0, c2_line=0;
                for(j=0; j<length; j++)
                    if( line[j] == line[i] ) 
                        c2_line++;
                for(j=0; j<curr; j++)
                    if( result[j] == line[i] )
                        c1_result++;
                if( c1_result < c2_line ){  
                    result[curr] = line[i];
                    print_permutation(length,curr+1);
                }
            }
        }
}
void my_sort(char *source,int length){  
    int i,j;
    for(i=0; i<length; i++)
        for(j=i; j<length; j++)
            if( source[i] > source[j] ){
                char tmp = source[i];
                source[i] = source[j];
                source[j] = tmp;
            }
}

int main(){
    int n,i,length;
    scanf("%d",&n);

    for(i=0; i<n; i++){  
        scanf("%s",line);
        length = strlen(line);
        //std::sort(line,line+length);
        my_sort(line,length);
        print_permutation(length,0);
        
        printf("\n");
    }
    
    return 0;
}
