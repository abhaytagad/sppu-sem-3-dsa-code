#include<iostream>
using namespace std;
#include<vector>


class node{

public:

    float start;
    float end;
    string status;
    node* next;
    

    node(float start, float  end){

        this->start = start;
        this->status = "not book";
        this->end = end;
        next = NULL;
        
        
    }


};

class linkedlist{

    node* head = NULL;

public:

    void book_slot(float start , float end){

        node* new_node = new node(start, end);

        if ((start > end) or (start > 24) or (end > 24)){

            cout<<"the Aponintment can not be shedule or invalid input"<<"\n";
        }
        

        if (head == NULL){
           
            head = new_node;
            new_node->status = "book";
            cout<<"the apointment is booked succusefully"<<"\n";
            return;
        }

        node* curr = head;

        while (curr->next != NULL){
            
            node* front = curr->next;
           
            if (curr->end != front->start){

                if ((curr->end <= start ) and (front->start >= end)){
                    
                    curr->next = new_node;
                    new_node->status = "book";
                    new_node->next = front;
                    cout<<"the apointment is booked succusefully"<<"\n";
                    return;
                }
                else if ((front->start < end) and (front->start > start)){

                    cout<<"the apointment can not book . please reduse the time"<<"\n";
                    return;

                }
            }

            curr = curr->next;



        }
        if ((start < head->start) and (end <= head->start) ){

            curr = head;
            head = new_node;
            new_node->status = "book";
            head->next = curr;
            cout<<"the apointment is booked succusefully"<<"\n";
            return;
        }
        
        curr->next = new_node;
        new_node->status = "book";
        cout<<"the apointment is booked succusefully"<<"\n";

        return;

    }


    void cancle_slot(float start , float end){

        node* temp = head;

        bool flag = false;

        while (temp->next != NULL){
            
            if ((temp->next->start == start) and (temp->next->end == end)){

                flag = true;

                if (temp->next->next != NULL){

                    node* node_delet = temp->next;
                    temp->next = temp->next->next;
                    free(node_delet);
                    cout<<"the apointment is cancled succusefully"<<"\n";
                    return;
                }
                temp->next = NULL;
                cout<<"the apointment is cancled succusefully"<<"\n";
                return;


            }
            temp = temp->next;
        }

        if ((head->start == start) and (head->end == end)){

            node* node_delet = head;
            head = head->next;
            free(node_delet);

            cout<<"the apointment is cancled succusefully"<<"\n";
        
            return;

        }
        if (! flag ){

            cout<<"the apointment was not sheduled"<<"\n";
            return;
        }
    }
        

    void free_slot(){
        
        node* curr = head;
       
        bool flag = false;

        while (curr->next != NULL){
            
            node* front = curr->next;

            if (curr->end != front->start){

                flag = true;
                cout<<"free slot is: "<<curr->end<<" - " <<front->start<<"\n";
            }
            curr = curr->next;
            

        }
        if ((curr->end != head->start) and (curr != head)){

            cout<<"free slot is: "<<curr->end<<" - " <<head->start<<"\n";


         }

        if (! flag){

            cout<< "free slot is not present "<<"\n";

        }
        return;


    }

};


int main(){

    linkedlist Sheduled;

    while (true){

        
        int ch ;
        cout<<"\n";
        cout<<"1. book Apointment\n2. Display free slot\n3. cancle Apointment\n4. exit\n";
        cout<<"\n";
        cin>>ch;

        if (ch == 1){
            
            float start,end;
            cout<<"enter start and end time"<<"\n";
            cin>>start>>end;
            Sheduled.book_slot(start,end);

        }
        else if (ch == 2){
            
            Sheduled.free_slot();

        }
        else if (ch == 3){

            float start,end;
            cout<<"enter start and end time"<<"\n";
            cin>>start>>end;
            Sheduled.cancle_slot(start, end);

        }
        else if (ch == 4){

            break;
        }
        else{

            cout<<"invalid input"<<"\n";

        }


    } 

}