#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

void BubbleSort(int a[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

queue<int> q;

void inorder(int index, int n){ 
    if(index>=n)
        return ;
    inorder(index*2+1, n);
    q.push(index);
    inorder(index*2+2, n);
}

void CreateBST(int a[], int BST[], int n){
    int index, i=0;
    while(!q.empty()){
        index = q.front();
        //cout << index << " " <<endl;
        q.pop();
        BST[index] = a[i];
        i++;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n], BST[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    BubbleSort(a, n);
    inorder(0, n);
    CreateBST(a, BST, n);
    
    for(int i=0; i<n-1; i++){
        cout << BST[i] << " ";
    }
    cout << BST[n-1];
    
    return 0;
}