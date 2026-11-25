// ExtendingDataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
using namespace std;

//Stack

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
};

template <typename T>
class Stack{
private:
    Node<T>* top;

public:
    Stack(){
        top = nullptr;
    }

    void Push(T value){
        Node<T>* newNode = new Node<T>;

        newNode->data = value;
        newNode->next = top;

        top = newNode;
    }

    T Pop(){
        if(top == nullptr){
            throw runtime_error("Stack is empty");
        }

        T value = top->data;
        Node<T>* temp = top;

        top = top->next;
        delete temp;

        return value;
    }
};

//Queue

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* back;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    void Push(T value) {
        Node<T>* newNode = new Node<T>;

        newNode->data = value;
        newNode->next = nullptr;

        if (back == nullptr) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }
    }

    T Pop() {
        if (front == nullptr) {
            throw runtime_error("Queue is empty");
        }

        T value = front->data;
        Node<T>* temp = front;

        front = front->next;

        if (front == nullptr) {
            back = nullptr;
        }

        delete temp;
        return value;
    }
};

//Quack

template <typename T>
class DNode {
public:
    T data;
    DNode<T>* next;
    DNode<T>* prev;
};

template <typename T>
class Quack{
private:
    DNode<T>* front;
    DNode<T>* back;

public:
    Quack(){
        front = nullptr;
        back = nullptr;
    }

    void push_front(T value){
        DNode<T>* newNode = new DNode<T>;

        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = front;

        if(front != nullptr){
            front->prev = newNode;
        } else{
            back = newNode;
        }

        front = newNode;
    }

    void push_back(T value){
        DNode<T>* newNode = new DNode<T>;

        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = back;

        if (back != nullptr){
            back->next = newNode;
        } else {
            front = newNode;
        }

        back = newNode;
    }

    T pop_front(){
        if (front == nullptr) {
            throw runtime_error("Quack is empty");
        }

        T value = front->data;

        DNode<T>* temp = front;
        front = front->next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            back = nullptr;
        }

        delete temp;

        return value;
    }

    T pop_back() {
        if (back == nullptr) {
            throw runtime_error("Quack is empty");
        
}

        T value = back->data;

        DNode<T>* temp = back;
        back = back->prev;

        if(back != nullptr){
            back->next = nullptr;
        } else{
            front = nullptr;
        }

        delete temp;
        return value;
    }
};

int main(){

	//Test stack
    Stack<int> s;

    s.Push(1);
    s.Push(2);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;

    //Test queue

    Queue<int> q;

    q.Push(3);
    q.Push(4);

    cout << q.Pop() << endl;
    cout << q.Pop() << endl;

	//test quack

    Quack<int> qu;

    qu.push_front(2);
    qu.push_front(1);
    qu.push_back(3);
    qu.push_back(4);

    cout << qu.pop_front() << endl;
    cout << qu.pop_back() << endl;
    cout << qu.pop_front() << endl;
    cout << qu.pop_back() << endl;

    return 0;
}

