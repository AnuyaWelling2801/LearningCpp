//
//  shared_future.cpp
//  
//
//  Created by Anuya Welling on 1/16/19.
//

#include <iostream>
#include <future>
#include <thread>
#include <functional>
#include <numeric>

using namespace std;

void print_future(future<int>& f){
    cout << "future value : " << f.get() << endl;
}

int main(){
    promise<int> prom;
    shared_future<int> f(prom.get_future());
    
    thread print_thread1(print_future, ref(f));
    thread print_thread2(print_future, ref(f));

    //Do not invert the set_value and join. Results in deadlock
    prom.set_value(10);
    
    print_thread1.join();
    print_thread2.join();
}
