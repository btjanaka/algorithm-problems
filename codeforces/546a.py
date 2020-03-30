# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeForces) 546a
# Title: Soldier and Bananas
# Link: https://codeforces.com/problemset/problem/546/A
# Idea: See if you can figure out the code golf :D
# Difficulty: easy
# Tags: implementation
k,n,w=map(int,input().split());print(max(0,w*(w+1)//2*k-n))
