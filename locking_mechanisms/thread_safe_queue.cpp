//
//  thread_safe_queue.cpp
//  
//
//  Created by Anuya Welling on 1/15/19.
//

#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>
#include <thread>
using namespace std;


//use condition variables for creating a thread safe class
template<typename T>
class thread_safe_queue{
    mutex m;
    condition_variable cv;
    //queue with the same name to make it easier
    queue<shared_ptr<T>> queue;
    
public:
    thread_safe_queue(){
    }
    
    thread_safe_queue(thread_safe_queue const& other){
        
    }
    
    void push(T& value){
        lock_guard<mutex> lg(m);
        //To avoid exception scenarios that can occur in resource allocation while returning value
        queue.push(make_shared<T>(value));
        //wake up sleeping threads to check condition
        cv.notify_one();
    }
    
    shared_ptr<T> pop(){
        lock_guard<mutex> lg(m);
        if(queue.empty()){
            return shared_ptr<T>();
        }
        else{
            //combine front and pop function
            shared_ptr<T> ref(queue.front());
            queue.pop()
            return ref;
        }
    }
    
    bool empty(){
        lock_guard<mutex> lg(m);
        return queue.empty();
    }
    
    size_t size(){
        lock_guard<mutex> lg(m);
        return queue.size();
    }
    
    shared_ptr<T> wait_pop(){
        unique_lock<mutex> lg(m);
        cv.wait(lg, [this] {
            return !queue.empty();
        });
        shared_ptr<T> ref = queue.front();
        queue.pop();
        return ref;
    }
}

