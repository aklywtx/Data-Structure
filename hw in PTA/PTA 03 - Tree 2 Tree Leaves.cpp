#include<iostream>
#include<queue>
using namespace std;

//输入树->层序遍历，遇到左右都为空的节点就记下下标，然后输出所有下标

#define MaxTree 10
#define Tree int
#define Null -1

struct TreeNode{
    Tree Left = -1;
    Tree Right = -1;
}T[MaxTree];

Tree BuildTree(struct TreeNode T[]){
    int N, Root = Null;
    char cl, cr;
    cin >> N;
    int check[MaxTree];
    
    if(N){
        for(int i=0; i<N; i++){
            check[i] = 0;
        }
        for(int i=0; i<N; i++){
            cin >> cl >> cr;
            if(cl != '-'){
                T[i].Left = cl-'0';
                check[T[i].Left] = 1;
            }
            if(cr != '-'){
                T[i].Right = cr-'0';
                check[T[i].Right] = 1;
            }
        }
        
        int i;
        for(i=0; i<N; i++){
            if(check[i] == 0) Root = i;
        }
    }
    
    return Root;
}

void MarkLeaves(Tree R){
    Tree current;
    queue<Tree> q;
    vector<int> Leaves;
    
    current = R;
    if (current != Null) q.push(R);
        
    while(!q.empty()){
        current = q.front();
        if(T[current].Left == Null && T[current].Right == Null)
            Leaves.push_back(current);
        q.pop();
        if(T[current].Left != Null) 
            q.push(T[current].Left);
        if(T[current].Right != Null) 
            q.push(T[current].Right);
    }
    
    if(!Leaves.empty()){
        cout << Leaves[0];
        if (Leaves.size()>1){
            for(int i=1; i<Leaves.size(); i++){
                cout << " " <<Leaves[i];
            }
        }
    }
}

int main(){
    Tree R = BuildTree(T);
    MarkLeaves(R);
    
    return 0;
}