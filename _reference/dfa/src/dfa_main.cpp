#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "dfa.h"

using btjanaka::finite_automata::Dfa;
using btjanaka::finite_automata::DfaException;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::unordered_set;
using std::vector;

const string USAGE = "Usage: dfa <input-file>";

// Parses the command line arguments to return the input file name
string parseCmdline(int argc, char* argv[]) {
  if (argc != 2) {
    cout << USAGE << endl;
    exit(1);
  }
  return argv[1];
}

// Attempts to read the Dfa from the input file; may catch a DfaException, print
// out the message associated with it, and exit instead.
Dfa readDfa(const string& input_file) {
  try {
    ifstream ifile(input_file.c_str());
    string buf;

    unordered_set<char> alphabet;
    vector<char> alphabet_v;  // holds sequential version of the alphabet
    unordered_map<string, unordered_map<char, string>> transitions;
    string start;
    unordered_set<string> accept;

    // Read alphabets
    getline(ifile, buf);
    stringstream alph_ss(buf);
    alph_ss >> buf;  // throw away the '|'
    while (alph_ss >> buf) {
      if (buf.size() != 1)
        throw DfaException("Each alphabet must be a single character");
      if (alphabet.find(buf[0]) != alphabet.end())
        throw DfaException("duplicate alphabets");
      alphabet.insert(buf[0]);
      alphabet_v.push_back(buf[0]);
    }

    // Throw away dashes
    getline(ifile, buf);

    // Read table rows, up until the blank line
    while (getline(ifile, buf) && !buf.empty()) {
      stringstream ss(buf);
      string state;
      for (int i = 0; ss >> buf; ++i) {
        if (i == 0) {
          state = buf;
          transitions[state] = {};
        } else if (i > 1) {
          transitions[state][alphabet_v[i - 2]] = buf;
        }
      }
    }

    // Get the start state
    getline(ifile, start);

    // Throw away blank line
    getline(ifile, buf);

    // Read accept states
    while (getline(ifile, buf) && !buf.empty()) accept.insert(buf);

    return Dfa(alphabet, transitions, start, accept);
  } catch (DfaException e) {
    cout << "Exception while reading Dfa: " << e.msg() << endl;
    exit(1);
  }
}

void runCmdPrompt(const Dfa& dfa) {
  string input;

  cout << "Starting command prompt" << endl;
  cout << "Press Ctrl+D or Ctrl+C to quit" << endl;

  while (true) {
    cout << "> ";
    if (getline(cin, input)) {
      try {
        cout << (dfa.eval(input) ? "Accepted" : "Rejected") << endl;
      } catch (DfaException e) {
        cout << "Exception: " << e.msg() << endl;
      }
    } else {
      cout << endl;
      break;
    }
  }
}

int main(int argc, char* argv[]) {
  string input_file = parseCmdline(argc, argv);
  Dfa dfa = readDfa(input_file);
  runCmdPrompt(dfa);
  return 0;
}
