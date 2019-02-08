// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10114
#include <bits/stdc++.h>
using namespace std;

int main() {
  int months;
  float down;
  float amt;
  int records;

  scanf("%d %f %f %d", &months, &down, &amt, &records);

  while (months >= 0) {
    float car_val = down + amt;
    float loan_payment = amt / months;

    int month_number = 0;
    float percentage;
    float amt_owed = amt;
    int next_month;

    // Handle month 0. Month 0 is special in that only the car_val goes
    // down. The amt_owed stays the same.
    scanf("%d %f", &month_number, &percentage);
    ++month_number;  // Month number is now 1
    --records;
    car_val -= (percentage * car_val);

    // Go through the rest of the records.
    while (records--) {
      scanf("%d", &next_month);
      for (; amt_owed >= car_val && month_number < next_month; ++month_number) {
        amt_owed -= loan_payment;
        car_val -= percentage * car_val;
        // printf("month: %d, car_val: %f, amt_owed: %f\n",
        // month_number, car_val, amt_owed);
      }
      scanf("%f", &percentage);
    }

    // Cycle until all months are done
    for (; amt_owed >= car_val && month_number <= months; ++month_number) {
      amt_owed -= loan_payment;
      car_val -= percentage * car_val;
      // printf("Month: %d, car_val: %f, amt_owed: %f\n",
      // month_number, car_val, amt_owed);
    }

    // month_number has an unnecessary increase at the end of the for loops
    --month_number;

    // Print final result
    printf("%d month", month_number);
    if (month_number == 1)
      printf("\n");
    else
      printf("s\n");

    // Get next set of data
    scanf("%d %f %f %d", &months, &down, &amt, &records);
  }

  return 0;
}
