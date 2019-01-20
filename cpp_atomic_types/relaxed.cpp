//
//  relaxed.cpp
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

void write_x_then_y(){
    x.store(true, memory_order_relaxed);
    y.store(true, memory_order_relaxed);
}

void read_y_then_x(){
    while(!y.load(memory_order_relaxed))
        ;
    
    if(x.load(memory_order_relaxed)){
        z++;
    }
}

int main(){
    x = false;
    y = false;
    z = 0;
    
    thread writer_thread(write_x_then_y);
    thread reader_thread(read_y_then_x);
    
    writer_thread.join();
    reader_thread.join();

    return 0;
}
