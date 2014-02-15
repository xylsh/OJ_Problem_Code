#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include<functional>
#define MAX 50010
using namespace std;

/*
 * 1.贪心。给了N个数，按照题目的相加方式，无论以怎样的顺序相加,必然要相加N-1次。
 *         那么，为了使总cost最小，就要使每一步的cost最小，即计算当前所有数中最小的2个数的cost，
 *         所以每一步加最小的2个数即可。
 * 2.写完过后，测试一下这组数据：
 *   6
 *   9 9 9 9 9 9
 *   0
 * 3.优先队列priority_queue的使用参考了文章：http://www.cppblog.com/darren/archive/2009/06/09/87224.html
 */

int num[MAX];

priority_queue< int, vector<int>, greater<int> > que;   //小顶堆

int main(){
    int N,number,i;
    long long min_cost;
    while( scanf("%d", &N) == 1 && N != 0 ){  
        //get input
        for(i=0; i<N; i++){
            scanf("%d", &number);
            que.push(number);
        }  

        //initial
        min_cost = 0;

        /*while( !que.empty() ){
            printf("%d ",que.top());
            que.pop();
        }  
        printf("\n");*/

        while( que.size() > 1 ){
            int num1 = que.top();  que.pop();
            int num2 = que.top();  que.pop();
            int sum = num1 + num2;
            min_cost += sum;
            que.push(sum);
        }
        que.pop();   //把最后的一个元素抛弃掉
        
        printf("%lld\n", min_cost);
    
    }
    return 0;
}

