# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 860
import sys
from collections import defaultdict
from math import log

counts = defaultdict(int)
for line in sys.stdin:
    line = line.strip()
    if line == "****END_OF_TEXT****":
        tot = sum(counts.values())
        et = sum(
            map(
                lambda x: counts[x] * (log(tot, 10.0) - log(counts[x], 10.0)) / tot,
                counts))
        emax = log(tot, 10.0)
        erel = round(et / emax * 100.0)
        print(f"{tot} {et:.1f} {erel}")
        # reset
        counts = defaultdict(int)
    elif line == "****END_OF_INPUT****":
        break
    else:
        for word in line.split():
            for ch in ",.:;!?\"()":
                word = word.replace(ch, "")
            counts[word.lower()] += 1
