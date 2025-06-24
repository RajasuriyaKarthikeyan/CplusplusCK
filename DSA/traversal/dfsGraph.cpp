#include <iostream>
#include <vector>
#include <array>


using namespace std;
constexpr int MAX = 5;

struct Vertex{
    char label;
    bool visited;
};

//stack variables for dfs
array<int,MAX> stack;
int top = -1;

//array of veritices
array<Vertex*,MAX> listVertices;
//array for adjacent matrix
array<array<int,MAX>,MAX> adjMatrix;
//vertex count
int vertexCount = 0;

void push(int item){
    stack[++top] = item;
}
int pop(){
    return stack[top--];
}
int peek(){
    return stack[top];
}

bool isEmpty(){
    return top == -1;
}

void addVertex(char label){
    Vertex* vertex = new Vertex;
    vertex->label = label;
    vertex->visited = false;
    listVertices[vertexCount++] = vertex;
}

void addEdges(int start, int end){
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayVertex(int vertextIndex){
    cout << listVertices[vertextIndex]->label << " ";
}

int getAdjacentUnivisitedVertext(int vertextIndex){
    for(int i=0;i<vertexCount;i++){
        if(adjMatrix[vertextIndex][i]==1 && listVertices[i]->visited==false){
            return i;
        }
    }
    return -1;
}

void resetList(){
    for(int i=0;i<vertexCount;i++){
        listVertices[i]->visited = false;
    }
}

void depthFirstSearch(int startIndex){
    listVertices[startIndex]->visited = true;
    displayVertex(startIndex);
    push(startIndex);

    while(!isEmpty()){
        int unvisitedVertex = getAdjacentUnivisitedVertext(peek());
        if(unvisitedVertex == -1){
            pop();
        } else {
            listVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }
    resetList();
}

void DFSRecursive(int startIndex){
    listVertices[startIndex]->visited = true;
    displayVertex(startIndex);

    for(int i=0;i<vertexCount;i++){
        if(adjMatrix[startIndex][i]==1 && listVertices[i]->visited==false){
            DFSRecursive(i);
        } 
    }
}

int main(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            adjMatrix[i][j] = 0;
        }
    }
    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addEdges(0,1);
    addEdges(1,4);
    addEdges(0,2);
    addEdges(1,3);
    addEdges(2,4);
    addEdges(3,4);
    cout << "DFS Stack Approach : ";
    depthFirstSearch(0);
    cout << endl;
    cout << "DFS Recursive Approach : ";
    DFSRecursive(0);
    cout << endl;
    return 0;
}



