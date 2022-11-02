#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 10
typedef int Vertex;

typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;
};
typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct VNode{
    PtrToAdjVNode FirstEdge;
    Vertex V;
}AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

bool visited[MaxVertexNum] = {false};

//初始化图
LGraph CreateGraph(int VertexNum){
    Vertex V=0;
    LGraph Graph;
    
    Graph = new GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(V=0; V<Graph->Nv; V++){
        Graph->G[V].FirstEdge = NULL;
    }
    
    return Graph;
}

//插入边
void InsertEdge(LGraph Graph,Edge E)
{
    PtrToAdjVNode NewNode,W;
    /* 插入边 <V1, V2> ,在V1为下标的链表中，插入结点V2,表示v1->v2*/
    NewNode = new AdjVNode;
    NewNode->AdjV = E->V2;

    if(!Graph->G[E->V1].FirstEdge)
    {
        NewNode->Next = Graph->G[E->V1].FirstEdge;
        Graph->G[E->V1].FirstEdge = NewNode;
    }
    else if(Graph->G[E->V1].FirstEdge&&!Graph->G[E->V1].FirstEdge->Next)
    {
        if(NewNode->AdjV < Graph->G[E->V1].FirstEdge->AdjV)
        {
            NewNode->Next = Graph->G[E->V1].FirstEdge;
            Graph->G[E->V1].FirstEdge = NewNode;
        }else{
            NewNode->Next = Graph->G[E->V1].FirstEdge->Next;
            Graph->G[E->V1].FirstEdge->Next = NewNode;
        }
    }
    else{
        for(W = Graph->G[E->V1].FirstEdge; W; W=W->Next)
        {
            if(!W->Next||(W->Next->AdjV > NewNode->AdjV))
            {
                NewNode->Next = W->Next;
                W->Next = NewNode;
                break;
            }
        }
    }
    
    NewNode = new AdjVNode;
    NewNode->AdjV = E->V1;

    if(!Graph->G[E->V2].FirstEdge)
    {
        NewNode->Next = Graph->G[E->V2].FirstEdge;
        Graph->G[E->V2].FirstEdge = NewNode;
    }
    else if(Graph->G[E->V2].FirstEdge&&!Graph->G[E->V2].FirstEdge->Next)
    {
        if(NewNode->AdjV < Graph->G[E->V2].FirstEdge->AdjV)
        {
            NewNode->Next = Graph->G[E->V2].FirstEdge;
            Graph->G[E->V2].FirstEdge = NewNode;
        }else{
            NewNode->Next = Graph->G[E->V2].FirstEdge->Next;
            Graph->G[E->V2].FirstEdge->Next = NewNode;
        }
    }
    else{
        for(W = Graph->G[E->V2].FirstEdge; W; W=W->Next)
        {
            if(!W->Next||(W->Next->AdjV > NewNode->AdjV))
            {
                NewNode->Next = W->Next;
                W->Next = NewNode;
                break;
            }
        }
    }
}

//建立图
LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    int Nv;
    
    cin >> Nv;
    Graph = CreateGraph(Nv);
    
    cin >> Graph->Ne;
    if(Graph->Ne != 0){
        E = new ENode;
        for(int i=0; i<Graph->Ne; i++){
            cin >> E->V1 >> E->V2;
            InsertEdge(Graph, E);
        }
    }
    
    return Graph;
}

void Visit(Vertex V){
    cout << V << " ";
}

void DFS(LGraph Graph, Vertex S, void (*Visit)(Vertex)){
    PtrToAdjVNode W;
    Visit(S);
    visited[S] = true;
    
    for(W=Graph->G[S].FirstEdge; W; W = W->Next){
        if(!visited[W->AdjV])
            DFS(Graph, W->AdjV, Visit);
    }
}

void BFS(LGraph Graph, Vertex S, void (*Visit)(Vertex)){
    queue<Vertex> MyQueue;
    Vertex V;
    PtrToAdjVNode W;

    Visit(S);
    visited[S] = true;
    MyQueue.push(S);

    while(!MyQueue.empty()){
        V = MyQueue.front();
        MyQueue.pop();
        for(W=Graph->G[V].FirstEdge; W; W = W->Next){
            if(!visited[W->AdjV]){
                Visit(W->AdjV);
                visited[W->AdjV] = true;
                MyQueue.push(W->AdjV);
            }
        }
    }
}


int main(){
    LGraph Graph;
    Graph = BuildGraph();

    for(int i=0; i<Graph->Nv; i++){
        if(!visited[i]){
            cout << "{ ";
            DFS(Graph, i, Visit);
            cout << "}" << endl;
        }
    }
    
    for(int i=0; i<Graph->Nv; i++){
        visited[i] = false;
    }
    
    for(int i=0; i<Graph->Nv; i++){
        if(!visited[i]){
            cout << "{ ";
            BFS(Graph, i, Visit);
            cout << "}" << endl;
        }
    }

    return 0;
}