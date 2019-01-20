//
//  package_task.cpp
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

int add(int x, int y){
    cout << "Addition operation calling in thread id - " << this_thread::get_id() << endl;
    return x+y;
}

void task_normal(){
    packaged_task<int(int,int)> task1(add);
    future<int> future_task = task1.get_future();
    //need to explicitly call the task
    task1(100,50);
    cout << "task normal answer - " << future_task.get() << endl;
}

void thread_task(){
    packaged_task<int(int,int)> task1(add);
    future<int> future_task = task1.get_future();
    thread thread_detach(move(task1),100,50);
    thread_detach.detach();
    
    cout << "thread task answer - " << future_task.get() << endl;
}

int main(){
    cout << "Main thread id - " << this_thread::get_id() << endl;
    task_normal();
    thread_task();
    return 0;
}
