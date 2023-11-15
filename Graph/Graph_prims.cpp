#include<iostream>
#include<climits>
using namespace std;
class Node{
	public:
	int data;    //stores the neighbouring vertex's ID
	Node* next;
	Node() : data(-1) , next(nullptr){}
	Node(int d) : data(d) , next(nullptr){}
};

class LinkedList{
	Node* head;
	Node* end;

public:
	LinkedList() : head(nullptr){}

	bool InsertEnd(int destination){
		Node* newNode = new Node(destination);
		if(!head){
			head = newNode;
			end = newNode;
			return true;
		}else{
			Node* iter;
			for(iter = head ; iter->next != nullptr ; iter = iter->next);
			iter->next = newNode;
			end = newNode;
			return true;
		}

	}
	void display(int x){
	    cout << "-------\n";
	     cout << x << " : ";
		for(Node* iter = head ; iter ; iter = iter->next)
			cout << iter->data << ' ';

	}

	Node* Begin(){
		return head;
	}

	Node* End(){
		return end;
	}
};
class Vertex{
    public:
    string name;
    LinkedList adjacentList;
    Vertex() : adjacentList() {}
};


class Graph{
	int size;
	Vertex* arr;
	public:
	Graph() : size(0) , arr(nullptr) {}
	Graph(int s) : size(s) {
		arr = new Vertex[size];
	}
	void Prims(int (*Matrix)[5]){
		int parent[size];
		int key[size];
		bool Hash[size]{false};
		for(int i = 0 ; i < size ; i++){
			key[i] = INT_MAX;
			parent[i] = 0;
		}
		parent[0]  = -1;
		key[0] = -1;
		int vertex_id, adjacent_vertex_id;
		for(int count = 0 ; count < size ; count++){
			vertex_id = findMin( &key[0] , &Hash[0] ) ;
			
			for(adjacent_vertex_id = 0 ; adjacent_vertex_id < size ; adjacent_vertex_id++){   // iterates over the columns of the matrix (those columns represents weightof adjacent node)
				if(  Matrix[vertex_id][adjacent_vertex_id] != 0  && key[adjacent_vertex_id] > Matrix[vertex_id][adjacent_vertex_id] && Hash[adjacent_vertex_id] == false){
					parent[adjacent_vertex_id] = vertex_id;
					key[adjacent_vertex_id] = Matrix[vertex_id][adjacent_vertex_id];
				} 
			}
		
			Hash[vertex_id] = true;
		}
		
		print( &key[0] , &parent[0] ) ;
		
		
	}
	
	void print(int* key , int* parent){
		for(int i = 1; i < size ; i++){
			cout << parent[i] << " --> " << i  << "    " << key[i] << endl;
		}
		
	}
	int findMin(int* key ,bool * hash){
		int min = INT_MAX, index;
		for(int i = 0 ; i < size ; i++){
			if(key[i] < min && hash[i] == false){
				min = key[i];
				index = i;
			}
		
		}
		return index;
	}
	

};

int main(void){

      int graph[][5] =                 { { 0, 2, 0, 6, 0 },
                                      { 2, 0, 3, 8, 5 },
                                      { 0, 3, 0, 0, 7 },
                                      { 6, 8, 0, 0, 9 },
                                      { 0, 5, 7, 9, 0 } };
          Graph g1(5);
	  g1.Prims(graph);

}


