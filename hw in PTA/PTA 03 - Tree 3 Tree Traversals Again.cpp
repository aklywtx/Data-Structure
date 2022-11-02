/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

#define MaxTree 30
#define Null -1
#define Tree int
#define ARR_LEN(array, length){ length =  sizeof(array) / sizeof(array[0]); }


struct BinTreeNode {
    Tree data;
    BinTreeNode *leftChild;
    BinTreeNode *rightChild;
};

stack<Tree> s;
char action;
Tree InOrderTraversal[MaxTree];

BinTreeNode CreateBinaryTree() {
    int num = 0, i = 0;
    
    for(int j=0; j<2*N; j++){
        cin >> Action;
        if(Action == "Push"){
            cin >> num;
            s.push(num);
        }else{
            InOrderTraversal[i] = s.top();
            s.pop();
            i ++;
        }
    }
    
    BinTreeNode *p;
    int N;
    cin >> N;
    i = 0;
    
    if(i == 0)
        p = NULL;
    else {
        p = new BinTreeNode<Tree>();
        p->data = num;
        p->leftChild = CreateBinaryTree();
        p->rightChild = CreateBinaryTree();
    }
    return p;
}

实在整不会了 上网找了解答 mooc上姥姥给的
*/

#include<cstdio> //c中的<stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
const int maxn=100;
int pre[maxn], in[maxn], post[maxn];
 
void solve(int PreL, int inL, int postL, int n){
	if(n==0)return;  //空树
	if(n==1){  //只有一个节点的树
		post[postL]=pre[PreL];
		return;
	}
	int i;
	int root=pre[PreL];  //pre第PreL个元素，即左边最开始的元素是根节点
	post[postL+n-1]=root;  //post最后一个元素是pre的第一个元素
	for(i=0; i<n; i++){
		if(in[inL+i]==root)break; //用中序确定左右分界
	}
	int L=i, R=n-i-1;
	solve(PreL+1, inL, postL, L);
	solve(PreL+1+L, inL+L+1, postL+L, R);
}
int main(){
	int n, num, i=0, j=0;
	scanf("%d", &n);
	string s;
	stack<int> st;
	for(int z=0; z<2*n; z++){
		cin>>s;
        //push是先序遍历的顺序，pop输出的是中序遍历的顺序，这个问题就可以转化成，如果知道了先序遍历和中序遍历的顺序，如何求后序遍历
		if(s=="Push"){
			scanf("%d\n", &num);
			st.push(num);
			pre[i++]=num;
		}else{
			num=st.top();
			st.pop();
			in[j++]=num;
		}
	}
	solve(0,0,0,n);
	for(int i=0; i<n; i++){
		printf("%d", post[i]);
		if(i!=n-1)printf(" ");
	}
	return 0;
} 
