//
//  templates.cpp
//  
//
//  Created by Anuya Welling on 12/10/18.
//

#include <iostream>
using namespace std;

template<class T>
void print(T n){
    cout<<"template function"<<n<<endl;
}

void print(int n){
    cout<<"non-template version"<<n<<endl;
}

int main(){
    
    print("HELLO");
    print<>(28);
    
    return 0;
}
