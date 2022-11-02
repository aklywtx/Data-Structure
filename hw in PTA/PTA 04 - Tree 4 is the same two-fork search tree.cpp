#include<iostream>
using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode{
    int v;
    Tree Left,Right;
    int flag = 0;
};


Tree NewNode(int V);
Tree MakeTree(int N);
Tree Insert(Tree T, int V);
int Check(Tree T, int V);
int Judge(Tree T, int N);
void Reset(Tree T);
void FreeTree(Tree T);
int main(){
    int N, L;
    Tree T;
    
    cin >> N;
    while(N){
        cin >> L;
        T = MakeTree(N);
        
        for(int i=0; i<L; i++){
            if(Judge(T, N)) cout << "Yes" << endl;
            else cout << "No" << endl;
            Reset(T);
        }
        FreeTree(T);
        cin >> N;
    }
    return 0;
}


//建立新结点并初始化
Tree NewNode(int V){ 
    Tree T = new TreeNode;
    T->v = V;
    T->Left = T->Right = NULL;
    T->flag = 0;
    
    return T;
}

//建立模版树，其他的跟它比较
Tree MakeTree(int N){
    Tree T;
    int V;
    cin >> V;
    T = NewNode(V);
    
    for(int i=1; i<N; i++){
        cin >> V;
        T = Insert(T, V);
    }
    return T;
}

//这个Insert有点东西！！！
Tree Insert(Tree T, int V){
    if(!T) //先判断T空不空，这也是递归终止的条件
        T = NewNode(V);
    else{
        if(V<T->v)
            T->Left = Insert(T->Left, V);
        else
            T->Right = Insert(T->Right, V);
    }
    return T;
}

//判断序列中的每一个数
int Check(Tree T, int V){
    if(T->flag){
        if(V>T->v) return Check(T->Right, V);
        else if(V<T->v) return Check(T->Left, V);
        else return 0;
    }
    else{
        if(V == T->v){
            T->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}

int Judge(Tree T, int N){
    int flag = 0, V;
    
    cin >> V;
    if(T->v != V) 
        flag = 1;
    else 
        T->flag = 1;
    
    for(int i=1; i<N; i++){
        cin >> V;
        if(!Check(T, V) && !flag) flag = 1;
    }
    
    if(flag) return 0;
    else return 1;
}

void Reset(Tree T){
    if(T->Left) Reset(T->Left);
    if(T->Right) Reset(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T){
    if(T->Left) FreeTree(T->Left);
    if(T->Right) FreeTree(T->Right);
    delete T;
}
