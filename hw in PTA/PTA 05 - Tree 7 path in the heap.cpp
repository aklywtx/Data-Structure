#include<iostream>
using namespace std;

#define MAXDATA -10001;

typedef struct HNode * Heap;
struct HNode{
    int *Data;
    int Size;
    int Capacity;
};
typedef Heap MinHeap;

Heap CreateMinHeap(int n){
    MinHeap H = new HNode;
    H->Data = new int[n+1];
    H->Size = 0;
    H->Capacity = n;
    H->Data[0] = MAXDATA;
    
    return H;
}

void Insert(Heap H, int x){
    int i;
    i = ++ H->Size;
    for(; H->Data[i/2]>x; i/=2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = x;
}

void PrintPath(Heap H, int num){
    for(; num>1; num/=2){
        cout << H->Data[num] << " ";
    }
    cout << H->Data[num] << endl;
}

int main(){
    int n, m, x, num;
    Heap H;
    
    cin >> n >> m;
    
    H = CreateMinHeap(n);
    
    for(int i=0; i<n; i++){
        cin >> x;
        Insert(H, x);
    }
    
    for(int i=0; i<m; i++){
        cin >> num;
        PrintPath(H, num);
    }
    
    return 0;
}