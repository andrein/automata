#ifndef NFA_H
#define NFA_H
#include <deque>

using namespace std;

typedef unsigned state;
typedef char input;

enum {
  EPS = -1,
  NONE = 0,
};

enum position{
  FRONT = -1,
  BACK = 1,
};

class NFA{
  public:
    NFA();
    NFA(unsigned size, state initial, state final);
    NFA(const NFA& other);
    NFA(input in); //create a basic NFA on input in
/*    NFA unionNFA(NFA nfa1, NFA nfa2);
    NFA concatenateNFA(NFA nfa1, NFA nfa2);
    NFA starNFA(NFA nfa);*/
    NFA& operator=(const NFA& other);
    NFA& operator+(const NFA& other); //concatenation operator: a+b=ab
//    NFA& operator+();                 //a+ is the equivalent of aa*
    NFA& operator*(); //Kleen closure / Star operator: a*
    NFA& operator|(NFA& other); //union operator: a|b 
    
    void show() const;

    //TODO are those really needed?
/*    void setInitialState(state s) {initial=s;}
    void setFinalState(state s) {final=s;}
    unsigned getSize() {return size;}
    */
    // TODO those should be private
    void addTransition(state from, state to, input in);
    void insertState(int numStates, position p);
  private:
    state initial;
    state final;
    unsigned size;
    deque< deque <input> > transTable;

    bool isValidState(state s);
    void insertNFA(const NFA& other);
};
#endif // NFA_H
