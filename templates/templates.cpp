//
//  templates.cpp
//  
//
//  Created by Anuya Welling on 12/10/18.
//

#include <iostream>
using namespace std;

template<class T>
class Test{
private:
    T obj;
public:
    Test(T obj){
        this->obj = obj;
    }
    void print() {
        cout << obj << endl;
    }
};

int main(){
    Test<int> test1(28);
    test1.print();
    
    return 0;
}
