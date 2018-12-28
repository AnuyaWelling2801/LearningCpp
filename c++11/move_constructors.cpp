//
//  move_constructors.cpp
//  
//
//  Created by Anuya Welling on 12/27/18.
//

#include <iostream>
#include <vector>
using namespace std;

class Test{
public:
    int i;
    Test(){
        cout << "this is a constructor " <<endl;
        this->i = 0;
    }
    Test(int i){
        cout << "this is a parameteriszed constructor" <<endl;
        this->i = i;
    }
    Test(const Test &other){
        cout << "this is a copy constructor" << endl;
        this->i = other.i;
        
    }
    Test(Test &&other){
        cout << "this is a move constructor" <<endl;
        other.i = 0;
    }
};
int main(){
    
    vector<Test> vec;
    vec.push_back(Test());
    return 0;
}
