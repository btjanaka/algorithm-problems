# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) minorsetback
# Title: Minor Setback
# Link: https://open.kattis.com/problems/minorsetback
# Idea: Implementation
# Difficulty: medium
# Tags: implementation

import sys
from collections import defaultdict
from math import log

n = int(input())


def calc_a(f):
    return round(12 * log(f / 440, 2)) % 12


note_to_a = {
    "A": 0,
    "A#": 1,
    "Bb": 1,
    "B": 2,
    "C": 3,
    "C#": 4,
    "Db": 4,
    "D": 5,
    "D#": 6,
    "Eb": 6,
    "E": 7,
    "F": 8,
    "F#": 9,
    "Gb": 9,
    "G": 10,
    "G#": 11,
    "Ab": 11,
}

musical_keys = {
    "G major": {"G", "A", "B", "C", "D", "E", "F#"},
    "C major": {"C", "D", "E", "F", "G", "A", "B"},
    "Eb major": {"Eb", "F", "G", "Ab", "Bb", "C", "D"},
    "F# minor": {"F#", "G#", "A", "B", "C#", "D", "E"},
    "G minor": {"G", "A", "Bb", "C", "D", "Eb", "F"},
}

alist = []
aset = set()
for _ in range(n):
    freq = float(input())
    a = calc_a(freq)
    alist.append(a)
    aset.add(a)

musical_keys_a = {}
for k, v in musical_keys.items():
    musical_keys_a[k] = {note_to_a[note] for note in v}

mkey = []
for k, v in musical_keys_a.items():
    if len(aset - v) == 0:
        mkey.append(k)

if len(mkey) != 1:
    print("cannot determine key")
else:
    mkey = mkey[0]
    print(mkey)
    a_to_note = {}
    for note in musical_keys[mkey]:
        a_to_note[note_to_a[note]] = note
    for a in alist:
        print(a_to_note[a])
