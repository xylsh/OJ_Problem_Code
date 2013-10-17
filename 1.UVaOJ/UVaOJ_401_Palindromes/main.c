#include <stdio.h>
#include <string.h>
#define MAX 30

const char mirror_char1[] = { 'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8' };
const char mirror_char2[] = { 'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8' };
char str[MAX];

int is_palindrome(char *str,int n){  
    int ok = 1;
    int i;
    for(i=0; i<n-i-1; i++){
        if( str[i] != str[n-i-1] ){  
            ok = 0;
            break;
        }
    }
    return ok;
}
int is_mirrored(char *str,int n){  
    int ok = 1;
    int i,j;
    for(i=0; i<=n-i-1; i++){
        for(j=0; j<21; j++){  
            if( str[i]==mirror_char1[j] ) break;
        }
        if( str[n-i-1] != mirror_char2[j] ){
            ok = 0;
            break;
        }
    }
    return ok;
}

int main(){ 
    /* freopen("in.in","r",stdin);*/
    /* freopen("out.out","w",stdout);*/
    int ispalindrome,ismirrored;
    ispalindrome = ismirrored = 0;
    
    while( fgets(str,MAX,stdin) != NULL && str[0] != '\n' ){
        str[ strlen(str)-1 ] = '\0';      /* 去掉换行符 */
        printf("%s",str);

        ispalindrome = is_palindrome(str,strlen(str));
        ismirrored = is_mirrored(str,strlen(str));

        if( ispalindrome && ismirrored )
            printf(" -- is a mirrored palindrome.\n");
        else if( ispalindrome )
            printf(" -- is a regular palindrome.\n");
        else if( ismirrored )
            printf(" -- is a mirrored string.\n");
        else
            printf(" -- is not a palindrome.\n");
        printf("\n");

    }

    /*printf("Time: %f\ns", (double)clock() / CLOCKS_PER_SEC);*/
    return 0;
}

