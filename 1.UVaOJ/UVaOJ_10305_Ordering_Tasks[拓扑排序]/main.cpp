#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
using namespace std;
#define MAX_N 110
#define MAX_M 1000

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=105&page=show_problem&problem=1246
 * 1.这道题考察拓扑排序。
 * 2.白书上讲的拓扑排序不太好理解，这是百度百科的算法：
 *   step1:从有向图中选择一个没有前驱(即入度为0)的顶点并且输出它.
 *   step2:从图中删去该顶点,并且删去从该顶点发出的全部有向边.
 *   step3:重复上述两步,直到剩余的网中不再存在没有前趋的顶点为止.
 */

vector<int> E[MAX_M];   //记录有向边
int rudu[MAX_N];        //rudu[i]表示结点i的入度
int ans[MAX_N];         //保存排序结果
int n,m;

//删去从结点i发出的全部有向边
void del_edge(int i){
    while( !E[i].empty() ){  
        rudu[ E[i].back() ]--;
        E[i].pop_back();
    }
}

int main(){
    int i;
    while( scanf("%d %d",&n,&m) == 2 && n!=0 ){  

        //initial
        memset(rudu, 0, sizeof(rudu));
        memset(ans, 0, sizeof(ans));

        int a,b;
        for(i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            E[a].push_back(b);      //保存有向边
            rudu[b]++;              //结点b的入度+1
        }

        for(i=1; i<=n; i++){  
            int j=1;
            while( rudu[j] != 0 ){     //找到入度为0的结点
                j++;
            }
            ans[i] = j;          //把入度为0的结点放入排序序列
            rudu[j] = -1;        //把该结点入度改为-1,以此标记该结点已经被使用过了

            del_edge(j);         //删去从该结点发出的全部有向边
        }

        //output
        for(i=1; i<=n; i++){
            printf("%d",ans[i]);
            if( i != n )  printf(" ");
        }
        printf("\n");

    }
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
