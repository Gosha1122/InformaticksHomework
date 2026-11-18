#include <iostream>
#include "stack.h"
using namespace std;



int main()
{
    Stack stack;
    stack.push(10);
    stack.push(14);
    stack.push(12);
    stack.push(9);
    stack.push(18);
    stack.push(4);
    stack.print();
    cout << endl;
    stack.sorted();
    stack.print();
}