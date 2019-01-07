//
//  next_permutation.cpp
//  
//
//  Created by Anuya Welling on 1/6/19.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    vector<int> vec{1,2,3};
    vector<vector<int>> result;
    do{
        result.push_back(vec);
    }while(next_permutation(vec.begin(),vec.end()));
    
    for(auto x : result){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
