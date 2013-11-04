#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#define INF 2000000000
using namespace std;

/*
 * 1.隐式图其实可以看作解答树，是有重复结点的解答树，所以要注意去重，对已经访问过的结点(分支)剪枝。
 * 2.画出解答树，从根结点出发，BFS遍历解答树，对于已经访问过的结点不再次访问。
 * 3.如何判断当前 结点/状态 是否已经访问过呢？
 *   方法有很多，我用的是：根据当前状态的特征生成不同状态不会重复的哈希码，用一个set集合vis记录该哈希码，
 *   以后的状态如果生成的哈希相同，就表示该状态已经访问过了。
 */

//状态结点
typedef struct State{  
    int a,b,c,have_poured;
}State;

int n,a_volume,b_volume,c_volume,d;   //a_volume表示Ajug的容量
int poured_min;    //最小的倾倒水总量
set<int> vis;      //结点查找表；记录访问过的状态


int pour(int *src,int *dest,int dest_max);     //src向dest倒水.返回倾泻了多少水
void copy_state(State *src,State *dest);       //拷贝状态
int get_hash(State *state);      //每个状态生成不重复的整数
void add_state(State *state);    //添加状态到结点查找表(记录访问过的结点)
bool is_repeat(State *state);    //是否已经访问过状态state(即是否与已保存哈希码重复)
bool is_success(State *state);   //state状态是否有jug有d单位的水
void bfs();                      //对 解答树/隐式图 进行宽度优先遍历


int main(){
    int k;
    scanf("%d",&n);
    for(k=0; k<n; k++){
        scanf("%d %d %d %d",&a_volume,&b_volume,&c_volume,&d);
        //initial
        poured_min = INF;

        bfs();
    
        while( poured_min == INF ){    //如果没法达到d单位的水
            d--;
            bfs();
        }

        printf("%d %d\n",poured_min,d);

    }

    return 0;
}

//src向dest倒水.返回倾泻了多少水
int pour(int *src,int *dest,int dest_max){
    int rest = dest_max - *dest;
    if( *src >= rest ){
        *dest = dest_max;
        *src = *src - rest;
        return rest;
    }else{
        int tmp = *src;
        *dest = *dest + *src;
        *src = 0;
        return tmp;
    }
}

void copy_state(State *src,State *dest){
    dest->a = src->a;
    dest->b = src->b;
    dest->c = src->c;
    dest->have_poured = src->have_poured;
}
//每个状态生成不重复的整数
int get_hash(State *state){  
    int hash;
    hash = (state->a + 100)*1000000 + (state->b + 100)*1000;   //因为总水量不变，所以a和b定了c就定了
        //+ (state->c + 100);
    return hash;
}
void add_state(State *state){  
    vis.insert( get_hash( state ) );
}
bool is_repeat(State *state){  
    return vis.count( get_hash(state) ) > 0 ? true : false;
}
bool is_success(State *state){
    if( state->a == d || state->b == d || state->c == d)
        return true;
    return false;
}
void bfs(){ 
    queue<State *> que;
    vis.clear();      //initial查找表

    //初始状态
    State *s = (State *)malloc(sizeof(State));
    s->a = 0; s->b = 0; s->c = c_volume; s->have_poured = 0;

    add_state(s);
    que.push(s);

    while( !que.empty() ){  
        State *currstate = que.front();  que.pop();

        //todo:判断是否已经成功(有jug水量==d)
        //如果有，则记录倾倒水量总和，弹出结点，然后continue;(次数少不代表量少)
        if( is_success(currstate) ){
            if( poured_min > currstate->have_poured )
                poured_min = currstate->have_poured;
            continue;
        }

        //开始倒水
        if( currstate->a != 0 ){        //如果ajug有水
            if( currstate->b != b_volume ){    //如果能向bjug倒水
                //a->b a倒水给b
                //判断状态是否重复，不重复则把状态加入队列
                //todo:如果不倒水
                State *tmp = (State *)malloc(sizeof(State));
                copy_state(currstate, tmp);
                int pour_tmp = pour(&tmp->a, &tmp->b, b_volume);  //a->b a倒水给b
                if( !is_repeat(tmp) ){     //判断状态是否重复，不重复则把状态加入队列
                    tmp->have_poured += pour_tmp;
                    que.push(tmp);
                    add_state(tmp);
                }
            }
            
            if( currstate->c != c_volume ){    //如果能向cjug倒水
                //a->c
                //判断状态是否重复，不重复则把状态加入队列
                //todo:如果不倒水
                State *tmp = (State *)malloc(sizeof(State));
                copy_state(currstate, tmp);
                int pour_tmp = pour(&tmp->a, &tmp->c, c_volume);
                if( !is_repeat(tmp) ){
                    tmp->have_poured += pour_tmp;
                    que.push(tmp);
                    add_state(tmp);
                }
            }
        }
        if( currstate->b != 0 ){        //如果bjug有水
            if( currstate->a != a_volume ){    //如果能向ajug倒水
                //b->a
                //判断状态是否重复，不重复则把状态加入队列
                //todo:如果不倒水
                State *tmp = (State *)malloc(sizeof(State));
                copy_state(currstate, tmp);
                int pour_tmp = pour(&tmp->b, &tmp->a, a_volume);
                if( !is_repeat(tmp) ){
                    tmp->have_poured += pour_tmp;
                    que.push(tmp);
                    add_state(tmp);
                }
            }
            if( currstate->c != c_volume ){    //如果能向cjug倒水
                //b->c
                //判断状态是否重复，不重复则把状态加入队列
                //todo:如果不倒水
                State *tmp = (State *)malloc(sizeof(State));
                copy_state(currstate, tmp);
                int pour_tmp = pour(&tmp->b, &tmp->c, c_volume);
                if( !is_repeat(tmp) ){
                    tmp->have_poured += pour_tmp;
                    que.push(tmp);
                    add_state(tmp);
                }
            }
        }
        if( currstate->c != 0 ){        //如果cjug有水
            if( currstate->a != a_volume ){    //如果能向ajug倒水
                //c->a
                //判断状态是否重复，不重复则把状态加入队列
                //todo:如果不倒水
                State *tmp = (State *)malloc(sizeof(State));
                copy_state(currstate, tmp);
                int pour_tmp = pour(&tmp->c, &tmp->a, a_volume);
                if( !is_repeat(tmp) ){
                    tmp->have_poured += pour_tmp;
                    que.push(tmp);
                    add_state(tmp);
                }
            }
            if( currstate->b != b_volume ){    //如果能向bjug倒水
                //c->b
                //判断状态是否重复，不重复则把状态加入队列
                //todo:如果不倒水
                State *tmp = (State *)malloc(sizeof(State));
                copy_state(currstate, tmp);
                int pour_tmp = pour(&tmp->c, &tmp->b, b_volume);
                if( !is_repeat(tmp) ){
                    tmp->have_poured += pour_tmp;
                    que.push(tmp);
                    add_state(tmp);
                }
            }
        }

    }
}
