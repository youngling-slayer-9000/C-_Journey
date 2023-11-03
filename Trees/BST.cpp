#include<iostream>
#include<algorithm>
using namespace std;

//Generic Nodes
template<typename T>
class Node{
    T data;
    Node* left ;
    Node* right;
    Node() : data(0) , left(nullptr) , right(nullptr){}
    Node(T data) : data(data) , left(nullptr) , right(nullptr){}
};



/*stack definition*/
class Stack{
public:
    Node* array[20]; int top;
    Stack(){
        top = 0;
        for_each(&array[0] , &array[19] , [](Node* &ptr){
                 ptr = nullptr;
        });
    }

    void push(Node* &ptr){
        if(top == 20)
            return;
        array[top++] = ptr;
    }
    Node* pop(){
        if(top==0)
            return nullptr;
        array[--top];
    }
    bool isEmpty()const{
        if(top==0 || array[top-1] == nullptr)
            return true;
        else return false;
    }
};



class BST{  //BST Definition
    private:
        Node* root
    public:
    /*Inserting a Node recursively*/
    Node* InsertRec(T data,Node* iter){

        if(!iter){
            iter = get(data);
            root = iter;
        }else if(data > iter->data){
            iter->right = InsertRec(data , iter->right);
            iter =root
        }else{
            iter->left = InsertRec(data , iter->left);
        }
        return iter;

    }
    void Insert(T data){
         Node *current ,* successor;
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
         if(data > successor->data){
            successor->right = current;
         }else{
            successor->left = current;
         }
    }


 /*Displaying Elements By PreOrder traversal Recursively and Iteratively*/

    Node* PreOrder_R(Node* iter){    //DLR
        if(iter){
            cout << iter->data << " ";   //Any Process
            PreOrder_R(iter->left);
            PreOrder_R(iter->right);
        }
    }
    void PreOrder(){
        Stack stk;
        Node* ptr = root;
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

    Node* InOrder_R(Node* iter){
        if(iter){
            InOrder(iter->left);
            cout << InOrder << " "     //Any Process
            InOrder_R(iter->right);
        }
    }

    void InOrder(){
        Stack stk;
        Node* ptr = root;
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


    /*Displaying Elements By PostOrder traversal Recursively and Iteratively*/

    Node* PostOrder_R(Node* iter){
        if(iter){
            PostOrder_R(iter->left);
            PostOrder_R(iter->right);
            cout << iter->data << " ";   //Any Process
        }
    }
    void PostOrder(){

    }


    Node* get(T data){
        return (new Node(T data));
    }
};


int main(void){

      Array<5> obj;
      obj.display();
}

