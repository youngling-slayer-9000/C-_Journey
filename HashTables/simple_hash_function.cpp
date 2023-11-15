#include<iostream>
using namespace std;
class Node{
	int key;
	string value;

public:
	Node() : key(-1) {}
	bool add(int k ,string s){
		key = k;
		value = s;
		return true;
	}
	string getValue(){
		return value;
	}
	void display(){
		cout << key << " : " << value << endl;
	}
};


class HashTable{
	Node* arr;
	int size;
	int capacity;
public:
	HashTable() : arr(nullptr) , capacity(0) {}
	HashTable(int s) :size(0), capacity(s){
		arr = new Node[s];
		if(!arr){
			cerr << "Allocation Failed\n";
			exit(EXIT_FAILURE);
		}
	}
	bool Insert(int k , string v){
		int index = Hash(k);
		arr[index].add(k , v);
		size++;
		return true;
	}
        string fetch(int k){
		int index = Hash(k);
		return arr[index].getValue();
	
	}
	int Hash(int key){
		return ((key+98989) % capacity );
		
	}

	void PrintAll(){
		for(int i = 0 ;i < capacity ; i++){
			arr[i].display();
		}
	}
};

int main(void){
	HashTable h1(10);
	h1.Insert(0 , "sharon");
        h1.Insert(8,"Ben");		
	h1.Insert(3, "kodi");	
	cout << h1.fetch(8) << endl;
	h1.PrintAll();
	

}
