#include <iostream>

//a linked list implementation of the stack data structure using templates.
using namespace std;

template<typename T>
class linkedStack{
private:
    class Node{
    public:
        T data;
        Node* next;
    };
    Node* head = nullptr;
public:
    linkedStack(); //initialize an empty constructor
    bool isEmpty();
    void push(T data);
    T pop();
    ~linkedStack();
};

template<typename T>bool linkedStack<T>::isEmpty() {
    return head = nullptr;
}

template<typename T> void linkedStack<T>::push(T data) {
Node* first = head;
first  = new Node();
first->data = data;
first->next = head;
}

template<typename T>T linkedStack<T>::pop() {
    T data = head->data;
    head = head->next;
    return data;
}

template<typename T>
linkedStack<T>::~linkedStack() { //destructor
  cout <<"we are done";
}


/*Dijkstra's two stack algorithm using the stack*/
int main() {
    string t;
    linkedStack<string> ops;
    linkedStack<double> val;
    while (getline(cin,t)){
        if (t =="(")    ;
        else if (t == "+") ops.push(t);
        else if (t == "*") ops.push(t);
        else if (t == "-") ops.push(t);
        else if (t == ")"){
            string op = ops.pop();
            if (op == "+") val.push(val.pop() + val.pop());
            else if (op == "*") val.push(val.pop() * val.pop());
            else if ( op == "-") val.push(val.pop() - val.pop());
        } else{
            val.push(stod(t));
        }
        cout << val.pop() <<endl;
    }

    return 0;
}
