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
    
    //pre-sized vector, every element initalized to 1
    vector<double> numbers(20, 1);
    //Actual number of array you have in the array
    cout << numbers.size() << endl;
    //This capacity increases as we add more elements
    int capacity = numbers.capacity();
    cout << capacity <<endl;
    for(int i=0;i<10000;i++){
        numbers.push_back(i);
        //capacity increases exponentially
        if(numbers.capacity()!=capacity){
            capacity = numbers.capacity();
            cout << "Capacity : " << numbers.capacity() << endl;
        }
        
    }
    numbers.clear();
    cout << "Size after clearing the vector : " << numbers.size() <<endl;
    //capacity remains the max
    cout << "Capacity after clearing the vector : " << numbers.capacity() << endl;
    
    numbers.resize(100);
    cout << "Size after resizing the vector : " << numbers.size() <<endl;
    //capacity remains the max
    cout << "Capacity after resizing the vector : " << numbers.capacity() << endl;
    
    //to change capacity
    numbers.reserve(1000000);
    //size remains the same
    cout << "Size after reserving the vector : " << numbers.size() <<endl;
    //capacity changes to a greater number, does not change to a lesser number
    cout << "Capacity after reserving the vector : " << numbers.capacity() << endl;


    
    
    return 0;
}

