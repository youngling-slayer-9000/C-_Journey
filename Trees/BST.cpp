#include<iostream>
#include<algorithm>
using namespace std;



/* Modify the 2nd field to your required datatype (Currently set to int) */

typedef int Type ;



//Generic Nodes

template<typename T>
class Node{
public:
    T data;
    Node* left ;
    Node* right;
    Node<T>() : data(0) , left(nullptr) , right(nullptr){}
    Node<T>(T data) : data(data) , left(nullptr) , right(nullptr){}
};



/*stack definition*/
template<typename T>
class Stack{
public:
    Node<T>* array[20]; int top;
    Stack<T>(){
        top = 0;
        for_each(&array[0] , &array[19] , [](Node<T>* &ptr){
                 ptr = nullptr;
        });
    }

    void push(Node<T>* &ptr){
        if(top == 20)
            return;
        array[top++] = ptr;
    }
    Node<T>* pop(){
        if(top==0)
            return nullptr;
        return array[--top];
    }
    bool isEmpty()const{
        if(top==0 || array[top-1] == nullptr)
            return true;
        else return false;
    }
};


template<typename T>
class BST{  //BST Definition
     public:
        Node<T>* root;
       BST<T> () : root(nullptr) {}
   
    /*Inserting a Node recursively*/
    Node<T>* InsertRec(T data,Node<T>* iter){

        if(!iter){
            iter = get(data);
            root = iter;
        }else if(data > iter->data){
            iter->right = InsertRec(data , iter->right);
            iter =root;
        }else{
            iter->left = InsertRec(data , iter->left);
        }
        return iter;

    }
    void Insert(T data){
         Node<T> *current ,* successor;
         current = successor = root;
         while(current){
                successor = current;
            if(data > current->data)
                current = current->right;
            else
                current = current->left;
         }
         if(!successor){
            root = get(data);
            return;
         }
         current = get(data);
         if(data > successor->data){
         
            successor->right = current;
         }else{
            successor->left = current;
         }
    }
    
    Node<T>* Max(Node<T>* iter){
    	if(iter->right != nullptr)
    		Max(iter->right);
    	return iter;
    } 
    
    
    Node<T>* Min(Node<T>* iter){
    	if(iter->left != nullptr)
    		Max(iter->left);
    	return iter;
    } 
    
    
    Node<T>* Delete(Node<T>* iter ,T val){
    	if(val > iter->data) iter->right = Delete(iter->right , val);
    	else if (val < iter->data) iter->left = Delete(iter->left , val);
    	else{  //Found the target node
    	
    		if(iter->right && iter->left){      //case 1 : Two subtrees
    			Node<T>* maxNode = Max(iter->left);
    			iter->data  = maxNode->data;
    			iter->left = Delete(iter->left,iter->data);
    			
    		}
    		else{
    			Node<T>* temp = iter;         //case 2 : Atleast 1 subtree is present 
    			if(iter->left == nullptr)
    				iter = iter->right;
    			
    			if(iter->right == nullptr)
				iter = iter->left;    		
    			delete temp;
    			
    		}
    	
    	}
    	return iter;
    	
    }
    


 /*Displaying Elements By PreOrder traversal Recursively and Iteratively*/

    Node<T>* PreOrder_R(Node<T>* iter){    //DLR
        if(iter){
            cout << iter->data << " ";   //Any Process
            PreOrder_R(iter->left);
            PreOrder_R(iter->right);
        }
    	return nullptr;
    }
    
    void PreOrder(){
        Stack<T> stk;
        Node<T>* ptr = root;
        stk.push(ptr);
        /*Loop ends if the last element  is
           a nullptr OR stack is empty*/
        while(!stk.isEmpty()){ //--main loop
            while(ptr){
                Process(ptr);
                stk.push(ptr);
                ptr = ptr->left;
            }
            ptr = stk.pop();
            ptr = ptr->right;
        } //--end of main loop

    }

    /*Displaying Elements By InOrder traversal Recursively and Iteratively*/

    Node<T>* InOrder_R(Node<T>* iter){
        if(iter){
            InOrder_R(iter->left);
             Process(iter)  ;  //Any Process
            InOrder_R(iter->right);
        }
        return nullptr;
    }

    void InOrder(){
        Stack<T> stk;
        Node<T>* ptr = root;
        stk.push(ptr);
        while(!stk.isEmpty()){
            while(ptr){
                ptr = ptr->left;
                if(!ptr)
                    break;
                stk.push(ptr);
            }

            ptr = stk.pop();
            Process(ptr);
            ptr = ptr->right;
            if(!ptr)
                continue;
            stk.push(ptr);

        }
    }
	
    void Process(Node<T>* temp){
    	cout << temp->data << ' ';
    }

    /*Displaying Elements By PostOrder traversal Recursively and Iteratively*/

    Node<T>* PostOrder_R(Node<T>* iter){
        if(iter){
            PostOrder_R(iter->left);
            PostOrder_R(iter->right);
            cout << iter->data << " ";   //Any Process
        }
        return nullptr;
    }
    


    Node<T>* get(T data){
        return (new Node<T>(data));
    }
};

void Display(){
	cout << "-----------------------MENU-----------------------\n\n"
		"1)Insert(Iterative)              2) Insert(recursive)\n\n"\
	        "3)Delete                         4) PreOrder Traversal(Recursive)\n\n"\
	        "5)PreOrder Traversal(Iterativ)   6)InOrder Traversal\n\n"\
	        "7)InOrder Traversal(Recursive)   8)PostOrder(Recursive)\n\n"\
	        "9)Max Node                       10)MIn Node \n\n";                   
		
}
int main(void){

     BST<Type>obj;
     Display();
     int ch;
     cout << "Enter choice : ";
     Type buff;
     while(cin >> ch){  // Main driver loop
     
     	switch(ch){ //Switch
     		case 1:
     			cout << "Enter value : ";
     			cin >> buff;
     			obj.Insert(buff); 
     			cout << "Done\n"; break;
     		case 2 :
			cout << "Enter value : ";
			cin >> buff;
			obj.InsertRec(buff,obj.root);
			cout << "Done\n"; break;
		case 3:
			cout << "Enter element to be deleted : ";
			cin >> buff;
			if(obj.Delete(obj.root,buff))
				cout << "Deleted\n" ;
			else
				cout << "No such element\n";
			break;
		case 4:
			cout << "PreOrder Traversal : " ;
			obj.PreOrder_R(obj.root); 
			break;
		case 5:
			cout << "PreOrder traversal : ";
			obj.PreOrder();
			break;
		case 6:
			cout << "InOrder Traversal : ";
			obj.InOrder_R(obj.root);
			break;
		case 7:
			cout << "InOrder Traversal : ";
			obj.InOrder();
			break;
		case 8:
			cout << "Post Order : ";
			obj.PostOrder_R(obj.root);
			break;
		case 9:
			cout << "Max Node : " << obj.Max(obj.root)->data << endl;
			break;
		case 10 : 
			cout << "Min Node : " << obj.Min(obj.root)->data << endl;
			break;
		default :
			cout << "Invalid Operation\n"; 
     	
     	
     	} // End of Switch
     	
     	cout << "\nEnter Choice : ";
     
     
     
     
     }// end of while
      
}





