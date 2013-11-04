#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#define MAX_GROUP 85
using namespace std;

/*
 * 1.暴力枚举。用DFS。
 * 2.画出解答树。
 * 3.如果有4组分组，则解答树草图如下(数字表示input的分组编号)：
 * (X,X,X)->(1,X,X)->(1,2,X)->(1,2,3)
 *       |        |        |->(1,2,4)
 *       |        |
 *       |        |->(1,3,X)->(1,3,4)   //之所以没有结点(1,3,2),是因为观察发现,如果当前要填充的'X'比前一个数字小,那必定是重复 结点/分支，所以当前要填充的'X'要比前一个数字大，以避免重复。
 *       |        |
 *       |        |->(1,4,X)            //为避免重复 结点/分支 ，当前要填充的'X'要比前一个数字大才行，所以这个结点没有子结点了。
 *       |
 *       |->(2,X,X)->(2,3,X)->(2,3,4)
 *       |        |->(2,4,X)
 *       |
 *       |->(3,X,X)->(3,4,X)
 *       |
 *       |->(4,X,X)
 *   
 */
 

typedef struct Group{  
    int a,b,c,s;
}Group;

Group *groups[MAX_GROUP];
int n;   //input的小组数量
int max_score;
Group *order[3];

//获得当前分组得分
inline int get_order_score(){ 
    return order[0]->s + order[1]->s + order[2]->s;
}

//判断当前分组是否包含了全部9个人
bool is_include_all_people(){
    int flag[10];
    memset(flag,0,sizeof(flag));
    for(int i=0; i<3; i++){
        flag[order[i]->a] = 1;
        flag[order[i]->b] = 1;
        flag[order[i]->c] = 1;
    }
    bool include_all_people = true;
    for(int i=1; i<10; i++){
        if(flag[i] == 0){
            include_all_people = false;
            break;
        }
    }
    return include_all_people;
}

//深度优先搜索
void dfs(int curr_order,int current_team){

    if(curr_order == 3){      //递归边界
        //判断该排列是否含9人，如果是，记录得分
        if( is_include_all_people() ){
            int score_tmp = get_order_score();
            if( max_score < score_tmp )
                max_score = score_tmp;
        }
    }else{  
        for(int i=current_team; i<=n; i++){
            order[curr_order] = groups[i];
            dfs(curr_order+1,i+1);
        }
    }
}

int main(){
    int i,testcase = 0;;

    while( scanf("%d",&n) == 1 && n != 0 ){
        //initial
        max_score = -1;

        //get input
        Group *g;
        for(i=1; i<=n; i++){
            g = (Group *)malloc(sizeof(Group));
            scanf("%d %d %d %d",&g->a,&g->b,&g->c,&g->s);
            groups[i] = g;    //从下标为1的地方开始存
        }
    
        dfs(0,1);
    
        printf("Case %d: %d\n",++testcase,max_score);

        //释放内存
        for(int i=1; i<n; i++){  
            free(groups[i]);
        }
    
    }
    return 0;
}

