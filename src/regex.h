#ifndef REGEX_H
#define REGEX_H
#include "nfa.h"
#include <stack>

typedef char input;

class Regex{
  public:
    Regex(input inp[]);
    NFA parse();
    void show();
  private:
    stack<char> opStack;
    
    NFA parser(stack<char>& opStack);
};

#endif // REGEX_H
