#include <stdio.h>
int main(){ 
     /*freopen("file.out","r",stdin);
     freopen("out.out","w",stdout);*/
    int m,n;
    while( scanf("%d %d",&m,&n) == 2 ){  
        printf("%d\n",m*n-1);   /* n-1+n*(m-1) */
    }

    return 0;
}
