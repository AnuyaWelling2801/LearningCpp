//
//  exceptions.cpp
//  
//
//  Created by Anuya Welling on 12/2/18.
//

#include <iostream>
using namespace std;

class CanGoWrong{
public:
    CanGoWrong(){
        char* pMemory = new char[99999999999999999];
        delete [] pMemory;
    }
};
int main(){
    try{
            CanGoWrong wrong;
    }
    catch(bad_alloc &e){
        std::cout<<"Exception caught"<<e.what()<<std::endl;
    }
    return 0;
    
}
