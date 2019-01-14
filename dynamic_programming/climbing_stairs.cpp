//
//  climbing_stairs.cpp
//  
//
//  Created by Anuya Welling on 1/8/19.
//

#include <iostream>
using namespace std;


int climbing_stairs(int n){
    int stairs[n+1];
    //Base case
    stairs[1] = 1;
    stairs[2] = 2;
    for(int i=3;i<=n;++i){
        stairs[i] = stairs[i-1] + stairs[i-2];
    }
    return stairs[n];
}
int main(){
    int n = 45;
    cout << n << " stairs can be clmibed in " << climbing_stairs(n) << " ways";
    return 0;
}
