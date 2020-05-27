#include "dfa.h"
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace btjanaka {
namespace finite_automata {

using std::pair;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::unordered_set;

//
// DfaException
//

DfaException::DfaException() : msg_("Unspecified error") {}
DfaException::DfaException(string msg) : msg_(msg) {}

DfaException::DfaException(string type, string name, string thing) {
  stringstream ss;
  ss << type << " '" << name << "' is not in " << thing;
  msg_ = ss.str();
}

string DfaException::msg() { return msg_; }

//
// Dfa
//

namespace {

// Checks if any transitions involve alphabets that are not in the alphabet, or
// states that are not in the table. Throws DfaException if so.
void checkTransitions(
    const unordered_map<string, unordered_map<char, string>>& transitions,
    const unordered_set<char>& alphabet) {
  for (const auto& row : transitions) {
    const string& state = row.first;
    const unordered_map<char, string>& t = row.second;
    for (const pair<char, string>& trans : t) {
      if (alphabet.find(trans.first) == alphabet.end()) {
        throw DfaException(state + string(" alphabet"), string(1, trans.first),
                           "alphabets");
      }
      if (transitions.find(trans.second) == transitions.end()) {
        throw DfaException(state + string(" state"), trans.second, "states");
      }
    }
  }
}

// Checks that the start state is in the table; throws DfaException if not.
void checkStart(
    const string& start,
    const unordered_map<string, unordered_map<char, string>>& transitions) {
  if (transitions.find(start) == transitions.end()) {
    throw DfaException("start state", start, "states");
  }
}

// Checks that all accept states are in the table; throws DfaException if not.
void checkAccepts(
    const unordered_set<string>& accept,
    const unordered_map<string, unordered_map<char, string>>& transitions) {
  for (const string& state : accept) {
    if (transitions.find(state) == transitions.end()) {
      throw DfaException("accept state", state, "states");
    }
  }
}

}  // namespace

Dfa::Dfa(const unordered_set<char>& alphabet,
         const unordered_map<string, unordered_map<char, string>>& transitions,
         const string& start, const unordered_set<string>& accept)
    : alphabet_(alphabet),
      transitions_(transitions),
      start_(start),
      accept_(accept) {
  checkTransitions(transitions_, alphabet_);
  checkStart(start_, transitions_);
  checkAccepts(accept_, transitions_);
}

bool Dfa::eval(const string& input) const {
  string state = start_;
  for (char ch : input) {
    if (alphabet_.find(ch) == alphabet_.end()) {
      throw DfaException("alphabet", string(1, ch), "machine alphabet");
    }
    state = transitions_.at(state).at(ch);
  }
  return accept_.find(state) != accept_.end();
}

}  // namespace finite_automata
}  // namespace btjanaka
