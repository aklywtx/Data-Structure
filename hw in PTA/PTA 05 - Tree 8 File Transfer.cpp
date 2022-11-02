#include<iostream>
using namespace std;

#define MaxSize 10000

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

SetName Find(SetType S, ElementType X){
    if(S[X] < 0)
        return X;
    else
        return S[X] = Find(S, S[X]);
} //路径压缩

void Union(SetType S, SetName Root1, SetName Root2){
    if (S[Root1] < S[Root2]){
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }else{
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
} //按秩归并-按集合的规模

void Initialization(SetType S, int n){
    for(int i=0; i<n; i++)
        S[i] = -1;
}

void Input_connection(SetType S){
    SetName Root1, Root2;
    ElementType i, j;
    cin >> i >> j;
    Root1 = Find(S, i-1);
    S[Root1] --;
    Root2 = Find(S, j-1);
    S[Root2] --;
    if(Root1 != Root2)
        Union(S, Root1, Root2);
}

void Check_connection(SetType S){
    SetName Root1, Root2;
    ElementType i, j;
    cin >> i >> j;
    Root1 = Find(S, i-1);
    Root2 = Find(S, j-1);
    if (Root1 == Root2) cout << "yes" << endl;
    else cout << "no" << endl;
}

void Check_network(SetType S, int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(S[i] < 0)
            cnt ++;
    }
    if(cnt == 1)
        cout << "The network is connected." << endl;
    else
        cout << "There are " << cnt << " components." << endl;
}

int main(){
    SetType S;
    int n;
    char in;
    cin >> n;
    Initialization(S, n);
    
    do{
        cin >> in;
        switch(in){
            case 'I': Input_connection(S);break;
            case 'C': Check_connection(S);break;
            case 'S': Check_network(S, n);break;
        }
    }while(in != 'S');
    
    return 0;
}

