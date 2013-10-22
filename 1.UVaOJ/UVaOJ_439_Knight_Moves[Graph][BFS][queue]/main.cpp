#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

#define INF 100000
using namespace std;
/*
 * 使用宽度优先遍历(BFS)，从起点出发，走完所有能够到达的格子，
 * 用一个二维数组保存走到（能够走到的）格子的步数。
 * 终点格子保存的步数即为结果。
 */
typedef struct Node{  
    char alpha;
    int num;
}Node;

int dx[] = { -2,-2,-1,-1, 1, 1, 2, 2 };   /* num的位移向量 */
int dy[] = { -1, 1,-2, 2,-2, 2,-1, 1 };   /* alpha的位移向量 */
int chessboard[10][10];    /* 保存能走到的各个格子的步数 */
queue<Node*> q;

/* 设置走到格子s的步数 */
void set_step(Node* s,int value){  
    chessboard[s->num][s->alpha-'a'] = value;
}
/* 获得走到格子的步数 */
int get_step(int num,char alpha){  
    return chessboard[num][alpha-'a'];
}
/* 获得走到格子s的步数 */
int get_step(Node* s){  
    return chessboard[s->num][s->alpha-'a'];
}
/* 把格子s能够1步走到的所有格子加入队列 */
void add_available_node(Node* s){  
    Node* node;
    int i,nnum;
    char nalpha;
    for(i=0; i<8; i++){  
        nalpha = s->alpha+dx[i];  nnum = s->num+dy[i];
        if( nalpha>='a' && nalpha<='h' && nnum>=0 && nnum<8 
                && get_step(s)+1 < get_step(nnum,nalpha) ){     /* important */
            node = (Node*)malloc(sizeof(Node));
            node->alpha = nalpha;  node->num = nnum;
            q.push(node);
            set_step(node,get_step(s)+1);
        }
    }
}

int main(){
    /*freopen("in.in","r",stdin);*/
    /*freopen("out.out","w",stdout);*/
    int i,j;
    char line[10];
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    while( fgets(line,10,stdin) != NULL ){
        for(i=0; i<10; i++)
            for(j=0; j<10; j++)
                chessboard[i][j] = INF;   /* initial */
            
        a->alpha = line[0];   a->num = line[1]-'1';
        b->alpha = line[3];   b->num = line[4]-'1';
        set_step(a,0);
        q.push(a);
        while( !q.empty() ){  
            Node* n = q.front();  q.pop();
            add_available_node(n);
        }

        printf("To get from %c%d to %c%d takes %d knight moves.\n",
                a->alpha,a->num+1,b->alpha,b->num+1,get_step(b));

    }

    return 0;
}
