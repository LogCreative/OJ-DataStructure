/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include<iostream>
#include<stack>
using namespace std;

// @lc code=start
class MyQueue {
    stack<int> in_stack, out_stack;
    void in2out() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if (out_stack.empty()) {
            in2out();
        }
        int x = out_stack.top();
        out_stack.pop();
        return x;
    }
    
    int peek() {
        if (out_stack.empty()) {
            in2out();
        }
        int x = out_stack.top();
        return x;
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

