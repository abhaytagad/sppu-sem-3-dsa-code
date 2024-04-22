#include<iostream>
using namespace std;


const int size = 100;

template <class T>
 
class deque{
   
   
    int ptr;
    
    T array[size];

public:

    deque(){

        ptr = 0;
        
    }

    void push_back(T val){

        ptr++;

        if (ptr > size){
            
            cout<<"qeue full"<<"\n";
            return;
        }
        
        array[ptr - 1] = val;
        return;
    }

    

    void push_front(T val){

        ptr++;

        if (ptr > size){
            
            cout<<"qeue full"<<"\n";
            return;
        }

        int i = ptr ;

        while (i > 0){

            array[i] = array[i-1];
            i--;
        }

        array[i] = val;

        return;
        
    }

    void  pop_front(){

        if (ptr == 0){

            cout<<"array is empty"<<"\n";
            return;
        }

        int i = 0;
        while(i < ptr - 1){

            array[i] = array[i + 1];
            i++;

        }
        ptr--;
        return;
    }

    void pop_back(){

        if (ptr == 0){

            cout<<"array is empty"<<"\n";
            return;
        }

        ptr--;

    }

   void front(){

        cout<<array[0]<<"\n";
        return;
   }

   void back(){

        cout<<array[ptr - 1]<<"\n";
   }
    void display(){

        
        for (int i = 0; i < ptr ; i++ ){
            cout<<array[i]<<" ";
        }
        return;
    }

};



int main()
{

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(4);
    
    dq.front();
    dq.back();

    return 0;
}