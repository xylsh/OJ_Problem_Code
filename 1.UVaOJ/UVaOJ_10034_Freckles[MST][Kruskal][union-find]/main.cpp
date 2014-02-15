#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=116&page=show_problem&problem=975
 * 1.最小生成树的题目，可以使用Kruskal 或 Prim算法
 * 2.使用Kruskal算法时，可以使用并查集的方法来判断两个端点是否在同一个连通分量中。
 */

#define MAX_POINT 105
#define MAX_EDGE 5460   //104+103+...+3+2+1 = 5460

struct point{  
    double x,y;
};

point points[MAX_POINT];      //保存端点,下标作为端点序号
int u[MAX_EDGE];              //边(u,v)的端点u(序号)
int v[MAX_EDGE];              //边(u,v)的端点v(序号)
double w[MAX_EDGE];           //边的权重
int p[MAX_POINT];     //并查集，p[i]=x表示端点i的父结点是端点x，若端点i是根结点(没有父结点)，则令x=i
int r[MAX_EDGE];      //把权重从小到大排序后的边的序号

//返回2点之间的距离
inline double get_distance(point a, point b){  
    return sqrt( pow(a.x-b.x, 2) + pow(a.y-b.y, 2) );
}

//从小到大排序
inline int cmp(const int a, const int b){
    return w[a] < w[b];
}

//返回端点x所在集合的代表元，即所在树的根结点的序号
int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]) ;
}

int main(){
    int test_case;
    scanf("%d", &test_case);

    int n,            //端点数
        edges;        //边数
    double ans;       //最短路径
    while( test_case-- ){  

        //initial
        edges = ans = 0;
        scanf("%d", &n);        
        //初始化并查集 or 初始化连通分量，让每个点自成一个独立的连通分量
        for(int i=0; i<n; i++){  p[i] = i;  }

        //得到结点坐标
        for(int i=0; i<n; i++)
            scanf("%lf %lf", &points[i].x, &points[i].y);

        //得到所有边
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){  
                u[edges] = i;  v[edges] = j;
                w[edges] = get_distance(points[i],points[j]);
                edges++;
            }
        }
        
        for(int i=0; i<edges; i++){  r[i] = i;  }   //初始化边序号
        sort(r, r+edges, cmp);   //排序边
        //for(int i=0; i<edges; i++){  printf("%d (%d,%d) : %lf\n", r[i], u[r[i]], v[r[i]], w[r[i]]);  }
        
        for(int i=0; i<edges; i++){
            int curr_edge = r[i];    //剩余边中，最短边的序号
            int root_u = find( u[curr_edge] );    //当前边(u,v)的端点u所在集合的代表元
            int root_v = find( v[curr_edge] );    //当前边(u,v)的端点v所在集合的代表元
            if( root_u != root_v ){    //如果u,v不再同一个连通分量中
                ans += w[curr_edge];
                p[root_u] = root_v;    //合并连通分量(直接把 u所在树的根 设置为 u所在树的根的儿子)
            }
        }

        //output
        printf("%.2lf\n", ans);
        if( test_case != 0 )  printf("\n");
    }
    
    return 0;
}
