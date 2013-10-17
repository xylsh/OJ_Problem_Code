#include <stdio.h>
#include <string.h>
#include <stack>
#define MAX_LINE 140
#define MAX_TEST 1000000
using namespace std;
/*
 * 思路：使用栈，遇到左括号就push，右括号就判断与栈顶元素
 * 是否匹配，匹配则pop,不匹配则判断结果为No。
 * 注意：
 * 1.空行为Yes
 * 2.测试数据"[["
 * 3.每行判断之前要清空栈
 */
char line[MAX_LINE];
int result[MAX_TEST];
int main(){ 

    int n,flag,i,j,k,length;
    char c;
    stack<char> s;

    scanf("%d",&n);
    getchar();

    for(i=0; i<n; i++){       

        while(s.size()) s.pop();   /* 清空栈 */

        fgets(line,MAX_LINE,stdin);
        line[strlen(line)-1] = '\0';
        length = strlen(line);

        flag = 1;   /* 默认结果为Yes */
        for(j=0; j<length; j++){
            c = line[j];
            if( c == '(' || c == '[' ) s.push(c);
            else if( c == ')' ){
                if( !s.empty() && s.top() == '(') s.pop();
                else{ flag = 0; break; }
            }else if( c == ']' ){
                if( !s.empty() && s.top() == '[') s.pop();
                else{ flag = 0; break; }
            }
        }
        if( !s.empty() ) flag = 0;  /* 避免了"注意2" */
        result[i] = flag;
    }
    
    for(i=0; i<n; i++){
        printf("%s\n",result[i]?"Yes":"No");
    }

    return 0;
}
