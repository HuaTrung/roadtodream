#include<bits/stdc++.h>
using namespace std;

int vertexs =0;
int edges=0;
int startVertex=0;
vector<int> head;
vector<int> adjacencyList;
int* trace;

void solveRecursion(int currentVertex){

    cout<<currentVertex<<" ";
    for(int i=head[currentVertex-1];i<head[currentVertex];i++){
        if(trace[adjacencyList[i]-1]==0){
            trace[adjacencyList[i]-1]=currentVertex;
            solveRecursion(adjacencyList[i]);
        }
    }
}
void solveStack(){
    stack<int> mystack;
    trace[startVertex-1]=vertexs;
    cout<<"    "<<startVertex<<" ";
    mystack.push(startVertex);
    while(!mystack.empty()){
        int i=mystack.top();
        int j=head[i-1];
        for(;j<head[i];j++){
            if(trace[adjacencyList[j]-1]==0){
                trace[adjacencyList[j]-1]=i;
                cout<<adjacencyList[j]<<" ";
                mystack.push(adjacencyList[j]);
                break;
            }
        }
        if(j==head[i]){
            mystack.pop();
        }
    }
}
void solve(){
    trace[startVertex-1]=vertexs;
    cout<<"    "<<startVertex<<" ";
    int i=startVertex;
    while(i!=(vertexs)){
        int j=head[i-1];
        for(;j<head[i];j++){
            if(trace[adjacencyList[j]-1]==0){
                trace[adjacencyList[j]-1]=i;
                cout<<adjacencyList[j]<<" ";
                break;
            }
        }
        if(j==head[i]){
            i=trace[i-1];
        }
        else{
            i=adjacencyList[j];
        }
    }
}
int main()
{

    // read data from txt file
    fstream f;
	f.open("input.txt", ios::in);

	string data;

	string line;
	while (!f.eof())
	{
		getline(f, line);
		data += line;
	}

	f.close();

    // assign value to vertex, edges, startVertex and generate trace
    vertexs = data[0]-48;
    edges=data[1]-48;
    startVertex=data[2]-48;
    trace=new int[vertexs];

    // generate adjacency list
    int k=0;
    for(int j=0;j<vertexs ;j++){
        head.push_back(k);
        for(int i=3;i<data.length();i+=2){
            if((data[i]-49)==j){
                adjacencyList.push_back(data[i+1]-48);
                k++;
            }
            if((data[i+1]-49)==j){
                adjacencyList.push_back(data[i]-48);
                k++;
            }
        }
    }
    head.push_back(k);

    // assign every element in trace with value 0. It means every vertex unvisited
    for(int i=0;i<vertexs;i++){
        trace[i]=0;
    }
    cout<<endl<<"Adjacency List is: ";
    for(int i=0;i<adjacencyList.size();i++){
        cout<<adjacencyList[i]<<" ";
    }
    cout<<endl<<"Index vertex: ";
    for(int i=0;i<=vertexs;i++){
        cout<<head[i]<<" ";
    }

    //  recursion
    cout<<endl<<"Path with recursion: ";
    trace[startVertex-1]=vertexs;
    solveRecursion(startVertex);

    // assign every element in trace with value 0. It means every vertex unvisited
    for(int i=0;i<vertexs;i++){
        trace[i]=0;
    }

    //  stack
    cout<<endl<<"Path with stack: ";
    solveStack();

    // assign every element in trace with value 0. It means every vertex unvisited
    for(int i=0;i<vertexs;i++){
        trace[i]=0;
    }

    // without stack and recursion
    cout<<endl<<"Path with stack: ";
    solve();

    return 0;
}
