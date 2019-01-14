//
//  cut_rods.cpp
//  
//
//  Created by Anuya Welling on 1/8/19.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int cut_rods(int n, vector<int>& price){
    vector<int> R(n+1);
    R[0] = 0;
    for(int i=1;i<=n+1;++i){
        int max_val = -1;
        for(int j=1;j<=i;++j){
            int temp = price[j-1] + R[i-j];
            if(temp>max_val){
                max_val = temp;
            }
        }
        R[i] = max_val;
    }
    return R[n];
}

int main(){
    int size = 7;
    vector<int> array(size);
    for(int i=0; i<size; i++){
        array[i] = (rand())+1;
        cout << array[i] << " ";
    }
    cout << "The maximum price is " << cut_rods(size, array) << endl;
    
}
