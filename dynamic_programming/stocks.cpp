//
//  stocks.cpp
//  
//
//  Created by Anuya Welling on 1/10/19.
//

#include <iostream>
#include <vector>
using namespace std;

int profit(const vector<int> &array){
    int min=array[0];
    int max_profit = 0;
    for(int i=1;i<array.size();i++){
        if(array[i]-min>max_profit){
            max_profit = array[i]-min;
        }
        if(array[i]<min){
            min = array[i];
        }
    }
    return max_profit;
}

int main(){
    vector<int> array{7,1,5,3,6,4};
    cout << "max profit is " << profit(array) << endl;
    cout << "max profit is " << profit({7,6,4,3,1}) << endl;
    return 0;
}
