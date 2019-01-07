//
//  thread_ownership.cpp
//  
//
//  Created by Anuya Welling on 1/4/19.
//

#include <iostream>
#include <thread>
using namespace std;

void func1(){
    cout<< "Hello from function 1" << endl;
}
void func2(){
    cout<< "Hello from function 2" << endl;
}

void run_code(){
    
    thread t1(func1);
    //this will be a compile time error since the copy constructor is deleted
    //thread t2 = t1;
    
    //move works. Join on t1 will not do anything. Thread1 points to a nullpointer.
    thread t2 = move(t1);
    
    //this works. Implicit call to move constructor
    t1 = thread(func2);
    
    thread t3 = move(t2);
    
    //this is wrong, it compiles though. t1 gets the ownership of t3, the thread owned previously by t1 is not joined, hence the program is unsafe
    //t1 = move(t3);
    
    t1.join();
    //t3.join();
}
int main(){
    
    run_code();
    return 0;
}
