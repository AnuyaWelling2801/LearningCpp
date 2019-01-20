//
//  seq_cst.cpp
//  
//
//  Created by Anuya Welling on 1/19/19.
//

#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <assert.h>

using namespace std;

atomic<bool> x,y;
atomic<int> z;

void write_x(){
    x.store(true, memory_order_seq_cst);
}

void write_y(){
    y.store(true, memory_order_seq_cst);
}

void read_x_then_y(){
    while(!x.load(memory_order_seq_cst))
        ;
    
    if(y.load(memory_order_seq_cst)){
        z++;
    }
}

void read_y_then_x(){
    while(!y.load(memory_order_seq_cst))
        ;
        
        if(x.load(memory_order_seq_cst)){
            z++;
        }
}

int main(){
    x = false;
    y = false;
    z = 0;
    
    thread thread_a(write_x);
    thread thread_b(write_y);
    thread thread_c(read_x_then_y);
    thread thread_d(read_y_then_x);
    
    thread_a.join();
    thread_b.join();
    thread_c.join();
    thread_d.join();
    
    assert(z!=0);
    return 0;
}
