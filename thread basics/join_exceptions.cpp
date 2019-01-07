//
//  join_exceptions.cpp
//  
//
//  Created by Anuya Welling on 1/3/19.
//

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void func1(){
    cout<< "Hello from function" << endl;
}

void other_operations(){
    throw runtime_error("this is a runtime error");
}

class thread_guard{
    thread &t;
public:
    explicit thread_guard(thread &_t): t(_t){}
    //calls join in the destructor, hence when the main function exits or if an exception occurs, thread guard will be destructed and hence the thread will be joined
    ~thread_guard(){
        if(t.joinable()){
            cout << "thread guard destructor called" <<endl;
            t.join();
        }
    }
   // thread_guard(thread_guard & const) = delete;
   // thread_guard & operator = (thread_guard & const) = delete;
};
void run_thread(){
    thread thread1(func1);
   /* try{
        //this will give an error since an exception is thrown and join in never called, resulting in an unsafe application
        //other_operations();
        //thread1.join();
        //We have to use RAII here. Refer to the thread guard class.
    }
    catch(...){
        
    } */
    //Instead do this
    thread_guard tg(thread1);
    other_operations();
}
int main(){
    run_thread();
    //system("pause");
    return 0;
}
