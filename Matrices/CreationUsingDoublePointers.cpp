#include <iostream>
using namespace std;
int main() {
    int** d2array;    //declaration of pointer-to-pointer which points to to the beginning of each row
    int rows,columns;
    
    cout << "Rows and Columns: ";
    cin >> rows >> columns; 
    
    int* d1array[rows];  //array of pointers that is responsible for storing each rows in a matrix
    
    for(int i = 0 ; i < rows ; i++)
        d1array[i] = new int[columns];
    d2array = &d1array[0];
    cout << "Enter elements : \n";
    for(int i =0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            cin >> *(*(d2array+i)+j); //d2array[i][j]
            
        }
        
    }
    cout << "Elements in matrix : \n";
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            
            cout <<    *(*(d2array+i) + j)  << ' ';  //d2array[i][j]
        }
        cout << endl;
        
    }
}
