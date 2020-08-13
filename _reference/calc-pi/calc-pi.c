// Calculates pi given a pseudo-random number generator.
//
// Essentially, this program generates ITERATIONS points inside of the sqaure
// with corners at [1,1],[-1,1],[-1,-1],[1,-1] and figures out what proportion
// of those points are inside the unit circle. This ratio multiplied by 4 gives
// an estimate of pi.
//
// You are probably wondering, why 4? This is because we define pi to be the
// ratio of the circle's area and the radius squared
// (i.e. A/r^2 = pi --> A = pi * r^2). Say the unit circle has a radius r, then
// the square has sides of 2r and area 4r^2. Then, the ratio of the area of the
// circle to the area of the square is A / 4r^2 = pi / 4 -- thus, we multiply
// our calculated proportion by 4.
//
// Usage:
//   calc-pi ITERATIONS [RANDOM_SEED]
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

void usage() { printf("Usage: calc-pi ITERATIONS [RANDOM_SEED]\n"); }

// Generates a random double in the range [-1, 1]. Could probably be better.
double RandomDouble() { return rand() * 2.0 / RAND_MAX - 1; }

// Generates a random point in the square [-1, 1] by [-1, 1] and returns whether
// that point was <= 1 unit of the origin.
bool RandomPointInCircle() {
  double x = RandomDouble(), y = RandomDouble();
  double squared_dist = x * x + y * y;
  return squared_dist <= 1.0;
}

int main(int argc, char* argv[]) {
  // Parse command line flags.
  bool use_seed = false;
  long long iterations, seed;
  switch (argc) {
    case 3: {
      use_seed = true;
      seed = atoi(argv[2]);
    }
    case 2: {
      iterations = atoi(argv[1]);
      break;
    }
    default: {
      usage();
      exit(1);
    }
  }

  // Seed the generator if needed for reproducibility.
  if (use_seed) {
    srand(seed);
  }

  // Generate random points and figure out if they are inside the circle.
  long long inside_circle = 0, outside_circle = 0;
  for (long long i = 0; i < iterations; ++i) {
    if (RandomPointInCircle()) {
      ++inside_circle;
    } else {
      ++outside_circle;
    }
  }

  // Use the ratio of points inside the circle to get pi.
  printf("pi: %.9lf\n", 4.0 * inside_circle / (inside_circle + outside_circle));

  return 0;
}
