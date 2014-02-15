#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <string>
#define MAX_ENTRY 100010
#define WORD_MAX 15
using namespace std;

/*
 * 1.用stl的map来保存和搜索词典条目。Map内部采用红黑树，能对数据进行快速和高效的检索。
 * 2.这道题如果用数组保存词典条目，在OJ的输入规模下会超时(超过3s).
 */

char search_word[MAX_ENTRY][WORD_MAX];
map<string,string> dic;
char line[35];

int main(){
    
    //读取词典条目
    char a[WORD_MAX],b[WORD_MAX];
    while( fgets(line,35,stdin) != NULL && line[0] != '\n' ){
        sscanf(line,"%s %s",a,b);
        dic.insert( pair<string,string>(b,a) );
    }

    //读取待查单词
    int s = 0;
    while( scanf("%s",search_word[s]) == 1 ){
        //printf("search[%d]:%s\n",s,search_word[s]);
        s++;
    }

    map<string,string>::iterator it;
    for(int i=0; i<s; i++){
        it = dic.find(search_word[i]);
        if( it != dic.end() )
            cout<<it->second<<endl;
        else
            cout<<"eh"<<endl;
    }

    return 0;
}

