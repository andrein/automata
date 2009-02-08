#include <deque>
#include <iostream>
#include <cassert>

#include "nfa.h"

/*
Constructs an NFA with:
size    = number of states
initial = initial state
final   = final state
*/
NFA::NFA(unsigned size, state initial, state final){
  this->size=size;
  this->initial=initial;
  this->final=final;
  
  //error checking
  assert(isValidState(initial));
  assert(isValidState(final));
  
  //Initialize transTable with an empty graph, no transitions, and set its dimmensions
  transTable.resize(size, deque<input> (size, NONE));
}

/*
Constructs a copy of another NFA
other = NFA to be copied
*/
NFA::NFA(const NFA& other){
  size=other.size;
  initial=other.initial;
  final=other.final;
  transTable=other.transTable;
}
  

/*
Build a single-transition NFA with two states.
in = input
*/
NFA::NFA(input in){
  size=2;
  initial=0;
  final=1;

  //Initialize transTable with an empty graph, no transitions, and set its dimmensions
  transTable.resize(size, deque<input> (size, NONE));

  addTransition(0, 1, in);
}

/*
Build an union of two NFAs.
*/
NFA NFA::unionNFA(NFA nfa1, NFA nfa2){
  
}

/*
Concatenate two NFAs
*/
NFA NFA::concatenateNFA(NFA nfa1, NFA nfa2){
  
}

NFA& NFA::operator=(const NFA& other)
{
	if (this == &other)
		return *this;
	
	initial = other.initial;
	final = other.final;
	size = other.size;
	transTable = other.transTable;
	
	return *this;
}
/*
Check if the state is valid.
s = state to be checked
*/
bool NFA::isValidState(state s){
  if (s >= size)
    return false;
  return true;
}

/*
Add a transition between two states:
from = start state;
to   = end state;
in   = input
*/
void NFA::addTransition(state from, state to, input in){
  //error checking
  assert(isValidState(from));
  assert(isValidState(to));
  
  transTable[from][to]=in;
}

/*
Insert new states
numStates = number of states to insert
p         = FRONT | BACK

*/
void NFA::insertState(int numStates, position p){
  
  if (numStates<1)
    return;
  
  size+=numStates;
  
  deque< deque<input> >::iterator it;
  
  switch (p){
    case FRONT:
      for (it = transTable.begin(); it < transTable.end(); *++it)
	it->insert(it->begin(), numStates, NONE);
      it = transTable.begin();
      transTable.insert(it, numStates, deque<input> (size, NONE));
      break;
      
    case BACK:
      for (it = transTable.begin(); it < transTable.end(); *++it)
	it->insert(it->end(), numStates, NONE);
      it = transTable.end();
      transTable.insert(it, numStates, deque<input> (size, NONE));
      break;
  }
}

/*
Inserts a NFA into another NFA
*/
void NFA::insertNFA(NFA& other){
  insertState(other.size-1, BACK);
  
}

/*
Display the NFA
*/
void NFA::show() const{
  cout << "The NFA has " << size << " states, numbered from 0 to " << size-1 << "\n";
  cout << "Initial state is " << initial << "\n";
  cout << "Final state is " << final << "\n\n";
  state from, to;
  
  for (from=0; from<size; ++from)
    for (to=0; to<size; ++to){
      input in = transTable[from][to];
      if (in != NONE){
	cout<< "Transition from " << from << " to " << to << " on ";
      if (in!=EPS)
	cout<< "input "<< in << "\n";
      else
	cout<<"empty string" << "\n";
      }
    }
}
