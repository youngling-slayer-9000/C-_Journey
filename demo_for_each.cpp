#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* Only under the lambda function can you define a generic code that
    instructs wth to do with each element retrieved from the list*/

template<typename PTR,typename T>
void demo_for_each(PTR start, PTR end , T func){
    for(;start != end ; start++)
        func(*start);
}


int main(void){

    int arr[] = {1,2,3,4,5,6};
    size_t size = sizeof(arr)/sizeof(arr[0]);

   // float arr[5] = {89.3 , 12.67 , 90.8 , 90.90, 0.23,}
    demo_for_each(&arr[0] , &arr[size] , [](auto x){
                  //ANONYMOUS FUNCTION (lambda expression cxx+20)
                    cout << x << " ";
    }

    );

}
