# Deterministic Finite Automaton (DFA)

This is an implementation of a deterministic finite automaton in C++. It takes
in a file describing the DFA and starts a prompt where one can enter strings and
see if the DFA accepts them.

## Usage

Build the program (requires g++).

```
make
```

Create an input file. The input file consists of:
1. The transition table for the DFA, which consists of:
  - 1 row specifying the alphabet, e.g. `  |  a  b  c  `. Note the `|` is
    required. Each member of the alphabet must be a single character, and every
    character on this line must be padded by at least one space (unless the
    character is at either end of the line)
  - 1 row of dashes, e.g. `------` (the number does not matter)
  - *n* rows specifying the states, e.g. `q0 | q1 q2 q3`. Each
    state specified must be in the table, and must also have a space surrounding
    it (unless the state is at either end of the line)
1. 1 blank line
1. 1 line specifying the start state - this must be in the transition table
1. 1 blank line
1. *a* lines specifying the accepting states of the DFA

Putting this together, here is an example file:
```
   |  a   b   c
-----------------
q0 |  q1  q2  q3
q1 |  q0  q2  q3
q2 |  q1  q3  q2
q3 |  q3  q3  q3

q0

q3
q2
```

With the file made, run:
```
dfa input.dfa
```
And you will be given a prompt to enter input strings.
