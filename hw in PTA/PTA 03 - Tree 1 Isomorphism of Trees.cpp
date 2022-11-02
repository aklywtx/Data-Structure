#include<iostream>

using namespace std;

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]){
    int N, Root=-1;
    char cl, cr;
    cin >> N;
    
    if(N){
        int check[N]; //check数组用来找出根节点，寻找的方法：如果一个节点是其他节点的子节点，标为1，最后的0就是根节点
        for(int i=0; i<N; i++){
            check[i] = 0;
        }
        
        for(int i=0; i<N; i++){
            cin >> T[i].Element >> cl >> cr;
            //处理左边节点
            if(cl!='-'){
                T[i].Left = cl-'0';
                check[T[i].Left] = 1;
            }else T[i].Left = Null;
            //处理右边节点（同左边）
            if(cr!='-'){
                T[i].Right = cr-'0'; //把字符转化为数字
                check[T[i].Right] = 1;
            }else T[i].Right = Null;
        }
        
        //找出根节点
        int i;
        for(i=0; i<N; i++){
            if(check[i]==0) break;
        }
        Root = i;
    }
    return Root;
}

int isomorphic(Tree R1, Tree R2){
    if(R1 == Null && R2 == Null) return 1;
    if((R1 == Null && R2 != Null)||(R2 == Null && R1!= Null)) return 0;
    if(T1[R1].Element != T2[R2].Element) return 0;
    if(T1[R1].Left == Null && T2[R2].Left == Null)
        return isomorphic(T1[R1].Right, T2[R2].Right);
    if(T1[R1].Left != Null && T2[R2].Left != Null && T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)
        return isomorphic(T1[R1].Left, T2[R2].Left) && isomorphic(T1[R1].Right, T2[R2].Right);
    else
        return isomorphic(T1[R1].Right, T2[R2].Left) && isomorphic(T1[R1].Left, T2[R2].Right);
}

int main(){
    Tree R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    
    if(isomorphic(R1, R2)) cout << "Yes";
    else cout << "No";
    
    return 0;
}