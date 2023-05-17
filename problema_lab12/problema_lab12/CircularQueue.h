#pragma once
#include<vector>
#include"EmptyQueueExcept.h"
using namespace std;
template <class T>
class CircularQueue {
  private:
    T* queue;
    int front_index;
    int back_index;
    unsigned int size_queue;
    unsigned int capacity;

  public:
    CircularQueue(unsigned int max);
    void push(T value);
    T pop();
    T& front();
    T& back();
    unsigned int size();
    bool empty();

};
template <class T>
inline CircularQueue<T>::CircularQueue(unsigned int max): capacity(max),front_index(-1),back_index(-1),size_queue(0) {
    queue = new T[capacity];
}
template <class T>
inline void CircularQueue<T>::push(T value) {
    back_index = (back_index + 1) % capacity;
    queue[back_index] = value;
    if (front_index == -1)
        front_index++;
    if (back_index == front_index and size_queue == capacity)
        front_index = (front_index + 1) % capacity;
    if (size_queue < capacity)
        size_queue++;
}
template <class T>
inline T CircularQueue<T>::pop() {
    if (size_queue == 0)
        throw EmptyQueueExcept{};
    T value = queue[front_index];
    size_queue--;
    front_index = (front_index + 1) % capacity;
    return value;
}
template <class T>
inline bool CircularQueue<T>::empty() {
    return !(size_queue>0);
}
template <class T>
inline unsigned int CircularQueue<T>::size() {
    return size_queue;
}
template <class T>
inline T& CircularQueue<T>::back() {
    if (size_queue == 0)
        throw EmptyQueueExcept{};
    /*return queue[back_index];*/
    return queue[size_queue - 1];
}
template <class T>
inline T& CircularQueue<T>::front() {
    if (size_queue == 0)
        throw EmptyQueueExcept{};
 
   /* return queue[front_index];*/
    return queue[0];
}