// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 453
// Title: Minimum Moves to Equal Array Elements
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Idea: Each move is equal to decrementing a single element by 1. Find the min
// of all the numbers and subtract it from each number to get the number of
// decrements required.
// Difficulty: easy
// Tags: math, array
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    mn = Math.min(...nums);
    tot = 0;
    for(let x of nums)
        tot += x - mn;
    return tot;
};
