//
//  function_pointer1.cpp
//  
//
//  Created by Anuya Welling on 12/11/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string name){
    return name.size() == 3;
}

int countStrings(vector<string> &texts, bool (*func)(string text)){
    int tally = 0;
   /* for(int i=0;i<texts.size();i++){
        if(func(texts[i])){
            tally++;
        }
    } */
    for(auto x : texts){
        if(func(x)){
            tally++;
        }
    }
    return tally;
}

int main(){
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    
    cout << count_if(texts.begin(), texts.end(), match)<<endl;
    cout << countStrings(texts,match) <<endl;
    return 0;
}
