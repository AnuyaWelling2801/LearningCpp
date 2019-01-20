//
//  promises.cpp
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

void print_int(future<int>& f){
    cout << "waiting for value from the main thread " << endl;
    cout << "future value : " << f.get() << endl;
}

int main(){
    promise<int> prom;
    future<int> f = prom.get_future();
    
    thread print_thread(print_int, ref(f));
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "Setting the value in the main thread" << endl;
    //Do not invert the set_value and join. Results in deadlock
    prom.set_value(10);
    
    print_thread.join();
}
