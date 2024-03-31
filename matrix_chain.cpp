#include<iostream>
#include<climits>
#include<array>
#define foreach(iter, p) \
    for(const auto& iter : p)
using namespace std;

template<class T, size_t N>
int MatrixChain(const array<T,N>& p){

    array<array<T,N-1>,N-1> table {0}; //2d array all initialized to 0's
    for(int spread = 2 ; spread < p.size() ; spread++){
        
        for(int i = 0 ; i <=  p.size() - spread - 1 ; i++){
            
            int j = i + spread -1;
	    table[i][j] = INT_MAX;
            for(int k = i ; k < j ; k++){
               int temp = table[i][k] + table[k+1][j] + p[i] * p[k+1] * p[j+1];
	       if(temp < table[i][j])
		   table[i][j] = temp;
                
            }
            
        }
        
    }
    return table[0][p.size() -2];

    
    

}

int main(void){
    array<int,5> arr = {40,20,30,10,30};
   cout <<  MatrixChain(arr);
}
