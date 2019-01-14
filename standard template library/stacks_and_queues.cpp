//
//  stacks_and_queues.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test{
private:
    string name;
public:
    Test(string name) : name(name){
    }
    ~Test(){
        cout << "Object Destroyed" << endl;
    }
    void print(){
        cout << name << endl;
    }
};

int main(){
    //LIFO
    stack<Test> testStack;
    testStack.push(Test("Anuya"));
    testStack.push(Test("Atul"));
    testStack.push(Test("Arpita"));
    
    Test test1 = testStack.top();
    test1.print();
    
    //pop does not return. Return is done bu top.
    testStack.pop();
    //If we want to be more efficient, return the reference
    Test &test2 = testStack.top();
    //this is very unreliable code since the reference is popped off the stack.
    //testStack.pop(); //reference will refer to destroyed object.
    test2.print();
    
    //The only way to traverser through a stack is to pop it off
    while(testStack.size()>0){
        Test test1 = testStack.top();
        test1.print();
        testStack.pop();
    }
    cout << endl;
    
    //Queue - FIFO
    queue<Test> testQueue;
    testQueue.push(Test("Anuya"));
    testQueue.push(Test("Atul"));
    testQueue.push(Test("Arpita"));
    
    Test test3 = testQueue.front();
    test3.print();
    
    //pop does not return. Return is done bu top.
    testQueue.pop();
    //If we want to be more efficient, return the reference
    Test &test4 = testQueue.back();
    //this is very unreliable code since the reference is popped off the stack.
    //testStack.pop(); //reference will refer to destroyed object.
    test4.print();
    
    //The only way to traverser through a stack is to pop it off
    while(testQueue.size()>0){
        Test test5 = testQueue.front();
        test5.print();
        testQueue.pop();
    }


    return 0;
}
