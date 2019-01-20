//
//  compare_exchange.cpp
//  
//
//  Created by Anuya Welling on 1/19/19.
//

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

int main(){
    atomic<int> x(20);
    
    int expected_value1 = 20;
    int expected_value2 = 10;
    
    cout << "expected value 1 : " << expected_value1 << endl;
    bool return_val1 = x.compare_exchange_weak(expected_value1,6);
    
    //Successful hence x gets the desired value
    cout << "Operation successful " << return_val1 << endl;
    cout << "Current expected value " << expected_value1 << endl;
    cout << "Current x : " << x << endl;
    cout << endl;
    atomic<int> y(20);
    cout << "expected value 2 : " << expected_value2 << endl;
    bool return_val2 = y.compare_exchange_weak(expected_value2,6);
    //Not successful hence the expected value gets the desired value
    cout << "Operation successful " << return_val2 << endl;
    cout << "Current expected value " << expected_value2 << endl;
    cout << "Current y : " << y << endl;
    return 0;
}
