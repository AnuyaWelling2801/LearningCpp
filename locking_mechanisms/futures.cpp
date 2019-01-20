//
//  futures.cpp
//  
//
//  Created by Anuya Welling on 1/15/19.
//

#include <iostream>
#include <future>
#include <chrono>

using namespace std;


int async_operations(){
    this_thread::sleep_for(std::chrono::milliseconds(3000));
    return 5000;
}

void do_other_operations(){
    cout << "Doing other operations" <<endl;
}

int main(){
    //creator of the async task has the create the future variable associated with the async task.
    future<int> future_answer = async(async_operations);
    do_other_operations();
    //When the creator of async task needs the result of the async task it calls the get method on the future variable
    //blocks of async operation has not been completed
    
    cout << "The answer is : "<< future_answer.get() << endl;
    
}
