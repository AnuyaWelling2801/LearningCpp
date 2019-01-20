//
//  atomic_flags.cpp
//  
//
//  Created by Anuya Welling on 1/19/19.
//

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

int main(){
    atomic_flag flag = ATOMIC_FLAG_INIT;
    
    //set the flag value to true and return the previous value
    cout << "1. Previous flag value : " << flag.test_and_set() << endl;   //sets to 1 and returns the prev value = 0
    cout << "2. Previous flag value : " << flag.test_and_set() << endl;   //sets to 0 and returns the prev value = 1
    
    //clears the flag value
    flag.clear(); //sets to 0
    cout << "3. Previous flag value : " << flag.test_and_set() << endl; //sets to 1 and returns the prev value = 0
    return 0;
}
