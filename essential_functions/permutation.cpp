//
//  permutation.cpp
//  
//
//  Created by Anuya Welling on 1/6/19.
//

#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int> a, int i, int n, vector<vector<int>> res){
    if(i == n){
        cout<< a[0] << a[1] <<a[2] <<endl;
        res.push_back(a);
        return;
    }
    for(int j=i;j<a.size();j++){
        swap(a[i],a[j]);
        permutation(a, i+1, n, res);
        swap(a[i],a[j]);
    }
}


int main(){
    vector<int> a = {1,2,3};
    vector<vector<int>> res;
    permutation(a, 0, a.size()-1, res);
    for(auto x : res){
        for(auto y : x){
            cout << y << " ";
        }
    }
    return 0;
}
