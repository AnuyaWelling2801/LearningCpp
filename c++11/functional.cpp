//
//  functional.cpp
//  
//
//  Created by Anuya Welling on 12/26/18.
// Lets you easily define a type equivalent to the one referenced to any callable type in c++

//Standard function type - callable - function<return type (parameter type)>

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string &str){
    return str.size()==3;
}

class Check{
public:
    bool operator()(string &str){
        return str.size()==3;
    }
    
}check1;

void run(function<bool(string&)>){
    string test = "stars";
    cout << check(test) <<endl;
}
int main(){
    
    int size = 5;
    vector<string> vec = {"one", "two", "three"};
    
    //count_if is from algorithms
    int count = count_if(vec.begin(),vec.end(),[size](string s){return s.size()==size;});
    cout<<count<<endl;
    
    //works with function pointers and functors too
    cout << count_if(vec.begin(),vec.end(),check) <<endl;
    cout << count_if(vec.begin(),vec.end(),check1) <<endl;
    
    //so basically emulate this behavior of passing anything "callable " to the function and getting an output
    //look at the run function
    run([size](string s){return s.size()==size;});
    run(check);
    run(check1);
    
    return 0;
}
