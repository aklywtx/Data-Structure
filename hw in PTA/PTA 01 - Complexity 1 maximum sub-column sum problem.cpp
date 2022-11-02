#include <iostream>
using namespace std;

/*int MaxSubseqSum4(int List[], int N){
    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    
    for(i=0; i<=N; i++){
        ThisSum += List[i];
        if (ThisSum > MaxSum){
            MaxSum = ThisSum;
        }else if (ThisSum < 0){
            ThisSum = 0;
        } 
    }
    
    return MaxSum;
}*/

int Max3(int A, int B, int C){
    return A > B ? A > C ? A : C : B > C ? B: C;
}

int DivideAndConquer(int List[], int left, int right){
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum=0, MaxRightBorderSum=0, MaxBorderSum=0;
    int center;

    if(left==right){
        if(List[left]<0){
            return 0;
        }else{
            return List[left];
        }
    }

    center = (left + right) / 2;
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    int LeftBorderSum=0, RightBorderSum=0;
    for (int i = center; i >= left;i--){
        LeftBorderSum += List[i];
        if(LeftBorderSum>MaxLeftBorderSum){
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    for (int i = center + 1; i <= right;i++){
        RightBorderSum += List[i];
        if(RightBorderSum > MaxRightBorderSum){
            MaxRightBorderSum = RightBorderSum;
        }
    }

    MaxBorderSum = MaxLeftBorderSum + MaxRightBorderSum;

    return Max3(MaxBorderSum, MaxLeftSum, MaxRightSum);
}

int MaxSubseqSum3(int List[], int N){
    return DivideAndConquer(List, 0, N-1);
}

int main(){
    int K = 0;
    cin >> K;
    int Len = K-1;
    int a[K] = {0,};
    for(int i=0; i<=Len; i++){
        cin >> a[i];
    }
    
    int Max = MaxSubseqSum3(a, K);
    cout << Max << endl;

    return 0;
}
