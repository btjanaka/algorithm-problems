// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 485
// Title: Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/
// Idea: Keep track of a current count of ones, and when we see a 0, reset the
// count to 0.
// Difficulty: easy
// Tags: math, array
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let max_ones = 0;
    let cur_ones = 0;
    for(let x of nums) {
        if(x == 1) {
            ++cur_ones;
            max_ones = Math.max(max_ones, cur_ones);
        } else {
            cur_ones = 0;
        }
    }
    return max_ones;
};
