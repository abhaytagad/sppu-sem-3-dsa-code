#include<iostream>
using namespace std;
#include<vector>


class node {

public:

    node* next;
    node* prev;
    string status;
    string name;
    int seat_num;
    node(string name){
       
        this->name = name;
        this->status = "not book";
        next =  NULL;
        seat_num = 0;
        prev = NULL;

    }
};


class LinkedList{

    friend class booking_system;

    node* head = NULL;
    node* tail = NULL;

    void insert(int seat_num, string name ){

        if (seat_num > 7){
            cout<<"invalid seat number";
            return;
        }

        node* new_node = new node(name);
        new_node->seat_num = seat_num;
        new_node->status = "booked";

        if (head == NULL){

            head = new_node;
            tail = new_node;
            tail->next = head;
            return;
        }

        node* temp = head;

        head = new_node;
        head->next = temp;
        head->prev = tail;
        tail->next = head;

        return;

    }
   
};


class booking_system{

public:

    LinkedList r1,r2,r3,r4,r5,r6,r7,r8,r9,r10;

    LinkedList Info[10] = { r1,r2,r3,r4,r5,r6,r7,r8,r9,r10} ;


    void book(int seat_num, int row_num, string name){

        if (row_num > 10){

            cout << "invalid row number"<<"\n";
            return;
        }


       Info[row_num - 1].insert(seat_num, name);
           

    }


    void notbooked(){

        for (int i = 0; i < 10; i++){

            if (Info[i].head == NULL){

                cout<<"row number :"<<i+1<<"\n";
                cout<<"seat numbers: "<< 1<<"-"<<7<<"\n";

            }
            else{

                cout<<"row number :"<<i+1<<"\n";

                for (int j = 1; j < 8; j++ ){

                    node* temp = Info[i].head;
                    bool flag = true;
                   
                   
                    while (temp != Info[i].tail){

                        if (temp->seat_num == j){

                            flag = false;
                            break;
                        }
                       
                        
                       
                        temp = temp->next;

                    }

                    if ( Info[i].tail->seat_num == j){
                           
                        flag = false;
                        
                    }
                   
                     
                    if (flag){
                       
                        cout<<"seat numbers: "<<j<<"\n";
                    }
                }
            }
        }
        return;
    }


    void cancle_booking(int seat_num, int row_num){

        node* temp = Info[row_num - 1].head;

        if (temp == NULL){

            cout<<"the booking was not done"<<"\n";
            return;
        }
       
        if (temp->seat_num == seat_num ){
           
            Info[row_num - 1].head = temp->next;
            cout<<"cancled succesfully"<<"\n";
            return;
        }

        while (temp != Info[row_num - 1].tail)

        {
            if (temp->next->seat_num == seat_num){

                temp->next = temp->next->next;
                Info[row_num - 1].tail = temp;
                cout<<"cancled succesfully"<<"\n";
                return;
            }

            temp = temp->next;
        }
       
        node* temp1 = temp->prev;
       
       
        cout<<"the booking was not done"<<"\n";
        return;
   
       
    }


};

int main(){
   
   
    booking_system T;
    // T.book(6,2,"Abhay");
    // T.book(2,2,"Abhay");
    // T.book(4,2,"Abhay");
    // T.book(5,2,"Abhay");
    // T.book(3,2,"Abhay");
    // T.cancle_booking(6,2);
    // T.notbooked();
   
    while(true){
       
        cout<<"enter the choice\n1.book seat\n2.info of vacant seats\n3.cancle booking\n4.exit\n ";
       
        int ch;
        cin>>ch;
       
        if (ch == 1){
            int seat, row;
            string name;
            cout<<"enter the seat number and row number:"<<"\n";
            cin>>seat>>row;
            cout<<"enter the name:"<<"\n";
            cin>>name;
            T.book(seat,row,name);
           
        }
        else if (ch == 2){
           
            T.notbooked();
        }
        else if (ch == 3){
           
            int seat, row;
            cout<<"enter the seat number and row number:"<<"\n";
            cin>>seat>>row;
            T.cancle_booking(seat,row);
           
        }
        else if (ch == 4){
           
            break;
        }
        else {
           
            cout<<"invalid input";
        }
    }
   
    return 0;
}


