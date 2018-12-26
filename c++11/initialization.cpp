//
//  initialization.cpp
//  
//
//  Created by Anuya Welling on 12/19/18.
//

#include <iostream>
#include<vector>
#include <initializer_list>
using namespace std;

class Test{
public:
    Test(initializer_list<string> texts){
        for(auto value:texts){
            cout<<value<<endl;
        }
    }
};

int main(){
    
    //generalizing the uses of braces
    //can similarly use it for other variables.
    int value{5};
    cout<<value<<endl;
    
    //can even use it with new
    int *pInts = new int[3]{1,2,3};
    cout<<pInts[1]<<endl;
    delete[] pInts;
    
    //works for pointers too
    int *pSomething{&value};
    cout << *pSomething <<endl;
    
    //for nullpointers
    //nullptr is a new c++11 keyword
    //This part is giving me a segmentation fault
    /*int *pSomething2{};
    cout << *pSomething2<<endl;*/
    //can initialize public members of classes using curly brackets
    class C{
    public:
        string text;
        int id;
    };
    C c1 = {"anuya", 28};
    cout<<c1.text<<endl;
    //works for structures too, since structures just aggregate elements
    struct S{
        string text;
        int id;
    };
    S s1 = {"atul", 10};
    cout<<s1.text<<endl;
    //works for anonymous classes too
    struct{
    public:
        string text;
        int id;
    }r1{"hello", 10}, r2{"hi", 28};
    cout<<r1.text<<endl;
    cout<<r2.text<<endl;
    //This fails
    /*struct{
    public:
        string text;
        int id = 7;
    }z1{"hello", 10};
    cout<<z1.text<<endl;*/
    
    //can initialize vector values
    vector<string> strings{"one" , "two", "three"};
    cout<<strings[2]<<endl;
    
    //using initializer lists
    Test test{"one", "two", "three"};
    
    
    return 0;
}
