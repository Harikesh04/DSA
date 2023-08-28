#include <bits/stdc++.h>
using namespace std;

//Problem:https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);

        return;
    }

    int pop()
    {
        int x;
        if (!q1.empty())
        {
            x = q1.front();
            q1.pop();
        }

        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};


// using one queue.
// class MyStack {
// public:
// queue<int>q1;
// queue<int>q2;
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q2.push(x);

//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }

//         swap(q1,q2);

//         return;
        
//     }
    
//     int pop() {
//         int x;
//         if(!q1.empty()){
//             x=q1.front();
//             q1.pop();

//         }

//         return x;



        
        
//     }
    
//     int top() {
//         return q1.front();
        
//     }
    
//     bool empty() {
//         return q1.empty();
        
//     }
// };


class MyStack {
public:
queue<int>q1;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);

        for(int i=1;i<q1.size();i++){
            q1.push(q1.front());
            q1.pop();


        }

        return;
        
    }
    
    int pop() {
        int x;
        if(!q1.empty()){
            x=q1.front();
            q1.pop();

        }

        return x;



        
        
    }
    
    int top() {
        return q1.front();
        
    }
    
    bool empty() {
        return q1.empty();
        
    }
};

