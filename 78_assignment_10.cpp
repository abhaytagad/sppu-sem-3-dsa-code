#include<iostream>
using namespace std;
#include<map>

template<class T>
class node {

    public:

    node* next;
    T val;

    node(T val){

        this->val = val;
        next = NULL;
    }
};

template<class T>

class stack {


    node<T> *head = NULL;

    public:

    void push(T val){
        
        node<T>* new_node = new node<T>(val);

        if (head == NULL){

            head = new_node;
            return;
        }

        node<T>* temp = head;

        head = new_node;

        head->next = temp;
        return;
    }

    char top(){

        return head->val;
    }

    bool isEmpty(){

        if (head == NULL){

            return true;
        }
        return  false;
    }

    void pop(){

        node<T>* temp = head;

        if (head == NULL){

            head = NULL;
            free(temp);
            return;

        }   
        else{

            head = head->next;
            free(temp);
            return;
        }
        
    }

};



string infixtopostfix(string str){

    string result = "";

    stack<char> st;

    map<char,int> m;
    m['('] = 1;
    m[')'] = 2;
    m['*'] = 3;
    m['/'] = 4;
    m['+'] = 5;
    m['-'] = 6;

    for(int i = 0; i < str.length(); i++){

        if (m.find(str[i]) == m.end()){

            result += str[i];
        }
        else{

            if (st.isEmpty()){

                st.push(str[i]);
            }
            else{

               if (m[st.top()] <= m[str[i]]){

                     while(! st.isEmpty() && m[st.top()] <= m[str[i]]){
        
                        result += st.top(); 
                        st.pop();
                    }
                    st.push(str[i]);
               }
               else{

                    
                   st.push(str[i]);
               }
            }
        }
    }
    
    while(! st.isEmpty()){
        
        result += st.top(); 
        st.pop();
    }
    
    return result;

    
}



int eveluate(map<char,int> m, string str){

    stack<int> st;

    for (int i = 0 ; i < str.length(); i++){

        if (m.find(str[i]) == m.end()){

            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();
            if (str[i] == '*'){
                st.push(a*b);
            }
            else if (str[i] == '+'){
                st.push(a+b);
            }
            else if (str[i] == '-'){
                st.push(a-b);
            }
            else if (str[i] == '/'){
                st.push(a/b);
            }

        }
        else{

            st.push(m[str[i]]);
        }
    }

    return st.top();

}


int main(){


    while(true){

        int ch ;
        cout<<"enter the choice \n1.infix to postfix\n2.evalate postfix\n3.exit:\n";
        cin>>ch; 
        if (ch == 1){
            string str;
            cout<<"enter the expression:";
            cin>>str;
            cout<<infixtopostfix(str)<<"\n";

        }
        else if (ch == 2){

            int n ;
            cout<<"enter the number of operand:";
            cin>>n;
            map<char , int> m;
            while (n--)
            {
                char operand ;
                int val;
                cout<<"enter the operand and value:";
                cin>> operand>>val;

                m[operand] = val;
            }

            string str;
            cout<<"enter the expression:";
            cin>>str;

            cout<<eveluate(m,str)<<"\n";

            
        }
        else{

            break;
        }
    }
}