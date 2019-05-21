// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) longest-common-subsequence
// Title: The Longest Common Subsequence
// Link: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/
// Idea: Classic DP problem
// Difficulty: easy
// Tags: dp
'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the longestCommonSubsequence function below.
function longestCommonSubsequence(a, b) {
    let an = a.length,
        bn = b.length;
    let dp = [];
    for (let i = 0; i <= an; ++i) dp.push(new Array(bn + 1));

    // Fill out the dp table with the lengths
    for (let i = 0; i <= an; ++i) {
        for (let j = 0; j <= bn; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    // Backtrack through the table to find the actual string
    let i = an,
        j = bn;
    let chars = [];
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            chars.push(a[i - 1]);
            --i;
            --j;
        } else if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else {
            --j;
        }
    }
    chars.reverse();

    return chars;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);
    const nm = readLine().split(' ');
    const n = parseInt(nm[0], 10);
    const m = parseInt(nm[1], 10);
    const a = readLine().split(' ').map(aTemp => parseInt(aTemp, 10));
    const b = readLine().split(' ').map(bTemp => parseInt(bTemp, 10));
    let result = longestCommonSubsequence(a, b);
    ws.write(result.join(" ") + "\n");
    ws.end();
}
