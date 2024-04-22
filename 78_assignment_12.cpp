#include<iostream>
using namespace std;


template<class T>

class items{


public:

    T data;
    int prio;

    

    items() {}  // Default constructor

    items( T d){

        this->data = d;

        cout<<"enter the priority:";
        cin>> prio;

    }
};

template<typename T>

bool operator <=(T val, T val1){

    if (val.prio <= val1.prio){

        return true;
    }
    else {

        return false;
    }

}

template<typename T>
class queue{

    T array[100];
    int f;
    int b;

    public:


    queue(){

        f = -1;
        b = -1;

    }

    void enqueue(T val){


        if (f == -1){
            f++;
            b++;
            array[b] = val;
            return;
        }
        else if (b == 99){

            cout<<"overflow"<<"\n";

            return;
        }
        else{

            b++;
            for(int i = 0; i < b; i++ ){

                if (array[i] <= val){

                    int j = b;
                    while(j > i){

                        array[j] = array[j -1];
                        j--;
                    }

                    array[i] = val;
                    return;
                }
            }
        }

        b++;
        array[b] = val;
        return;

    }


    void deque(){

        if (f == -1){

            cout<<"underflow"<<"\n";

            return;

        }
        f++;

        return;

    }


    void front(){

        if (f == -1){

            cout<<"underflow"<<"\n";
            return;
        }

        cout<<array[f].data<<"\n";
        return;
    }
    
};
int main()
{


    // items<int> s(1);
    // items<int> s1(12);
    // items<int> s2(13);
    // items<int> s3(14);
    // items<int> s4(15);
    // items<int> s5(16);
    // items<int> s6(2);
    // items<int> s7(4);
    // items<int> s8(6);
    // items<int> s9(9);
    // items<int> s10(3);

    // queue<items<int>> q;

    // q.enqueue(s);
    // q.enqueue(s1);
    // q.enqueue(s2);
    // q.enqueue(s3);
    // q.enqueue(s4);
    // q.enqueue(s5);
    // q.enqueue(s6);
    // q.enqueue(s7);
    // q.enqueue(s8);
    // q.enqueue(s9);
    // q.enqueue(s10);

    // q.front();
    queue<items<int>> qu;
    while(true){

        int ch ;
        
        cout<<"enter the choice \n1.create object\2.dequeue\n3.front\n4.exit";
        cin>>ch;
        if (ch == 1){

            int num;
            cout<<"enter the val:"<<"\n";
            cin >> num;
            items<int> obj(num);
            qu.enqueue(obj);


        }
        else if (ch == 2){

            qu.deque();
        }
        else if (ch == 3){

            qu.front();
        }
        else{

            break;
        }
    }

    return 0;
}