#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1310
 * 1.这是关于最小生成树的题目。
 * 2.首先使用Kruskal算法+并查集得到构成最小生成树的边(从小到大排列)，
 *   然后，因为有S个卫星频道，所以可以省去S-1条边，我们当然省去最长的边。
 *   最后，剩余的构成最小生成树的边中，最大权重边的权重就是无线电必须达到的距离值。
 */

#define MAX_POINT 505
#define MAX_EDGE 127260   //504+503+...+3+2+1 = 127260

struct point{  
    int x,y;
};

point points[MAX_POINT];
int u[MAX_EDGE];
int v[MAX_EDGE];
double w[MAX_EDGE];   //权重
int r[MAX_EDGE];      //按权重从小到大排序后的边的序号
int p[MAX_POINT];     //并查集
int mst[MAX_EDGE];    //记录添加到MST的边的序号

//返回点a与点b的距离
double get_distance(point a,point b){  
    return sqrt( pow(a.x-b.x,2) + pow(a.y-b.y, 2) );
}

int cmp(const int a, const int b){  
    return w[a] < w[b];
}

//返回mst权重最大边的权重
double get_max_weight(int length){
    double max = -1;
    for(int i=0; i<length; i++)
        if( max < w[ mst[i] ] )
            max = w[ mst[i] ];
    return max;
}

//返回端点a所在树的根
int find(int a){  
    return p[a] == a ? a : p[a] = find( p[a] ) ;
}

int main(){
    int test_case;
    scanf("%d", &test_case);

    int S,     //the number of satellite channels
        P,     //the number of outposts
        edge;
    double ans;
    while( test_case-- ){  

        scanf("%d %d", &S, &P);
        for(int i=0; i<P; i++)
            scanf("%d %d" , &points[i].x, &points[i].y);

        edge = ans = 0;

        //得到边
        for(int i=0; i<P; i++)
            for(int j=i+1; j<P; j++){  
                u[edge] = i;  v[edge] = j;
                w[edge] = get_distance(points[i], points[j]);
                edge++;
            }

        for(int i=0; i<edge; i++)  r[i] = i;
        for(int i=0; i<P; i++) p[i] = i;
        sort(r, r+edge, cmp);

        int have_add_MST = 0;
        for(int i=0; i<edge; i++){     //遍历所有边
            int curr_edge = r[i];
            int root_u = find( u[curr_edge] );
            int root_v = find( v[curr_edge] );
            if( root_u != root_v ){        //如果不在同一个连通分量
                mst[have_add_MST++] = curr_edge;      //当前边加入mst
                p[ root_u ] = root_v;      //合并连通分量
            }
        }

        have_add_MST = have_add_MST - ( S-1 );    //S个卫星频道可以省去S-1条边
        ans = get_max_weight(have_add_MST);
    
        printf("%.2f\n", ans);
    
    }
    
    //printf("time used = %f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
