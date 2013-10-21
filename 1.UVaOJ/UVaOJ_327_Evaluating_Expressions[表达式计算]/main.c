#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 200

/**
 * 算法大致步骤题目中已经给出，有变化的地方是在处理前置++/--时，把后置++/--一并处理了。
 * 另外，输出字母要按字典序输出。
 */

/* 定义节点方便排序要输出的字母 */
typedef struct Node{  
    int value;    /* 数字值 */
    char c;       /* 对应字母 */
}Node;

char line[MAX];      /* 一行表达式 */
int num[MAX];        /* 保存处理了前置++/--的数字 */
int num_final[MAX];  /* 保存处理了所有++/--的数字 */
int num_count;       /* 数字个数/字母个数 */
Node* nodes[MAX];    /* 节点数组，为了排序输出 */

/* 字母转换为数字 并 处理++和-- */
void prepare(){
    int i;
    int flag = 1;    /* 1表示无前置，2表示前置++，3表示前置-- */
    int length = strlen(line);
    for(i=0; i<=length; i++){
        if( isalpha(line[i]) ){  
            num[num_count] = line[i] - 96;

            if( flag == 2)  
                num[num_count]++;
            else if( flag == 3)   
                num[num_count]--;

            num_final[num_count] = num[num_count];
            flag = 1;
            num_count++;
        }else if( line[i] == '+' && line[i+1] == '+' ){  
            flag = 2;
            line[i] = line[i+1] = ' ';
        }else if( line[i] == '-' && line[i+1] == '-' ){  
            flag = 3;
            line[i] = line[i+1] = ' ';
        }else if( (line[i] == '+' || line[i] == '-' || line[i] == '\0') && flag != 1  ){  /* 如果是后置++或后置-- */
            
            if( flag == 2 )  
                num_final[num_count-1]++;
            else if( flag == 3 )  
                num_final[num_count-1]--;
            
            flag = 1;
        }
    }
}
/* 计算表达式 */
int cal(){  
    int i;
    int curr = 0;
    int value = num[0];
    int length = strlen(line);
    for(i=0; i<length; i++){
        if( isalpha(line[i]) ){  
            curr++;
        }else if( line[i] == '+' ){
            value += num[curr];
        }else if( line[i] == '-' ){  
            value -= num[curr];
        }
    }
    return value;
}

int main(){
    int value,i,j,k;

    while( fgets(line,MAX,stdin) != NULL ){  
        line[strlen(line)-1] = '\0';
        num_count = 0;
        value = 0;

        printf("Expression: %s\n",line);
        prepare();
        value = cal();
        printf("    value = %d\n",value);

        /*printf("去掉所有++、--: %s\n",line);*/

        /* 建立节点，然后排序 */
        j = k = 0;
        int length = strlen(line);
        for(i=0; i<length; i++){
            if( isalpha(line[i]) ){
                /*printf("    %c = %d\n",line[i],num_final[j++]);*/
                nodes[k] = (Node*)malloc(sizeof(Node));
                nodes[k]->c = line[i];
                nodes[k]->value = num_final[j++];
                k++;
            }
        }
        /* 排序 */
        for(i=0; i<k; i++){  
            for(j=i+1; j<k; j++){  
                if( nodes[i]->c > nodes[j]->c ){  
                    Node* tmp = nodes[i];
                    nodes[i] = nodes[j];
                    nodes[j] = tmp;
                }
            }
        }
        /* output */
        for(i=0; i<k; i++)
            printf("    %c = %d\n",nodes[i]->c,nodes[i]->value);
    }

    return 0;
}
