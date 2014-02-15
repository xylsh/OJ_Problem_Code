#include <stdio.h>
#include <string.h>
#define MAX 1000010

/*
 * 1.分析发现，2只蚂蚁碰头后向各自原方向的相反方向前进，可以看成2只蚂蚁碰头时，穿过对方身体，继续向前。
 * 2.注意，所有蚂蚁掉落时间，等于最后掉落的那只蚂蚁的在杆子上行走的时间。
 */

int ant[MAX];
int pole_length,ant_amount;

inline void get_time(int *earliest, int *latest){
    int time,right;
    for(int i=0; i<ant_amount; i++){  
        right = pole_length - ant[i];    //当前蚂蚁如果向右走需要的时间(向左走的时间就是ant[i])

        //计算最短时间
        time = ant[i] < right ? ant[i] : right ;     //当前蚂蚁向离它近的一端走
        if( time > *earliest )
            *earliest = time;

        //计算最长时间
        time = ant[i] > right ? ant[i] : right ;     //当前蚂蚁向离它远的一端走
        if( time > *latest )
            *latest = time;
    }

}

int main(){
    int test_case,earliest_time,latest_time;

    scanf("%d",&test_case);
    for(int k=0; k<test_case; k++){
        scanf("%d %d", &pole_length, &ant_amount);
        for(int i=0; i<ant_amount; i++)
            scanf("%d", &ant[i]);
    
        //initial
        earliest_time = 0;
        latest_time = 0;

        get_time(&earliest_time, &latest_time);
        
        printf("%d %d\n", earliest_time, latest_time);
    
    }
        
    return 0;
}

