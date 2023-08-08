#include <bits/stdc++.h>
using namespace std;

// works on the pricicple of lifo
// use ful
// 1. reversing items
// 2.when to do undo / redo operation or forward/backward

int main(int argc, char const *argv[])
{
    stack<int> s;

    // adding ele in stack
    s.push(1);
    s.push(2);
    s.push(3);

    // removing ele from the stack
    //  ele can be removed only from the top of the stack

    s.pop();

    // no other option of deletion,insetion

    // size of the stack

   s.size();
   //  printing elements of the stack

   while (s.empty()==false)
   {
    cout<<s.top()<<" ";
    s.pop();
   }
   



    return 0;
}
