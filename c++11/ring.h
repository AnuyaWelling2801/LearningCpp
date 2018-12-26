//
//  ring.h
//  
//
//  Created by Anuya Welling on 12/17/18.
//

#ifndef ring_h
#define ring_h

#include<iostream>
using namespace std;

template<typename T>
class ring{
private:
    int pos;
    int m_size;
    T *m_values;
    
public:
    //its a friend class
    class iterator;
public:
    ring(int size) : m_size(size), m_values(NULL){
        m_values = new T[size];
    }
    ~ring(){
        delete [] m_values;
    }
    int size(){
        return m_size;
    }
    iterator begin(){
        return iterator(0,*this);
    }
    iterator end(){
        return iterator(m_size,*this);
    }
    void add(T value){
        m_values[pos++] = value;
        if(pos==m_size){
            pos=0;
        }
    }
    T &get(int pos){
        return m_values[pos];
    }
};

//making classes iterable
//need begin and end methods

template<class T>
class ring<T>::iterator {
private:
    int m_pos;
    ring &m_ring;
public:
    iterator(int pos, ring &aRing) : m_pos(pos), m_ring(aRing){
        
    }
    iterator &operator++(int){
        m_pos++;
        return *this;
    }
    iterator &operator++(){
        m_pos++;
        return *this;
    }
    T &operator*(){
        return m_ring.get(m_pos);
    }
    
    bool operator!=(const  iterator &other) const{
        return m_pos != other.m_pos;
    }
    void print(){
        cout<<"this is an iterator"<<T()<<endl;
    }
};
#endif /* ring_h */
