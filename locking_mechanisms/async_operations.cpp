//
//  async_operations.cpp
//  
//
//  Created by Anuya Welling on 1/15/19.
//

#include <iostream>
#include <future>
#include <string>

using namespace std;

void printing(){
    cout << "Printing runs on - " << this_thread::get_id() << endl;
}

int add(int x, int y){
    cout << "Adding result : " << x+y << " runs on - " << this_thread::get_id() << endl;
    return x+y;
}

int subtract(int x, int y){
    cout << "Subtract result : " << x-y << " runs on - " << this_thread::get_id() << endl;
    return x-y;
}

int main(){
    cout << "Main thread runs on - " << this_thread::get_id() << endl;
    int x = 100;
    int y = 50;
    future<void> f1 = async(launch::async, printing);
    // runs on the main thread since the launch is deferred
    future<int> f2 = async(launch::deferred, add, x,y);
    //compiler decids if deferred or async is used
    future<int> f3 = async(launch::deferred | launch::async, subtract, x,y);
    
    f1.get();
    cout << "f2 future = " << f2.get() << endl;
    cout << "f3 future = " << f3.get() << endl;
    
    return 0;
}
