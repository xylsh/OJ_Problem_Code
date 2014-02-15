#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=115&page=show_problem&problem=1432
 * 1.概率计算题。
 * 2.参加节目者选门分为2个步骤，1.首先选一扇门，2.主持人开门后，参加节目者换成选另一扇未开之门。
 * 3.分析样例后，发现 最终所求概率p = p1 + p2,
 *               其中,p1表示参加节目者第一步选择的是cow的门并第二步换门后选中car的概率，
 *                    p2表示参加节目者第一步选择的是car的门并第二步换门后选中car的概率.
 * 4.数据类型要用double，用float会wrong answer.
 */

int main(){
    double cows,cars,show,doors;
    double p1,p2;   //概率
    while( scanf("%lf %lf %lf", &cows, &cars, &show) == 3 ){
        doors = cows + cars; 
        p1 = ( cows / doors ) * ( cars / (doors - show - 1) );             //计算p1
        p2 = ( cars / doors ) * ( (cars - 1) / ( doors - show - 1 ) );     //计算p2

        printf("%.5f\n", p1+p2);

    }

    return 0;
}
