/* 
#include<iostream>
using namespace std;

typedef struct LNode *PtrToLNode
struct LNode{
    int Position;
    int Data
}
int main(){
    List Read();
    void Print(List L);
    List Reverse(List L, int K);
    return 0;
}

要给输入的数据排序
建立头节点输入第一行的地址为FrontP：
如果之后的P->Position == 任意一个输入的节点的Next，插入到它后面；
否则插入到整个链表的后面。
  插入：Attach函数
  寻找：找到返回插入节点的指针，找不到返回NULL（插入在最后）
最后记录下N和K的值，delete头节点

List Read(){
    List L
}

写不下去了55 找了答案
*/

//静态链表
#include<iostream>
#include<stdio.h>
#include<algorithm> //reverse函数
using namespace std;

#define MAXSIZE 100000 //最大地址为五位数

struct Node{
    int Data;
    int Next;
}Node[MAXSIZE];

int main(){
    int N, K, head;
    cin >> head >> N >> K;
    int Address, Data, Next;

    //输入链表
    for(int i=0;i<N;i++){
        cin >> Address >> Data >> Next;
        Node[Address].Data = Data;
        Node[Address].Next = Next;
    }
    
    int List[MAXSIZE];//用来存储首位相连的地址，-1不存储
    int j = 0; //j用来存储能够首位相连的节点数
    int p = head; //p指示当前节点
    while(p!=-1){
        List[j++] = p;
        p = Node[p].Next;
    }
    
    //翻转
    for(int i = 0; i+K <= j; i += K){
        reverse(&List[i], &List[i+K]); //reverse函数左闭右开
    }
    
    //打印
    int i;
    for(i = 0; i < j-1; i++){
        printf("%05d %d %05d\n", List[i], Node[List[i]].Data, List[i+1]);
    }
    printf("%05d %d -1\n", List[i], Node[List[i]].Data);
    
    return 0;
}
