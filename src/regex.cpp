#include "regex.h"
#include <iostream>
//TODO remove iostream

using namespace std;

Regex::Regex(char inp[]){
  int i;
  for (i=0; inp[i] != 0; ++i)
    opStack.push(inp[i]);
}

NFA Regex::parser(stack<char>& opStack){
  NFA n;
  while (!opStack.empty()){
    switch(opStack.top()){
      case '|':
        opStack.pop();
        n = n | parser(opStack);
      break;
      
      case '*':
        opStack.pop();
        n = n + *parser(opStack);
      break;
    
      case ')':
        opStack.pop();
        n = n + parser(opStack);
      break;
      
      case '(':
        opStack.pop();
        return n;
      break;
    
      default:
        n = n + NFA(opStack.top());
        opStack.pop();
      break;
    }
  }
    return n;
}

NFA Regex::parse(){
  return parser(opStack);
}

void Regex::show(){
  while (!opStack.empty()){
    cout<<opStack.top()<<" ";
    opStack.pop();
  }
  while(!opStack.empty()){
    cout<<opStack.top()<<" ";
    opStack.pop();
  }
}

