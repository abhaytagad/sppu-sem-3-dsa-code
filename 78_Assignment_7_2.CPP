#include<iostream>
using namespace std;

class node{

    friend class linkedlist;
    int val;
    node* next;
    node* prev ;
public:
    node(int val){

        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class linkedlist{

    node* head = NULL;
    node* tail = NULL;
    

public:

    void create(int val){

        while (val > 0){

            int c = val%10;

            if (c != 0 && c!= 1){

                cout<<"invalid number"<<"\n";
                
                return;
            }
            node* new_node = new node(c);

            if (head == NULL){

                head = new_node;
                tail = new_node;

            }
            else{

                node* temp = head;
                head = new_node;
                head->next = temp;
                temp->prev = head;
            }

            val/=10;
        }
    }


    

    void first_complement(){

        node* temp = head;

        while(temp != NULL){

            if (temp->val == 0){
                
                temp->val = 1;
                
            }
            else{
                temp->val = 0;
                
            }

            temp = temp->next;
        }
    }



    void sec_compliment(){

        first_complement();

        int carry = 1;
        node* temp = tail;
       

        while(temp != NULL){

            int sum = temp->val + carry;

            if (sum > 1){

                carry = 1;
                temp->val = 0;
            }
            else {

                temp->val = sum;
                carry = 0;
            }

            temp = temp->prev;
        }

    }

    linkedlist add(linkedlist &b1,linkedlist &b2);


    void display(){

        node* temp = head;

        while (temp != NULL){
            
            cout<<temp->val;
            temp = temp->next;
        }
        cout<<"\n";
    }
};


linkedlist linkedlist:: add(linkedlist &b1,linkedlist &b2){

    linkedlist l;

    int carry = 0;

    node* temp1 = b1.tail;
    node* temp2 = b2.tail;

    while (temp1 != NULL && temp2 != NULL){

        int sum = temp1->val  + temp2->val + carry ;

        if (sum > 1){

            node* new_node = new node(0);
            if (l.head == NULL){
                l.head = new_node;
                l.tail = new_node;
            }
            else{

                node* temp = l.head;
                l.head = new_node;
                l.head->next = temp;
                temp->prev = l.head;
            }

            carry = 1;
        }
        else{

            node* new_node = new node(sum);
            if (l.head == NULL){
                l.head = new_node;
                l.tail = new_node;
            }
            else{

                node* temp = l.head;
                l.head = new_node;
                l.head->next = temp;
                temp->prev = l.head;
            }

            carry = 0;
        }

        temp1 = temp1->prev;
        temp2 = temp2->prev;

    }

    if (temp1 != NULL){

        while (temp1 != NULL){

            int sum = carry + temp1->val;

            if (sum > 1){

                node* new_node = new node(0);

                if (l.head == NULL){
                    l.head = new_node;
                    l.tail = new_node;
                }
                else{

                    node* temp = l.head;
                    l.head = new_node;
                    l.head->next = temp;
                    temp->prev = l.head;
                }

                carry = 1;
            }
            else{

                node* new_node = new node(sum);
                if (l.head == NULL){
                    l.head = new_node;
                    l.tail = new_node;
                }
                else{

                    node* temp = l.head;
                    l.head = new_node;
                    l.head->next = temp;
                    temp->prev = l.head;
                }

                carry = 0;
            }

            temp1 = temp1->prev;

        }
    }

    else if (temp2 != NULL){

        while (temp2 != NULL){

            int sum = carry + temp2->val;

            if (sum > 1){

                node* new_node = new node(0);

                if (l.head == NULL){
                    l.head = new_node;
                    l.tail = new_node;
                }
                else{

                    node* temp = l.head;
                    l.head = new_node;
                    l.head->next = temp;
                    temp->prev = l.head;
                }

                carry = 1;
            }
            else{

                node* new_node = new node(sum);
                if (l.head == NULL){
                    l.head = new_node;
                    l.tail = new_node;
                }
                else{

                    node* temp = l.head;
                    l.head = new_node;
                    l.head->next = temp;
                    temp->prev = l.head;
                }

                carry = 0;
            }

            temp2 = temp2->prev;

        }


    }

    if (carry != 0){
        node* new_node = new node(carry);
        node* temp = l.head;
        l.head = new_node;
        l.head->next = temp;
        temp->prev = l.head;
    }

    return l;

}

int main(){

    linkedlist l1;
    l1.create(10);
    linkedlist l2 ;
    l2.create(101);
    linkedlist l = l.add(l1, l2);
    l.display();

}