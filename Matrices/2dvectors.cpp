#include<iostream>
#include<vector>
using namespace std;
int main(void){

	int rows, columns;

	cout << "Enter rows and columns : " ;
 	cin >> rows  >> columns;
	vector<vector<int>> matrix = vector(rows , vector<int>(columns,0));
	cout << "Entere elements  ; \n";

	for(int i = 0 ;i < rows ; i++){
		for(int j = 0 ; j < columns ; j++){
			int buff;
			
			cin >> matrix[i][j];		
	         }

	}
	cout << "Entered elements : " << endl;
	for(vector<vector<int>>::iterator iter  = matrix.begin() ; iter!= matrix.end() ; iter++){
		for(int x : *iter)
			cout << x << "  ";
		cout << endl;
	}

}
