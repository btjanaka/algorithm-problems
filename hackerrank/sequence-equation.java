// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) sequence-equation
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    ArrayList<Integer> p = new ArrayList();
    int n = in.nextInt();
    for (int i = 0; i < n; ++i) {
      p.add(in.nextInt());
    }
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        if (p.get(p.get(y - 1) - 1) == x) {
          System.out.println(y);
          break;
        }
      }
    }
  }
}
