#include<iostream>
using namespace std;
template<typename T>
class vehicle{
	
public:
	vehicle<T>() : name(0){}
	vehicle<T>(T val) : name(val){}
	void display(){
		cout << name << endl;
	}
private:
	T name;
	

};
template <typename S>
class Bike{
public:
	Bike<S>() : obj(0){}
	Bike<S>(S val) : obj(val){}
	void display(){
		obj.vehicle<S>::display();
	}
	private:
		vehicle<S> obj;

};

int main(void){
	Bike<int> obj(233);
	obj.display();
	
}
