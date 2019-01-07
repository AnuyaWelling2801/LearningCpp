//
//  join_and_detatch.cpp
//  
//
//  Created by Anuya Welling on 1/3/19.
//

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void func1(){
    //this_thread - namespace groups a set of functions that access the current thread.
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout<< "Hello from function" << endl;
}

void run_thread(){
    thread thread1(func1);
    thread1.join();
    
    cout << "Hello from main thread 1" <<endl;

    //execution is independent, hence main thread will continue. No syncronization point required
    thread thread2(func1);
    thread2.detach();
    
    cout << "Hello from main thread 2" <<endl;

    
}
int main(){
    run_thread();
    //system("pause");
    return 0;
}

