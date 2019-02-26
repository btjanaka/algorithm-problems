# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 11239
from collections import defaultdict
import sys

projects = defaultdict(set)
students = defaultdict(set)
last_proj = ""

for line in sys.stdin:
    if line[0] == "1":
        for s in students:
            if len(students[s]) > 1:
                for p in students[s]:
                    projects[p].remove(s)
        for p, c in sorted([(p, len(projects[p])) for p in projects],
                           key=lambda x: (-x[1], x[0])):
            print(f"{p} {c}")
        projects.clear()
        students.clear()
    elif line[0] == "0":
        break
    else:
        line = line.strip()
        if line[0].isupper():
            last_proj = line
            projects[last_proj] = set()
        else:
            projects[last_proj].add(line)
            students[line].add(last_proj)
