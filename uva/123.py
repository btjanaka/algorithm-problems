# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 123
import sys
from collections import defaultdict

ignore = set()
titles = False
kwds = defaultdict(list)
for line in sys.stdin:
    line = line.strip().lower()
    if line == "::":
        titles = True
        continue

    if titles:
        words = line.split()
        for i in range(len(words)):
            if words[i] not in ignore:
                kwds[words[i]].append(
                    " ".join(words[:i] + [words[i].upper()] + words[i + 1:]))
    else:
        ignore.add(line)

for kw in sorted(kwds):
    for title in kwds[kw]:
        print(title)
