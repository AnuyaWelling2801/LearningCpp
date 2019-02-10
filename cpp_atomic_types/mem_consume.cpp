//
//  mem_consume.cpp
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

struct X{
    int i;
    string S;
};

atomic<X*> p;
atomic<int> a;

void create_x(){
    X* x = new X;
    x->i = 42;
    x->S = "Hello";
    
    a.store(20,memory_order_relaxed);
    p.store(x,memory_order_release);
}

void use_x(){
    X* x;
    while(!(x=p.load(memory_order_consume)))
        ;
    assert(x->i = 42);
    assert(x->S = "Hello");
    //not deterministic if this assert will fire
    assert(a.load(memory_order_relaxed)==20);
}

int main(){
    thread thread_a(create_x);
    thread thread_b(use_x);
    
    thread_a.join();
    thread_b.join();
    return 0;
}
