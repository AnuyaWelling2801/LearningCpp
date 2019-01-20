//
//  atomic_bool.cpp
//  
//
//  Created by Anuya Welling on 1/19/19.
//

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

int main(){
    atomic<bool> flag_1;  //true by default
    cout << "flag_1 : " << flag_1 << endl;
    //cannot use copy constructor - error: call to implicitly-deleted copy constructor of 'atomic<bool>'
    //atomic<bool> flag_2(flag_1);
    
    //not copy assignable -  error: call to implicitly-deleted copy constructor of 'atomic<bool>'
    //atomic<bool> flag_3 = flag_1;
    
    //construct using non atomic boolean types
    bool non_atomic = true;
    atomic<bool> flag_4(non_atomic);
    cout << "flag_4 : " << flag_4 << endl;

    //assign using non atomic boolean value
    //atomic<bool> flag_5 = non_atomic; //dunno why this isnt working
    //cout << "flag_5 : " << flag_5 << endl;

    atomic<bool> x(false);
    cout << "Is atomic variable implemented lock free - " << (x.is_lock_free() ? "yes" : "no") << endl;
    
    atomic<bool> y(true);
    
    //store operations
    x.store(false);
    x.store(y);
    
    //load operation
    cout << "value of the atomic bool : " << x.load() << endl;
    
    //exchange operation
    bool z = x.exchange(false);
    cout << "Previous value of x : " << z << endl;
    cout << "New value of x : " << x.load() << endl;
    return 0;
}
