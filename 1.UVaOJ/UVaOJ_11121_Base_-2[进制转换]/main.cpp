#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40      //题目的最大数据和最小数据的输出最多只有三十多位

/*
 * URL:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=115&page=show_problem&problem=2062
 * 1.先尝试手工转换几个数字观察。
 *   decimal 7 : 7 / -2 = -3 余数1
 *              -3 / -2 =  2 余数1
 *               2 / -2 = -1 余数0
 *              -1 / -2 =  1 余数1
 *               1 / -2 =  0 余数1
 *              -2进制: 11011
 *
 *   decimal -2: -2 / -2 = 1 余数0
 *                1 / -2 = 0 余数1
 *               -2进制: 10
 *   由此可见，十进制转-2进制：用2整除十进制整数，可以得到一个商和余数；再用2去除商，又会得到一个商和余数，
 *                             如此进行，直到商为0时为止，
 *                             然后把先得到的余数作为低位有效位，后得到的余数作为高位有效位，依次排列起来。
 *                             
 * 2.注意：计算机计算 -3 / -2 = 1 余数-1 ,不是我们需要的 -3 / -2 = 2 余数1,
 *         可以给商增加1,使余数非负(为1).
 */

int base2[MAX];
int length;

void get_base2(int decimal){  
    length = 0;         //initial
    int shang = decimal,yushu;
    
    while( shang != 0 ){  
        //下面2行不能调换顺序
        yushu = shang % -2;   //余数
        shang = shang / -2;   //商
    
        if( yushu < 0 ){  
            shang++;
            yushu = 1;
        }
        base2[length] = yushu;
        length++;
    }
}

int main(){
    int test_case,decimal;
    scanf("%d", &test_case);

    for(int k=1; k<=test_case; k++){  
        scanf("%d", &decimal);

        if( decimal == 0 ){       //如果为0,直接输出0 
            printf("Case #%d: 0\n", k);
            continue;
        }

        get_base2(decimal);

        //output
        printf("Case #%d: ", k);
        for(int i=length-1; i>=0; i--)
            printf("%d", base2[i]);
        printf("\n");

    }

    /*观察数据
    //转换7
    printf("%d , %d\n",7/-2, 7%-2);
    printf("%d , %d\n",-3/-2, -3%-2);
    printf("%d , %d\n",2/-2, 2%-2);
    printf("%d , %d\n",-1/-2, -1%-2);
    printf("%d , %d\n",1/-2, 1%-2);

    //转换-2
    printf("\n%d , %d\n",-2/-2, -2%-2);
    printf("%d , %d\n",1/-2, 1%-2);

    //转换1
    printf("%d , %d\n",1/-2, 1%-2);*/

    return 0;
}
