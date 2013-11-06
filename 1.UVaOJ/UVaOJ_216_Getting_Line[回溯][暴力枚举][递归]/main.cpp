#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 999999999
#define MAX 10

/*
 * 暴力枚举。
 * 1.把每个结点当作第一个结点，依次连接每一个结点，枚举完所有顺序。
 * 2.如果连接某一结点时，当前线缆长度已经不小于目前找到的最小长度，则剪枝。
 */

using namespace std;
typedef struct Node{  
    int x,y;
}Node;

Node *vertex[MAX];

int order[MAX],order_final[MAX],vis[MAX],n;
float min_cable;

//获得2个结点的距离
float get_distance(int start,int end,int *order){  
    if( start < 0 )
        return 0;
    int dx = vertex[ order[start] ]->x - vertex[ order[end] ]->x;
    int dy = vertex[ order[start] ]->y - vertex[ order[end] ]->y;
    float distance = (float)sqrt(dx*dx + dy*dy);
    return distance;
}

//枚举
void dfs(int curr,float cable){   //curr表示当前在排第curr个结点
    int i;
    if( curr == n ){     //递归边界  
        if( min_cable > cable ){
            min_cable = cable;
            for(i=0; i<n; i++)
                order_final[i] = order[i];
        }  
    }else{  
        for(i=0; i<n; i++){  
            if( vis[i] == 0 && cable < min_cable){  //[剪枝]如果当前的线缆长度>=目前找到的最小长度，那么就没有沿着这条路径遍历下去的必要了。
                order[curr] = i;
                vis[i] = 1;         //前一个结点连这个结点(i结点)
                dfs(curr+1, cable+ get_distance(curr-1,curr,order) );
                order[curr] = -1;
                vis[i] = 0;         //前一个结点不连这个结点(i结点)
            }
        }
    }
}

int main(){
    int count = 0,i;
    Node *node;
    while( scanf("%d",&n) && n != 0 ){
        //initial
        min_cable = INF;
        memset(vis,0,sizeof(vis));
        memset(order,-1,sizeof(order));
        memset(order_final,-1,sizeof(order_final));

        count++;
        
        //get input
        for(i=0; i<n; i++){
            node = (Node *)malloc(sizeof(Node));
            scanf("%d %d", &node->x, &node->y);
            vertex[i] = node;
        }

        dfs(0,0);
        
        //output
        printf("**********************************************************\n");
        printf("Network #%d\n",count);
        float distance;
        Node *node2;
        for(i=0; i<n-1; i++){
            node = vertex[ order_final[i] ];
            node2 = vertex[ order_final[i+1] ];
            distance = get_distance(i,i+1,order_final) + 16;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",node->x,node->y,node2->x,node2->y,distance);
        }
        min_cable += 16 * (n-1);
        printf("Number of feet of cable required is %.2f.\n",min_cable);

    }

    return 0;
}
