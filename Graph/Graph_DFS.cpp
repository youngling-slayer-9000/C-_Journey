#include<iostream>
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
    bool* Map;
public:
    Graph() : size(0) , arr(nullptr) , Map(nullptr) {}

    Graph(int s) : size(s){
        arr = new Vertex[size];
        Map = new bool[size];
    }

    void DFS(int source){
        Map[source] = true;
        cout << source << " ";
        //cout << "\n start NOde : " << source << endl;

        for(Node* iter = arr[source].adjacentList.Begin() ; iter != nullptr ; iter = iter->next){
            //cout << "\nadjacent NOdes to " << source << " : ";
          //  cout << iter->data << " ";
            if(!Map[iter->data]){

                DFS(iter->data);
            }


        }

    }
    void AddEdge(int source, int destination){

        if(source < size && destination < size){

            arr[source].adjacentList.InsertEnd(destination);

        }else{
            cout << "Invalid position\n";
        }
    }





};


int main(void){
    const int N = 15;
    Graph graph(N);
      graph.AddEdge(9, 5);
    graph.AddEdge(5, 4);
    graph.AddEdge(5, 3);
	graph.DFS(9);


}
