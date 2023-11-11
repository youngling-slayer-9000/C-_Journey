#include<iostream>
using namespace std;


class Vertex {
public:
	string name;
	bool flag;

	Vertex() : flag(0) {}	
	Vertex(string n , bool f)  : name(n) , flag(f){}

};

class Graph{
	Vertex** edges;
	int size;
public:
	Graph() : edges(nullptr) , size(0) {}
	Graph(int s) : size(s){
		edges = new Vertex*[size];
		for(int i =0 ; i < size ; i++){
			edges[i] = new Vertex[size];
		} 
		cout << "Successfully created adjacency matrix\n";
	}
	bool addEdge(int origin , int destination , string name){
		if(origin < size && destination < size){
			edges[origin][destination].flag = true;
			edges[origin][destination].name = name;
			return true;
		}
		else{
			cout << "Invalid position \n";
			return false;
		}

	}
	void display(){
		cout << " digraph {\n";
		for(int vertex = 0 ; vertex < size ; vertex++){
			for(int edge = 0 ; edge < size ; edge++){
				if(edges[vertex][edge].flag){
					cout << vertex << " -> " << edge << ";" << endl;
				}
			} 
		}
		cout << "}" << endl;
		
	}


};



int main(void){

	Graph g1(5);
	g1.addEdge(0,1,"sharon");
	g1.addEdge(0,2,"barry");
	g1.addEdge(2,4 , "Ben");
	
	g1.display();	
}
