#include <stdio.h>
#include <string.h>
#define MAX 100

/*
 * 1.如果N<10，直接输出N即可
 * 2.将N依次除以9~2即可得到组成Q的数字。(不停的除以9,直到不能除尽了才换下一个数，因为要使Q位数尽量少)
 * 3.1不能作为除数。
 * 4.因为要使Q尽量小，所以除数从9开始，而不是从2开始。
 */

int record[MAX];     //记录找到的因数
int record_length;
int chushu[] = { 9,8,7,6,5,4,3,2 };    //除数数组

void solve(int num){  
    int i = 0;
    while( num > 1 && i<8){  
        if( num/chushu[i] * chushu[i] == num ){  //如果num/chushu[i]能除尽
            num = num/chushu[i];
            record[record_length++] = chushu[i];
        }else
            i++;
    }
}

int main(){
    int n,i,k,num;
    int tmp,flag;

    scanf("%d",&n);
    for(k=0; k<n; k++){  
        scanf("%d",&num);

        //initial
        record_length = 0;

        if( num < 10 )
            printf("%d\n",num);       //如果N<10，直接输出N可
        else{
            solve(num);
            
            flag = 0;
            tmp = 1;
            for(i=0; i<record_length; i++)
                tmp *= record[i];
            
            if( tmp == num )
                flag = 1;

            //output
            if( !flag )
                printf("-1\n");
            else{  
                for(i=record_length-1; i>=0; i--)
                    printf("%d",record[i]);
                printf("\n");
            }
        }
    
    }

    return 0;
}

