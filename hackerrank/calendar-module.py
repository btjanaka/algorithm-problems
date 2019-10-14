# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) calendar-module
# Title: Calendar Module
# Link: https://www.hackerrank.com/challenges/calendar-module/problem
# Idea: Implementation
# Difficulty: easy
# Tags: calendar
import calendar
month, day, year = map(int, input().split())
print(calendar.day_name[calendar.weekday(year, month, day)].upper())
