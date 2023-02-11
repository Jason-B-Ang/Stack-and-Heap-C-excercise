//
// Created by Admin on 1/25/2023.
//

#ifndef CLION_PROG2_ABS_H
#define CLION_PROG2_ABS_H


#include <iostream>

using namespace std;

template <typename T>
class ABS{
private:
    unsigned int max_capacity;
    unsigned int curr_size;
    T* arr;
    const double scale_factor = 2.0f;
public:
    ABS();
    ABS(int capacity);
    ABS(const ABS &d);
    ABS& operator=(const ABS& d);
    ~ABS();
    void push(T data);
    T pop();
    T peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
};


template <typename T>
ABS<T>::ABS(){
    max_capacity = 1;
    curr_size = 0;
    arr = new T[max_capacity];
}
template <typename T>
ABS<T>::ABS(int capacity){
    this->max_capacity = capacity;
    this->curr_size = 0;
    arr = new T[max_capacity];
}
template <typename T>
ABS<T>::ABS(const ABS& d){
    //copy constructor
    this->arr = d.arr;
    this->curr_size = d.curr_size;
    this->max_capacity = d.max_capacity;
}
template <typename T>
ABS<T>& ABS<T>::operator=(const ABS& d){
    //asignment opperator
    this->arr = d.arr;
    this->curr_size = d.curr_size;
    this->max_capacity = d.max_capacity;
    return *this;
}
template <typename T>
ABS<T>::~ABS(){
    //destructor
    // delete
    delete[] arr;
    curr_size = 0;
    max_capacity = 0;
    arr = nullptr;
}
template <typename T>
void ABS<T>::push(T data){
    // add new item to top of stack and resize if necessary
    if (this->curr_size == this->max_capacity){
        // resize
        max_capacity =scale_factor*max_capacity;
        T* new_max_cap = new T[max_capacity];
        // for loop
        for (unsigned int i=0; i < curr_size;i++){
            new_max_cap[i] = arr[i];
        }
        //  new_max_cap[curr_size] = data;
        delete[] arr;
        this->arr = new_max_cap;
        this->arr[curr_size] = data;
        this->curr_size ++;

    }else{
        this->arr[curr_size] = data ;
        this->curr_size ++;
    }
}
template <typename T>
T ABS<T>::pop(){
// Remove the item at the top of the stack, resizes if
//  necessary, and return the value removed.
//   Throws a runtime_error if the stack is empty.
    if (curr_size == 0){throw runtime_error("An error has occured.");}else {
        T name = arr[curr_size - 1];
        curr_size--;
        //  cout << "hi"<<endl;
        if (curr_size < (max_capacity/scale_factor)){
            //  cout << "dafdsai"<<endl;
            // if(((float)curr_size / max_capacity) < (1.0 / scale_factor)){
            max_capacity = max_capacity/scale_factor;
            T* new_max_cap = new T[max_capacity];
            //  cout << "99" << endl;
            for (unsigned int i=0; i <curr_size;i++){
                new_max_cap[i] = arr[i];
            }
            // cout << "103"<< endl;
            delete[] arr;
            arr = new_max_cap;
        }
        return name;
    }

}
template <typename T>
T ABS<T>::peek(){
// Return the value of the item at the top of the
//  stack, without removing it.
//    Throws a runtime_error if the stack is empty
    if (this->curr_size == 0){throw runtime_error("An error has occured.");}else{
        return this->arr[this->curr_size-1];
    }
}
template <typename T>
unsigned int ABS<T>::getSize(){
// Returns the current number of items in the ABS.
    return this->curr_size;
}
template <typename T>
unsigned int ABS<T>::getMaxCapacity(){
// Returns the current max capacity of the ABS.
    return this->max_capacity;
}
template <typename T>
T* ABS<T>::getData(){
// Returns the array representing the stack.
    return this->*arr;
}


#endif //CLION_PROG2_ABS_H
