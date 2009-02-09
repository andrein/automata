#include "nfa.h"

int main()
{
  NFA a = NFA('a');
  NFA b = NFA('b');
  NFA x = NFA('b');
  x = x + b + a + *(b|a);
  x.show();
  
  return 0;
}