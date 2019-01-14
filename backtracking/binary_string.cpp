//
//  binary_string.cpp
//  
//
//  Created by Anuya Welling on 1/10/19.
//

#include <iostream>
#include <vector>
using namespace std;

void binary(int i, vector<int> &array){
    if(i==array.size()){
        for(auto a : array){
            cout << a << " ";
        }
        cout <<endl;
        return;
    }
    array[i] = 0;
    binary(i+1, array);
    array[i] = 1;
    binary(i+1, array);
}


int main(){
    int length = 5;
    vector<int> array(length);
    binary(0, array);
    return 0;
}
