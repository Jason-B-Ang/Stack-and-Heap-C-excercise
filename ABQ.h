//
// Created by Admin on 2/1/2023.
//

#ifndef CLION_PROG2_ABQ_H
#define CLION_PROG2_ABQ_H


#include <iostream>

using namespace std;

template <typename T>
class ABQ{
private:
    unsigned int max_capacity;
    unsigned int curr_size;
    T* arr;
    const double scale_factor = 2.0f;
public:
    ABQ();
    ABQ(int capacity);
    ABQ(const ABQ &d);
    ABQ& operator=(const ABQ& d);
    ~ABQ();
    void enqueue(T data);
    T dequeue();
    T peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
};


template <typename T>
ABQ<T>::ABQ(){
    max_capacity = 1;
    curr_size = 0;
    arr = new T[max_capacity];
}
template <typename T>
ABQ<T>::ABQ(int capacity){
    this->max_capacity = capacity;
    this->curr_size = 0;
    arr = new T[max_capacity];
}
template <typename T>
ABQ<T>::ABQ(const ABQ& d){
    //copy constructor
    this->arr = d.arr;
    this->curr_size = d.curr_size;
    this->max_capacity = d.max_capacity;
}
template <typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& d){
    //asignment opperator
    this->arr = d.arr;
    this->curr_size = d.curr_size;
    this->max_capacity = d.max_capacity;
    return *this;
}
template <typename T>
ABQ<T>::~ABQ(){
    //destructor
    // delete
    delete[] arr;
    curr_size = 0;
    max_capacity = 0;
    arr = nullptr;
}
template <typename T>
void ABQ<T>::enqueue(T data){
    // Add a new item to end of the queue and resizes if necessary.
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
T ABQ<T>::dequeue(){
// Remove the item at front of the queue, resizes if
//  necessary, and return the value removed.
//  Throws a runtime_error if the queue is empty.
    if (curr_size == 0){throw runtime_error("An error has occured.");}else {
        T name = arr[0];
        // cout << name << endl;
        curr_size--;
        for (unsigned int i=0; i <getMaxCapacity()-1;i++){
            arr[i] = arr[i+1];
        }
        if (curr_size < (max_capacity/scale_factor)){
            //  cout << "dafdsai"<<endl;
            max_capacity = max_capacity/scale_factor;
            T* new_max_cap = new T[max_capacity];
            for (unsigned int i=0; i < max_capacity;i++){
                new_max_cap[i] = 0;

            }
            for (unsigned int i=0; i < curr_size;i++){
                new_max_cap[i] = arr[i];
            }
            delete[] arr;
            arr = new_max_cap;
        }

        return name;
    }

}
template <typename T>
T ABQ<T>::peek(){
// Return the value of the item at the top of the
//  stack, without removing it.
//    Throws a runtime_error if the stack is empty
    if (this->curr_size == 0){throw runtime_error("An error has occured.");}else{
        return this->arr[0];
    }
}
template <typename T>
unsigned int ABQ<T>::getSize(){
// Returns the current number of items in the ABS.
    return this->curr_size;
}
template <typename T>
unsigned int ABQ<T>::getMaxCapacity(){
// Returns the current max capacity of the ABS.
    return this->max_capacity;
}
template <typename T>
T* ABQ<T>::getData(){
// Returns the array representing the stack.
    return this->*arr;
}


#endif //CLION_PROG2_ABQ_H
