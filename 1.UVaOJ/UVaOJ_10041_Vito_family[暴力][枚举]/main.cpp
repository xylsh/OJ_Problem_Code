#include <stdio.h>
#include <string.h>
#define INF 2000000000
#define MAX 510

/*
 * 1.经分析，要使距离最短，则house应该建在其中一个亲戚的相同位置。
 * 2.暴力枚举.每一个亲戚处依次假设为house，算出总距离，取其中最小的距离。
 */

int relatives[MAX];
int min_distance;    //distance最大不超过500*30000,int能够存放

//获得绝对值
inline int get_abs(int num){  
    return num>=0 ? num : -num;
}

//获得house到各个亲戚的距离和
int get_distance(int house,int r){  
    int i,distance = 0;
    for(i=0; i<r; i++){  
        distance += get_abs( house - relatives[i] );
    }
    return distance;
}

int main(){
    int n,r,i,k,house;
    scanf("%d",&n);

    for(k=0; k<n; k++){  
        scanf("%d",&r);

        //initial
        min_distance = INF;

        for(i=0; i<r; i++){  
            scanf("%d",&relatives[i]);
        }
    
        int distance_tmp;
        for(i=0; i<r; i++){  
            house = relatives[i];
            distance_tmp = get_distance(house,r);
            if(min_distance > distance_tmp)
                min_distance = distance_tmp;
        }

        printf("%d\n",min_distance);
    
    }
    
    return 0;
}

