#include<iostream>
#include<math.h>
using namespace std;

/*
#define MaxVertexNum 100
#define IslandRadius 7.5
typedef int Vertex;
typedef int Scale;

int Flag = 0; //标志是否能够跳到岸边，1表示可以，默认0表示不可以
Vertex visited[MaxVertexNum] = {false}; //记录节点有没有被访问过

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct VNode{
    Scale X;
    Scale Y;
    PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    int Jump;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum, int Jump){
    LGraph Graph;
    
    Graph = new GNode;
    Graph->Nv = VertexNum;
    Graph->Jump = Jump;
    Graph->Ne = 0;
    
    for(Vertex V=0; V<Graph->Nv; V++){
        Graph->G[V].FirstEdge = NULL;
    }
    
    return Graph;
}

bool IsEdge(LGraph Graph, Vertex V1, Vertex V2){
    int distance = pow(Graph->G[V1].X - Graph->G[V2].X, 2) + pow(Graph->G[V1].Y - Graph->G[V2].Y, 2);
    if(distance <= pow(Graph->Jump, 2))
        return true;
    else
        return false;
}

void InsertEdge(LGraph Graph, Vertex V1, Vertex V2){
    PtrToAdjVNode NewNode;
    NewNode = new AdjVNode;
    NewNode->AdjV = V2;
    
    NewNode->Next = Graph->G[V1].FirstEdge;
    Graph->G[V1].FirstEdge = NewNode;
    
}

LGraph BuildGraph(){
    LGraph Graph;
    int Nv, Jump;
    
    cin >> Nv >> Jump;
    Graph = CreateGraph(Nv, Jump);
    
    
    while(!cin.eof()){
        cin >> Graph->G[Graph->Ne].X >> Graph->G[Graph->Ne].Y;
        Graph->Ne ++;
    }
    
    for(int i=0; i<Graph->Ne; i++){
        for(int j=0; j<Graph->Ne; j++){
            if(i==j) continue;
            else{
                if(IsEdge(Graph, i, j))
                    InsertEdge(Graph, i, j);
            }
        }
    }
    
    return Graph;
}

Vertex FirstJump(LGraph Graph){
    int distance;
    Vertex V;
    for(V = 0; V<Graph->Nv && !visited[V]; V++){
        distance = pow(Graph->G[V].X, 2) + pow(Graph->G[V].Y, 2);
        if(distance <= pow(Graph->Jump + IslandRadius, 2)) break;
    }
    if(V == Graph->Nv) return -1;
    else return V;
    
}

void DFS(LGraph Graph, Vertex V){
    if(50 - abs(Graph->G[V].X) <= Graph->Jump || abs(50 - Graph->G[V].Y) <= Graph->Jump)
        Flag = 1;
    visited[V] = true;
    
    for(PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W=W->Next){
        if(!visited[W->AdjV])
            DFS(Graph, W->AdjV);
    }
}

int main(){
    LGraph Graph;
    Vertex V;
    Graph = BuildGraph();
    
    for(Vertex W = 0; W<Graph->Nv; W++){
        V = FirstJump(Graph);
        if(V == -1) Flag = 0;
        else{
        DFS(Graph, V);
        }
    }
    
    if(Flag == 1) cout << "Yes";
    else cout << "No";
    
    return 0;
}

*/

//优质解答

#define IslandRadius 7.5
#define MaxVertexNum 100

typedef struct node{
    int x;
    int y;
}Vertex;

int N, D, R;
bool visited[MaxVertexNum] = {false};

bool IsConnected(Vertex v1, Vertex v2) //判断节点之间是否联通
{
    return (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) <= D*D;
}

bool IsConnected(Vertex v)
{
    return v.x*v.x + v.y*v.y <= (D + IslandRadius)*(D + IslandRadius);
}

bool IsSafe(Vertex v){
    return abs(v.x) >= 50-D || abs(v.y) >= 50-D;
}

bool DFS(Vertex V[], int v){
    bool ret = false;
    visited[v] = true;
    if(IsSafe(V[v])) ret = true;
    else{
        for(int w=0; w<N; w++){
            if(!visited[w] && IsConnected(V[v], V[w])){
                ret = DFS(V, w);
                if(ret) break;
            }
        }
    }
    return ret;
}

void Save007(Vertex V[]){
    bool ret = 0;
    for(int v=0; v<N; v++){
        if (!visited[v] && IsConnected(V[v])){
            ret = DFS(V, v);
            if(ret) break;
        }
    }
    
    if(ret) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    cin >> N >> D;
    Vertex V[MaxVertexNum];
    
    for(int i=0; i<N; i++){
        cin >> V[i].x >> V[i].y;
    }
    Save007(V);
    system("pause");
    return 0;
}