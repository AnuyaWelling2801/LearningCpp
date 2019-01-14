//
//  chain.cpp
//  
//
//  Created by Anuya Welling on 1/10/19.
//

#include <iostream>
#include<vector>
#include<array>
using namespace std;

int link(int i,int j,int size, vector<vector<int>> array){
    if(j<0 or j>=size){
        return 0;
    }
    if(i==size-1){
        return 1;
    }
    if(array[i][j]>0){
        return array[i][j];
    }
    int a = link(i+1,j-1,size,array);
    int b = link(i+1,j,size,array);
    int c = link(i+1,j+1,size,array);
    //cout<< a+b+c;
    array[i][j] = a+b+c;
    return array[i][j];
}

int main(){
    int size = 3;
    vector < vector < int > > array(size, vector< int >(size,0));
    cout << link(0,0,size, array) << endl;
}
