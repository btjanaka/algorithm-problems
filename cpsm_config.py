# Configuration file for CPSM

# Command to run for opening the files when starting a new solution
editor = "vim -p"

# Should CPSM open the input file along with the code file? This is particularly
# useful if your editor does not support files
open_input = True

# When saving, should CPSM add and commit the files to git? You can choose to
# do this for one, both, or none of the code and input files
save_code_to_git = True
save_input_to_git = False

# Abbreviations for directories and full names of websites/competitions/etc.
# Abbreviations should be of the following form:
#   "(abbrev)": {
#       "name": "(full name of website/competition/etc)",
#       "dir": "(name of directory)",
#       # Whether or not to create input files for problems in this directory
#       "create_input_file": True/False,
#   },
abbreviations = {
    "uva": {
        "name": "UVa",
        "dir": "uva",
        "create_input_file": True,
    },
    "ka": {
        "name": "Kattis",
        "dir": "kattis",
        "create_input_file": True,
    },
    "hr": {
        "name": "HackerRank",
        "dir": "hackerrank",
        "create_input_file": True,
    },
    "lc": {
        "name": "LeetCode",
        "dir": "leetcode",
        "create_input_file": False,
    },
    "cf": {
        "name": "CodeForces",
        "dir": "codeforces",
        "create_input_file": True,
    },
    "cj": {
        "name": "CodeJam",
        "dir": "codejam",
        "create_input_file": True,
    },
    "ks": {
        "name": "KickStart",
        "dir": "kickstart",
        "create_input_file": True,
    },
}

# Mapping of strings that can be inserted into the templates below. Note that
# the following keys are reserved for use by CPSM:
#   "name" - the name of the website/competition/etc for the problem
#   "problem_name" - the title of the problem
# If you include these keys, they simply will not be used.
mappings = {
    "username": "btjanaka",
    "fullname": "Bryon Tjanaka",
}

# Mapping of template names. Each template should be of the following form:
#   "(template name)": {
#       "filetype": "(file extension to use with this template)",
#       "code": "(code for the template)",
#   },
# Substitution in the code is done using Jinja's Template.render(), with the
# mappings above. In short, you can represent variables from the mappings above
# by putting them in double curly braces, e.g. {{ variable }}. Refer to the
# Jinja docs at http://jinja.pocoo.org/docs/2.10/ for more info.
templates = {
    "cpp": {
        "filetype":
            "cpp",
        "code":
            """\
// Author: {{username}} ({{fullname}})
// Problem: ({{name}}) {{problem_name}}
// Title:
// Link:
// Idea:
// Difficulty:
// Tags:
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  return 0;
}
""",
    },
    "cpp-blank": {
        "filetype":
            "cpp",
        "code":
            """\
// Author: {{username}} ({{fullname}})
// Problem: ({{name}}) {{problem_name}}
// Title:
// Link:
// Idea:
// Difficulty:
// Tags:
""",
    },
    "c": {
        "filetype":
            "c",
        "code":
            """\
// Author: {{username}} ({{fullname}})
// Problem: ({{name}}) {{problem_name}}
// Title:
// Link:
// Idea:
// Difficulty:
// Tags:
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;

int main() {

  return 0;
}
""",
    },
    "c-blank": {
        "filetype":
            "c",
        "code":
            """\
// Author: {{username}} ({{fullname}})
// Problem: ({{name}}) {{problem_name}}
// Title:
// Link:
// Idea:
// Difficulty:
// Tags:
""",
    },
    "java-blank": {
        "filetype":
            "java",
        "code":
            """\
// Author: {{username}} ({{fullname}})
// Problem: ({{name}}) {{problem_name}}
// Title:
// Link:
// Idea:
// Difficulty:
// Tags:
""",
    },
    "js-blank": {
        "filetype":
            "js",
        "code":
            """\
// Author: {{username}} ({{fullname}})
// Problem: ({{name}}) {{problem_name}}
// Title:
// Link:
// Idea:
// Difficulty:
// Tags:
""",
    },
    "py": {
        "filetype":
            "py",
        "code":
            """\
# Author: {{username}} ({{fullname}})
# Problem: ({{name}}) {{problem_name}}
# Title:
# Link:
# Idea:
# Difficulty:
# Tags:

import sys
from collections import defaultdict

""",
    },
    "py-blank": {
        "filetype":
            "py",
        "code":
            """\
# Author: {{username}} ({{fullname}})
# Problem: ({{name}}) {{problem_name}}
# Title:
# Link:
# Idea:
# Difficulty:
# Tags:
""",
    },
    "py2": {
        "filetype":
            "py2",
        "code":
            """\
# Author: {{username}} ({{fullname}})
# Problem: ({{name}}) {{problem_name}}
# Title:
# Link:
# Idea:
# Difficulty:
# Tags:

import sys
from collections import defaultdict

""",
    },
    "py2-blank": {
        "filetype":
            "py2",
        "code":
            """\
# Author: {{username}} ({{fullname}})
# Problem: ({{name}}) {{problem_name}}
# Title:
# Link:
# Idea:
# Difficulty:
# Tags:
""",
    },
    "hs": {
        "filetype":
            "hs",
        "code":
            """\
-- Author: {{username}} ({{fullname}})
-- Problem: ({{name}}) {{problem_name}}
-- Title:
-- Link:
-- Idea:
-- Difficulty:
-- Tags:

import Data.List

main = do

"""
    },
    "hs-blank": {
        "filetype":
            "hs",
        "code":
            """\
-- Author: {{username}} ({{fullname}})
-- Problem: ({{name}}) {{problem_name}}
-- Title:
-- Link:
-- Idea:
-- Difficulty:
-- Tags:
""",
    },
}

# A mapping of filetypes to a list of commands that should be run during run
# mode. Each command should be of the form:
#   "(filetype)": {
#       ["(command 1)", "(command 2)", ...],
#   },
# Each command is interpreted as a jinja template, and there is only one
# variable, "problem_name", that is used during substitution. "problem_name"
# consists of the filename of the problem, with directories prepended to it.
run_commands = {
    "cpp": [
        "g++ {{ problem_name }}.cpp -o {{ problem_name }}.out",
        "{{ problem_name }}.out < {{ problem_name }}.txt",
    ],
    "c": [
        "gcc {{ problem_name }}.c -o {{ problem_name }}.out",
        "{{ problem_name }}.out < {{ problem_name }}.txt",
    ],
    "py": ["python {{ problem_name }}.py < {{ problem_name }}.txt",],
    "py2": ["python2 {{ problem_name }}.py2 < {{ problem_name }}.txt",],
}
