//
//  threadsafe_Stack.cpp
//  
//
//  Created by Anuya Welling on 1/7/19.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <stack>
using namespace std;

template<typename T>
class trivial_thread_safe_stack{
    stack<shared_ptr<T>> stk;
    mutex m;
public:
    void push(T elem){
        lock_guard<mutex> lg(m);
        stk.push(make_shared<T>(elem));
    }
    
    shared_ptr<T> pop(){
        lock_guard<mutex> lg(m);
        if(stk.empty()){
            throw runtime_error("Stack empty");
        }
        shared_ptr<T> res(stk.top());
        stk.pop();
        return res;
    }
    
    T& top(){
        lock_guard<mutex> lg(m);
        return stk.top();
    }
    
    bool empty(){
        lock_guard<mutex> lg(m);
        return stk.empty();
    }
    
    
};
