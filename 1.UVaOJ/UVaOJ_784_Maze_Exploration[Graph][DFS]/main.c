#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 40
#define MAX_LENGTH 90

/*
 * 从起点开始深度优先遍历，把' '全部替换成'#'即可。
 */

/* 位移向量 */
int dx[] = { 0, 0,1,-1 };
int dy[] = { 1,-1,0, 0 };

char maze[MAX_LINE][MAX_LENGTH];
char line[MAX_LENGTH];
int row;
/* 深度优先遍历 */
void dfs(int x,int y){  
    maze[x][y] = '#';
    int i,nx,ny;
    for(i=0; i<4; i++){  
        nx = x+dx[i];   ny = y+dy[i];
        if( nx>=0 && nx<row && ny>=0 
                && ny<strlen(maze[nx])     /* 迷宫每行宽度可能不一样 */
                && maze[nx][ny]==' ' ){  
            dfs(nx,ny);
        }
    }
}

int main(){
    /*freopen("in.in","r",stdin);*/
    /*freopen("out.out","w",stdout);*/
    int n,i,j,k,startx,starty;
    scanf("%d",&n);
    getchar();   /* skip '\n' */

    for(k=0; k<n; k++){
        /* initial */
        row = 0;
        memset(maze,0,sizeof(maze));

        fgets(line,MAX_LENGTH,stdin);
        while( line[0] != '_' ){  
            int length = strlen(line)-1;
            for(i=0; i<length; i++ ){  
                maze[row][i] = line[i];
                if( line[i] == '*' ){  startx = row; starty = i;  }   /* 找到起点 */
            }
            row++;
            fgets(line,MAX_LENGTH,stdin);
        }

        dfs(startx,starty);

        /* output */
        for(i=0; i<row; i++){
            int length = strlen(maze[i]);
            for(j=0; j<length; j++){  
                printf("%c",maze[i][j]);
            }
            printf("\n");
        }
        printf("%s",line);
    }
    return 0;
}

