//
//  spinlock_mutex.cpp
//  
//
//  Created by Anuya Welling on 1/22/19.
//

#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <assert.h>

using namespace std;

class spinlock_mutex{
    
    atomic_flag flag = ATOMIC_FLAG_INIT;
public:
    spinlock_mutex(){}
    void lock(){
        while(flag.test_and_set(memory_order_acquire));
    }
    void unlock(){
        flag.clear(memory_order_release);
    }
};

spinlock_mutex m;

void func(){
    lock_guard<spinlock_mutex> lg(m);
    cout << this_thread::get_id() << " hello "<< endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
}

int main(){
    thread t1(func);
    thread t2(func);
    
    t1.join();
    t2.join();
    return 0;
}
