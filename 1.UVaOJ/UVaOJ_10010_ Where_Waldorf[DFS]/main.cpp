#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX 55
#define MAX_K 25

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=96&page=show_problem&problem=951
 * 1.使用深度优先搜索。
 * 2.注意，题目中所说的所谓"8个方向"是指，如果当前字母符合单词的第一个字母，当前字母右边方向的字母符合单词的第二个字母，
 *   那么，只有以当前字母为起点，向右方向延伸strlen(word)-1个字母都符合单词才算匹配，中途不能换方向。换句话说，就是在
 *   匹配的时候，一旦匹配方向确定，是不能拐弯的。我就是在这个地方WA的。
 */

char square[MAX][MAX];
int vis[MAX][MAX];
char words[MAX_K][MAX];
int m,n,k;
bool is_success;

//w:第几个word;alpha:当前要判断word的第几个字母；
//用（dx,dy）来表示当前匹配的方向
void dfs(int x,int y,int w,int alpha,int word_length,int dx,int dy){  
    if( alpha == word_length ){     //如果所有字母都匹配
        is_success = true;
    }else if( square[x][y] == words[w][alpha] ){
        int nx = x+dx;              //向(dx,dy)方向移动
        int ny = y+dy;
        dfs(nx,ny,w,alpha+1,word_length,dx,dy);
    }
}

int main(){
    int test_case;
    int i,j;

    scanf("%d", &test_case);
    while(test_case--){
        //input
        scanf("%d %d", &m, &n);
        getchar();            //skip '\n'
        for(i=0; i<m; i++)
            scanf("%s", square[i]);
        scanf("%d", &k);
        for(i=0; i<k; i++)
            scanf("%s", words[i]);
        
        //统一字母为小写
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                if( isupper( square[i][j] ) )
                    square[i][j] = tolower( square[i][j] );
        int length;
        for(i=0; i<k; i++){
            length = strlen(words[i]);
            for(j=0; j<length; j++)
                if( isupper(words[i][j]) )
                    words[i][j] = tolower( words[i][j] );
        } 

        //////////////////////////////////////
        for(int w=0; w<k; w++){         //依次遍历每个单词
            is_success = false;         //初始化
            for(i=0; i<m; i++){         //遍历行
                for(j=0; j<n; j++){     //遍历列
                    if( square[i][j] == words[w][0] ){     //如果当前字母==单词第一个字母
                        memset(vis, 0, sizeof(vis));       //初始化
                        //依次向8个方向遍历
                        for(int dx=-1; dx<=1; dx++){
                            for(int dy=-1; dy<=1; dy++){
                                int nx = i+dx;
                                int ny = j+dy;
                                dfs(nx, ny, w, 1, strlen(words[w]),dx,dy );
                            }
                        }
                    }
                    if( is_success ){  
                        printf("%d %d\n",i+1,j+1);
                        break;
                    }
                }
                if( is_success )  break;
            }
        }
        
        //////////////////////////////////////
        if( test_case != 0 ) printf("\n");

    }
    
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
