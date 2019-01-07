//
//  mutex.cpp
//  
//
//  Created by Anuya Welling on 1/7/19.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <list>
using namespace std;

list<int> my_list;
mutex m;

void add_to_list(int const &i){
   //can also use a lock guard to have a RAII style mutex
    /* m.lock();
    my_list.push_back(i);
    m.unlock(); */
    lock_gusrd<mutex> lg(m);
    my_list.push_back(i);
}

int main(){
    thread t1(add_to_list,28);
    thread t2(add_to_list,10);
    
    t1.join();
    t2.join();
    
    for(auto x: my_list){
        cout << x << endl;
    }
    return 0;
}

