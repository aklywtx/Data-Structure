#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
typedef int Vertex;
#define MaxVertexNum 10000

typedef struct ENode * PtrToENode;
struct ENode {
    Vertex V1, V2;
};
typedef PtrToENode Edge;

typedef struct AdjVNode * PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct VNode{
    PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

typedef struct GNode * PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum){
    LGraph Graph;
    Graph = new GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    
    for(Vertex V=0; V<Graph->Nv; V++){
        Graph->G[V].FirstEdge = NULL;
    }
    
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E){
    PtrToAdjVNode NewNode;
    NewNode = new AdjVNode;
    NewNode->AdjV = E->V2;
    
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
    
    NewNode = new AdjVNode;
    NewNode->AdjV = E->V1;
    
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph(){
    LGraph Graph;
    int Nv;
    PtrToENode E;
    
    cin >> Nv;
    Graph = CreateGraph(Nv);
    cin >> Graph->Ne;
    for(int i=0; i<Graph->Ne; i++){
        E = new ENode;
        cin >> E->V1 >> E->V2;
        InsertEdge(Graph, E);
    }
    
    return Graph;
}

bool visited[MaxVertexNum] = {false};

double BFS(LGraph Graph, Vertex V){
    queue<Vertex> MyQueue;
    Vertex K, P=V;
    PtrToAdjVNode W;
    int cnt=0, dimension=0;
    double result;
        
    visited[V] = true;
    MyQueue.push(V);
    
    while (!MyQueue.empty() && dimension<6){
        K = MyQueue.front();
        MyQueue.pop();
        

        for(W = Graph->G[K].FirstEdge; W; W = W->Next){
            if(!visited[W->AdjV]){
                MyQueue.push(W->AdjV);
                visited[W->AdjV] = true;
            }
        }
        if(K==P){
            dimension ++;
            P = MyQueue.back();
        } 
    }
    
    for(Vertex V1=1; V1 <= Graph->Nv; V1++){
        if(visited[V1]){
            cnt ++;
            //cout << V1 <<endl;
        }
            
    }
   
    result = 100.00 * cnt / Graph->Nv ;
    return result;
    
}

int main(){
    LGraph Graph;
    Graph = BuildGraph();
    double result;
    
    
    for(Vertex V=1; V<=Graph->Nv; V++){
        for(Vertex V1=1; V1<=Graph->Nv; V1++){
            visited[V1] = false;
        }
        printf("%d: %.2f%%\n", V, BFS(Graph, V));
    }
    
    
    
    
    return 0;
}