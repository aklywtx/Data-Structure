#include <iostream>
#include<vector>
using namespace std;


int main(){
    int N = 0;
    cin >> N;
    
    //定义并初始化数组
    vector<int> List;
    int a;
    while (cin >> a){
        List.push_back(a);
    }

    
    int ThisSum, MaxSum;
    int i;
    int first, last, begin;
    first = last = begin = 0;
    ThisSum = MaxSum = List[0];
    
    for(i=1; i < N; i++){
        if (ThisSum >= 0){
            ThisSum += List[i];
        }else{
            ThisSum = List[i];
            begin = i;
        }
        if (MaxSum < ThisSum){
            MaxSum = ThisSum;
            last = i;
            first = begin;
        }
    }
    
    if (MaxSum < 0){
        MaxSum = 0;
        first = 0;
        last = N-1;
    }
    
    cout << MaxSum << " " << List[first] << " " << List[last] << endl;
    
    return 0;
    
}