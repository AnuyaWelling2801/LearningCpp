//
//  promises_exceptions.cpp
//  
//
//  Created by Anuya Welling on 1/16/19.
//

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

using namespace std;

void throw_exception(){
    try{
        throw;
    }
    catch(exception &e){
        cout << "number is negative" << endl;
    }
}
void print_result(future<int>& f){
    try{
        int x = f.get();
        cout << "value of square root " << x <<endl;
    }
    catch(exception &e){
        cout << "exception caught - " << e.what() << endl;
    }
}
void calculate_result(promise<int>& prom){
    int x = -9;
    if(x<0){
        throw_exception();
    }
    prom.set_value(sqrt(x));
}

int main(){
    promise<int> prom;
    future<int> f = prom.get_future();
    
    thread printing_thread(print_result, ref(f));
    thread calculation_thread(calculate_result, ref(prom));
    
    printing_thread.join();
    calculation_thread.join();
    
    return 0;
}
