//
//  pointers.cpp
//  
//
//  Created by Anuya Welling on 12/28/18.
//

#include <iostream>
#include <memory>
using namespace std;

class Test{
public:
    Test(){
        cout<< "created" <<endl;
    }
    void greet(){
        cout << "hello" <<endl;
    }
    ~Test(){
        cout << "destroyed" <<endl;
    }
};

//This class doesnt need a destructor
class Temp{
private:
    unique_ptr<Test[]> pTest2;
public:
    Temp() :pTest2(new Test[2]){};
};
int main(){
    //auto pointer used in c++98
    //autopointers cannot be used on arrays
    {
        unique_ptr<Test> pTest(new Test);
        pTest->greet();
    }//scope of unique pointer limited to here
    
    Temp temp1;
   
    shared_ptr<Test> pTest2 = nullptr;
    //SHARED POINTERS
    //object not deleted till all shared pointers pointing to it are deleted
    //shared_ptr<Test> pTest1(new Test());
    //More Efficiently
    {
        shared_ptr<Test> pTest1 =make_shared<Test>();
        pTest2 = pTest1;
    }//object not destroyed not but after the main function ends
    cout << "Finishined" <<endl;
    
    return 0;
}
