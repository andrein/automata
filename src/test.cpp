#include "nfa.h"

int main()
{/*
  NFA n(11, 0, 10);
  
  n.addTransition(0, 1, EPS);
  n.addTransition(0, 7, EPS);
  n.addTransition(1, 2, EPS);
  n.addTransition(1, 4, EPS);
  n.addTransition(2, 3, 'a');
  n.addTransition(4, 5, 'b');
  n.addTransition(3, 6, EPS);
  n.addTransition(5, 6, EPS);
  n.addTransition(6, 1, EPS);
  n.addTransition(6, 7, EPS);
  n.addTransition(7, 8, 'a');
  n.addTransition(8, 9, 'b');
  n.addTransition(9, 10, 'b');
  n.insertState(1, FRONT);
  n.addTransition(0, 7, 'c');
  n.insertState(2, BACK);
  n.addTransition(10, 13, 'd');*/
  
  NFA n = NFA('a');
  n.insertState(1,BACK);
  n.addTransition(1,2,'b');
  n.show();
  
  return 0;
}