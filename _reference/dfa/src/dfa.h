#ifndef BTJANAKA_FINITE_AUTOMATA_DFA_SRC_DFA_H
#define BTJANAKA_FINITE_AUTOMATA_DFA_SRC_DFA_H

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace btjanaka {
namespace finite_automata {

using std::string;
using std::unordered_map;
using std::unordered_set;

// Exception for the Dfa class
class DfaException {
 public:
  DfaException();
  DfaException(string msg);

  // Constructs a message saying "<type> '<name>' is not in <thing>", e.g.
  // "alphabet 'a' is not in the alphabet"
  DfaException(string type, string name, string thing);

  // Getter
  string msg();

 private:
  string msg_;
};

// A class to represent a DFA
class Dfa {
 public:
  // Constructs a DFA from the given alphabet, transitions, start state, and
  // accept states. Throws a DfaException if any discrepancies are found in the
  // specifications.
  //
  // Parameters:
  // |alphabet| a set telling the DFA's alphabet
  // |transitions| a map from each state to its transitions in the DFA,
  //   represented by a mapping between input alphabet and resulting string
  // |start| the DFA's start state
  // |accept| set of accepting states for the DFA
  Dfa(const unordered_set<char>& alphabet,
      const unordered_map<string, unordered_map<char, string>>& transitions,
      const string& start, const unordered_set<string>& accept);

  // Evaluates the given input string and tells whether it was accepted. Throws
  // a DfaException if the input has any characters that are not in the machine.
  bool eval(const string& input) const;

 private:
  unordered_set<char> alphabet_;
  unordered_map<string, unordered_map<char, string>> transitions_;
  string start_;
  unordered_set<string> accept_;
};

}  // namespace finite_automata
}  // namespace btjanaka

#endif  // BTJANAKA_FINITE_AUTOMATA_DFA_SRC_DFA_H
