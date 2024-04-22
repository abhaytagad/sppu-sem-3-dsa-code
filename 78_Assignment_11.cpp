
#include<iostream>
using namespace std;


class node {

    public:

    node* next;
    string job;

    node(string val){

        job = val;
        next = NULL;

    }
};


class linkedlist{

    public:

    node* head ;
    node* tail;

    linkedlist(){

        head = NULL ;
        tail = NULL;
    }

    void insert(string val){

        node* new_node = new node(val);

        if (head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        tail = new_node;

    }

    void pop(){

        if (head == NULL){
            cout<<"underflow"<<"\n";
            return;
        }
        else if (head->next == NULL){
            head =NULL;
            return;
        }
        else{

            head = head->next;

        }
    }


};

class queue{

    linkedlist q;
    public:

    void enqueue(string val){

        q.insert(val);

        return;
    }


    void dequeue(){

        q.pop();
        return;
    }


    void front(){

        if (q.head == NULL){
            cout<<"Underflow\n";
            return;
        }

        cout<<q.head->job<<"\n";

        cout<<"\n";


    }
};

int main()
{

    
    return 0;
}