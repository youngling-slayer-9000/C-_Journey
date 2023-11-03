#include<iostream>
using namespace std;
template<typename T>
class Node{
	T data;
	Node* left;
	Node* right;
	Node() : data(0) , left(nullptr) , right(nullptr) {}
	Node(T data) : data(data) , left(nullptr) , right(nullptr){}
};
class BST{
	Node* root;
	BST() : root(nullptr) {}
	
int main(void){


}
