//
//  auto.cpp
//  
//
//  Created by Anuya Welling on 12/17/18.
//

#include <iostream>
using namespace std;


//can use auto as the return type for functions
// -> would mean a trailing return type. Useful fot template functions
template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2){
    return value1 + value2;
}

int get(){
    return 999;
}

//stupid function that does nothing except return the value of get()
auto test2() -> decltype(get()){
    return get();
}

int main(){
    
    //auto is the default storage class specifier. Can miss out the type declaration all together
    cout<<test(4,8)<<endl;
    cout<<test2()<<endl;
}
