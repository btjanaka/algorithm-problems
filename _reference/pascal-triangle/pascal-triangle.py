"""Calculates Pascal's triangle.

Usage:
    python pascal-triangle.py --rows N --output CSV
Example:
    python pascal-triangle.py --rows 500 --output triangle.csv
"""
import argparse
import sys


def calc_pascal(rows: int, outfile: "file object"):
    """Calculates and outputs Pascal's triangle as a CSV.

    Args:
        rows: Number of rows to calculate.
        outfile: Output file handle for writing the results.
    """
    output = [0 for _ in range(rows)]
    for row in range(rows):
        if row == 0:
            # Seed the triangle.
            output[0] = 1
        else:
            # Add up adjacent elements (iterate backwards to make sure we only
            # see elements from the current row and not the next).
            for i in range(row, 0, -1):
                output[i] = output[i] + output[i - 1]
        outfile.write(','.join(map(str, output[:row + 1])) + '\n')


def main():
    """Parses the arguments and run everything."""
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument(
        "--rows",
        type=int,
        help="Number of rows to generate",
        default=10,
    )
    parser.add_argument(
        "--output",
        help="CSV file to save to. Leave out to output to command line",
        default=None,
    )
    args = parser.parse_args()

    write_to_stdout = args.output is None
    outfile = sys.stdout if write_to_stdout else open(args.output, "w")
    calc_pascal(args.rows, outfile)
    outfile.close()


if __name__ == "__main__":
    main()
