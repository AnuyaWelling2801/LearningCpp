//
//  vectors.cpp
//  
//
//  Created by Anuya Welling on 12/12/18.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> strings;
    
    //resizes automatically
    strings.push_back("Anuya");
    strings.push_back("Welling");
    strings.push_back("Atul");
    strings.push_back("Kulkarni");
    
    //undefined behavior
    cout<<strings[1]<<endl;
    
    //get size
    cout << strings.size() << endl;
    
    //traversing the vectors.
    for(vector<string>::iterator it = strings.begin(); it!=strings.end();it++){
        //iterator overloads the * operator
        cout << *it <<endl;
        //iterator also overloads the + operator
    }
    
    
    
    return 0;
}

