// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) max-min
import java.io.*;
import java.util.*;

public class Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int k = in.nextInt();
    ArrayList<Integer> arr = new ArrayList<>();
    for (int i = 0; i < n; ++i) arr.add(in.nextInt());
    Collections.sort(arr);

    int mn_i = 0, mn = arr.get(k - 1) - arr.get(0);
    for (int i = 1; i + k <= arr.size(); ++i) {
      int diff = arr.get(i + k - 1) - arr.get(i);
      if (diff < mn) {
        mn = diff;
        mn_i = i;
      }
    }
    System.out.println(mn);
  }
}
