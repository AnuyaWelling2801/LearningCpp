//
//  thread_parameters.cpp
//  
//
//  Created by Anuya Welling on 1/4/19.
//

#include <iostream>
#include <thread>
using namespace std;

//passing to a function by reference
void func1(int x, int y){
    cout<< "Hello from function " << x + y  << endl;
}

//passing to a function by reference
void func2(int &x){
    while(true){
        cout << "Value of x :" << x << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

}
int main(){
    
    //Passing by value
    thread t1(func1,1,2);
    t1.join();
    
    //passing by reference
    int x = 0;
    //make sure you are passing the ref.
    thread t2(func2, ref(x));
    this_thread::sleep_for(chrono::milliseconds(5000));
    
    x=28;
    cout << "main thread changes value of x to : " << x << endl;
    t2.join();
    
    return 0;
}
