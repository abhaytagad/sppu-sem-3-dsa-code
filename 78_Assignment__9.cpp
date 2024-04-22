#include<iostream>
#include<stack>
using namespace std;


bool check(string str){

    stack<char> s;

    for (int i = 0 ; i < str.length(); i++){

        if ((str[i] == ']')){

            if (s.top() == '['){
                
                s.pop();
            }
            else{

                return false;
            }


        }
        else if (str[i] == '}'){

            if (s.top() == '{'){
                
                s.pop();
            }
             else{

                return false;
            }


        }
        else if (str[i] == ')'){

            if (s.top() == '('){

                s.pop();
            }
             else{

                return false;
            }

        }

        else {

            s.push(str[i]);
        }
    }

    if (s.empty()){

        return true;
    }
    else{

        return false;
    }
}


int main(){


    string str = "{{[]}}";

    cout<<check(str);

    return 0;
}