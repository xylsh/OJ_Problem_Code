#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <string>
/*#include <algorithm>*/
using namespace std;

/*
 * 1.按照题目的步骤计算判断即可。
 * 2.数字小于10^9，最多9位，所以用int存放足够了。
 * 3.判重用了一个set。
 */

set<int> vis;  //用于判重

//返回每一位的平方 加起来的和。要仔细，这里容易出错。
int get_square(int num,int len){
    if(len == 1){  
        return num*num;
    }else if(len == 2){
        return (num/10) * (num/10) + (num%10) * (num%10);
    }else if(len == 3){
        return (num/100) * (num/100) + (num%100/10) * (num%100/10) +
            (num%10) * (num%10);
    }else if(len == 4){
        return (num/1000) * (num/1000) + 
            (num%1000/100) * (num%1000/100) +
            (num%100/10) * (num%100/10) + 
            (num%10) * (num%10);
    }else if(len == 5){
        return (num/10000) * (num/10000) + 
            (num%10000/1000) * (num%10000/1000) +
            (num%1000/100) * (num%1000/100) + 
            (num%100/10) * (num%100/10) +
            (num%10) * (num%10);
    }else if(len == 6){
        return (num/100000) * (num/100000) + 
            (num%100000/10000) * (num%100000/10000) +
            (num%10000/1000) * (num%10000/1000) + 
            (num%1000/100) * (num%1000/100) +
            (num%100/10) * (num%100/10) + (num%10) * (num%10);
    }else if(len == 7){  
        return (num/1000000) * (num/1000000) + 
            (num%1000000/100000) * (num%1000000/100000) +
            (num%100000/10000) * (num%100000/10000) +
            (num%10000/1000) * (num%10000/1000) +
            (num%1000/100) * (num%1000/100) + 
            (num%100/10) * (num%100/10) +
            (num%10) * (num%10);
    }else if(len == 8){  
        int tmp = num%10000000;
        return (num/10000000) * (num/10000000) + 
            (tmp/1000000) * (tmp/1000000) + 
            (tmp%1000000/100000) * (tmp%1000000/100000) +
            (tmp%100000/10000) * (tmp%100000/10000) +
            (tmp%10000/1000) * (tmp%10000/1000) +
            (tmp%1000/100) * (tmp%1000/100) + 
            (tmp%100/10) * (tmp%100/10) +
            (tmp%10) * (tmp%10);
    }else if(len == 9){  
        return (num/100000000) * (num/100000000) + 
            (num%100000000/10000000) * (num%100000000/10000000) +
            (num%10000000/1000000) * (num%10000000/1000000) + 
            (num%1000000/100000) * (num%1000000/100000) +
            (num%100000/10000) * (num%100000/10000) +
            (num%10000/1000) * (num%10000/1000) +
            (num%1000/100) * (num%1000/100) +
            (num%100/10) * (num%100/10) +
            (num%10) * (num%10);
    }
}

bool is_happy(int num){
    vis.insert(num);

    bool flag = false;
    int tmp;
    while( true ){  
        if( num<10 ){            //如果num是1位数
            num = get_square(num,1);
        }else if( num<100 ){     //如果num是2位数
            num = get_square(num,2);
        }else if( num<1000 ){     //如果num是3位数
            num = get_square(num,3);
        }else if( num<10000 ){     //如果num是4位数
            num = get_square(num,4);
        }else if( num<100000 ){     //如果num是5位数
            num = get_square(num,5);
        }else if( num<1000000 ){     //如果num是6位数
            num = get_square(num,6);
        }else if( num<10000000 ){     //如果num是7位数
            num = get_square(num,7);
        }else if( num<100000000 ){     //如果num是8位数
            num = get_square(num,8);
        }else if( num<1000000000 ){     //如果num是9位数
            num = get_square(num,9);
        }
        //printf("num:%d\n",num);
    
        if( num == 1 ){ flag = true; break; }
        else if( vis.count(num) > 0 ){ flag = false; break; }
        else { vis.insert(num); }
    }
    
    return flag;
}

int main(){
    int n,k;
    int num;
    scanf("%d",&n);
    for(k=1; k<=n; k++){
        scanf("%d",&num);

        //initial
        vis.clear();

        if( is_happy(num) ){
            printf("Case #%d: %d is a Happy number.\n",k,num);
        }else{  
            printf("Case #%d: %d is an Unhappy number.\n",k,num);
        }

    }
    
    return 0;
}

