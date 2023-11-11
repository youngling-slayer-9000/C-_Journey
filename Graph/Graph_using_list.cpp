#include<iostream>
using namespace std;
class Node{
	public:
	int data;    //stores the neighbouring vertex's ID
	Node* next;
	Node() : data(-1) , next(nullptr){}
	Node(int d) : data(d) , next(nullptr){}
};

class List{
	Node* head;
	Node* end;
	
public:
	List() : head(nullptr){}
	List(List& obj){
		this->head = obj.head;
	} 
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
		for(Node* iter = head ; iter ; iter = iter->next)
			cout << x << " --> " << iter->data << endl;
	
	}	

	Node* Begin(){
		return head;
	}

	Node* End(){
		return end;
	}
};


class Queue{
	int arr[100];
	int front, rear;
public:
	Queue() : front(-1) , rear(-1) {}
	 bool Enqueue(int data){
	  //   cout << "Front(En) : " << front << endl;
	  //   cout << "rear(end) : " << rear << endl;
	 	if(front == 99)
			return false;
		 
		 if(rear == -1 && front == -1){
			front++;
			arr[++rear] = data;
			return true;
		 }
		else {
		
			arr[++rear] = data;
		       return	true;
		}

	 
	 }
	 bool isEmpty(){
	 	if(front >  rear|| rear == -1)
	 		return true;
		else return false;
	 }
        int Dequeue(){
        //    cout << "FRONT : " << front << endl;
        //    cout << "rear : " << rear << endl;
            if(front==0 && rear==0){
                rear--;
                return arr[front--];
                
            }
            if(front ==-1 || rear ==-1){
                cout << "empty\n";
                return -1;
            }
            
            return arr[front++];
           
	
	}

};


class Vertex{
public:
	string name;
	List adjacentList ;  //keeps track of neighbouring vertices 
	Vertex() {}
	Vertex(Vertex& obj){
		this->name = obj.name;
		this->adjacentList = obj.adjacentList;
	
	}
};

class Graph{
	int size;
	Vertex* arr;    //for dynamically allocating an array where each element is a "Vertex" which has the data , neighbouring vertices 
public:
	Graph() : size(0) , arr(nullptr) {}
	Graph(int s) : size(s) {
		arr = new Vertex[size];

	}
	
	
	bool addEdge(int origin , int destination ){
		if(origin < size && destination < size){
			
			arr[origin].adjacentList.InsertEnd(destination);
			return true;
		}else{
			cout << "Invalid position" << endl;
			return false;
		}
	}
	
	void print(){
		cout << "digraph {" << endl;
		for(int origin = 0 ; origin < size ; origin++)
			arr[origin].adjacentList.display(origin);

	     cout << "}" << endl;
	
	}
	
	void BFS(int source){
		Queue q;
		bool visited[size] = {false};
		
		
		visited[source] = true;   //make the visited vertex true
		q.Enqueue(source);     //pushing vertex into queue
	
		while(!q.isEmpty()){
		 //   cout << "Do\n";
			 source  = q.Dequeue();
			cout << source << " " << endl  ;   ///displaying the contents of the current vertex
			
			for(Node* iter = arr[source].adjacentList.Begin() ; iter  ; iter = iter->next){
			//	cout << "Neighbouring nodes : ";
			//	arr[source].adjacentList.display(source);
				if(!visited[iter->data]){
	           //    cout << "IF" << endl;                                 
					visited[iter->data] = true;
			//		cout << "iter->data : " << iter->data << endl;
					q.Enqueue(iter->data);
				
				}
			}  
		}


	
	
	}

};


int main(void){
	Graph g1(4);
	g1.addEdge(0,2);
	g1.addEdge(0,1);
	g1.addEdge(1,0);
	g1.addEdge(3,2);
	g1.addEdge(2,3);
	g1.addEdge(2,0);
	g1.BFS(1);



}

