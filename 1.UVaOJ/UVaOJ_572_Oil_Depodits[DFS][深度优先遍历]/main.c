#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 120

char grid[MAX][MAX];
int m,n;
char line[MAX];

/* 深度优先遍历 */
void dfs(int i, int j){ 
    grid[i][j] = '*';   /* 标志访问过的点为* */
    
    int a,b;
    for(a=-1; a<=1; a++)
        for(b=-1; b<=1; b++){
            int ni = i+a; int nj = j+b;
            if( ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]=='@' ){
                dfs(ni,nj);
            }
        }

}

int main(){
    int count,i,j;
    scanf("%d %d",&m,&n);
    while( m != 0 ){
        getchar();  /* important! : skip '\n' */
        count = 0;
        memset(grid,0,sizeof(grid));

        for(i=0; i<m; i++){
            fgets(line,MAX,stdin);
            for(j=0; j<n; j++){  
                grid[i][j] = line[j];
            }
        }

        for(i=0; i<m; i++)
            for(j=0; j<n; j++){  
                if( grid[i][j] == '@' ){  
                    dfs(i,j);
                    count++;
                }
            }

        printf("%d\n",count);

        scanf("%d %d",&m,&n);
    }

    return 0;
}
