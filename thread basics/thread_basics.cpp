//
//  thread_basics.cpp
//  
//
//  Created by Anuya Welling on 1/3/19.
//

#include <iostream>
#include <thread>
using namespace std;

void func1(){
    cout<< "Hello from function" << endl;
}

class class1{
public:
    void operator()(){
        cout << "Hello from class" << endl;
    }
};


void run_thread(){
    
    
    //The order of printing is not definitive/reproducable
    //task passed as a finction
    thread thread1(func1);
    
    //task passed as a class
    class1 c1;
    thread thread2(c1);
    
    //task passed as a lambda
    thread thread3([]{cout<<"hello from lambda" <<endl;});
    
    //If join not used -> when the destructor is called, stack of those threads is not unwound, it calls std::terminate -> this is not safe
    thread1.join();
    thread2.join();
    //if the thread is in execution it is joinable
    if(thread3.joinable()){
        cout << "thread is joinable" <<endl;
    }
    thread3.join();
    //this is not joinable since its already joined
    if(thread3.joinable()){
        cout << "thread is joinable" <<endl;
    }
    else{
        cout << "thread not joinable since thread already joined" <<endl;
    }
}
int main(){
    run_thread();
    //system("pause");
    return 0;
}
