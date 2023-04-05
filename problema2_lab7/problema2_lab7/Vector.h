#pragma once
#include<iostream>
template<class T>
class Vector {
  private:
    unsigned int count;
    T *vector;

  public:
    Vector();
    Vector(const Vector& v);
    Vector(Vector&& v);
    void insert(unsigned int index, T value);
    T& operator[](unsigned int index);
    void remove(unsigned int index);
    void print() const;
    void sort();
    void sort(int (*f)(T x, T y));
};

template <class T>
inline Vector<T>::Vector():count(0) {
    vector = new T[100];
}

template <class T>
inline Vector<T>::Vector(const Vector& v):count(v.count) {
    vector = new T[100];
    for (unsigned int i = 0; i < count; i++)
        vector[i] = v.vector[i];
}

template <class T>
inline Vector<T>::Vector(Vector&& v) {
    count = v->count;
    vector = v.vector;
    v.vector = nullptr;

}

template <class T>
inline void Vector<T>::insert(unsigned int index, T value) {
    if (index<=count) {
        for (unsigned int i = count; i > index; i--)
            vector[i] = vector[i - 1];
        vector[index] = value;
        count++;
    }
}

template <class T>
inline T& Vector<T>::operator[](unsigned int index) {
        return vector[index];
   
}

template <class T>
inline void Vector<T>::remove(unsigned int index) {
    if (index<count) {
        for (unsigned int i = index; i < count - 1; i++)
            vector[i] = vector[i + 1];
        count--;
    }
}

template <class T>
inline void Vector<T>::print() const {
    for (unsigned int i = 0; i < count; i++)
        std::cout << vector[i] << " ";
    std::cout << "\n";
}

template <class T>
inline void Vector<T>::sort() {
    for (unsigned int i=0;i<count;i++)
        for (unsigned int j=i+1;j<count;j++)
            if (vector[i] > vector[j]) {
                T temp = vector[j];
                vector[j] = vector[i];
                vector[i] = temp;
            }

}

template <class T>
inline void Vector<T>::sort(int (*f)(T x, T y)) {
    for (unsigned int i = 0; i < count; i++)
        for (unsigned int j = i + 1; j < count; j++)
            if (f(vector[i],vector[j])==1) {
                T temp = vector[j];
                vector[j] = vector[i];
                vector[i] = temp;
            }
}
