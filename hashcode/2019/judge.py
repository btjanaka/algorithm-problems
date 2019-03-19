"""
This code scores either an input and output file,
or finds the max score of outputs from a folder
of inputs and prints the name of the output file.


Instructions:
to score a specific input output file do the following:
    python judge.py a.txt out/a.001.out

to find a max score for an input and a folder of outputs:
    python judge.py -f a.txt out/
"""
# Authors: Pooya Khosravi and Meta Novitia
import sys
from pathlib import Path


def score_file(in_file, out_file, verbose=False):
    """
    Parameters:
    -----------
    in_file: Path object to the input file
    out_file: Path object to the output file

    Returns:
    --------
    score: total score of the output
    """
    inf = open(in_file, 'r')
    outf = open(out_file, 'r')

    ind = [line.split() for line in inf][1:]

    scores = []

    n = int(outf.readline())
    t = [[], []]

    try:
        t[0] = [int(x) for x in outf.readline().split()]
        if len(t[0]) == 1:
            if ind[t[0][0]][0] != "H":
                raise IOError
            t[0] = ind[t[0][0]][2:]

        elif len(t[0]) == 2:
            if ind[t[0][0]][0] != "V" or ind[t[0][1]][0] != "V":
                raise IOError
            t[0] = ind[t[0][0]][2:] + ind[t[0][1]][2:]

    except ValueError:
        print("Non-integer found in output line: " + line)
        return 0
    except IOError:
        return 0

    for i in range(1, n):
        line = outf.readline()
        try:
            nw = i % 2
            ol = (i + 1) % 2
            t[nw] = [int(x) for x in line.split()]
            if len(t[nw]) == 1:
                if ind[t[nw][0]][0] != "H":
                    raise IOError
                t[nw] = ind[t[nw][0]][2:]

            elif len(t[nw]) == 2:
                if ind[t[nw][0]][0] != "V" or ind[t[nw][1]][0] != "V":
                    raise IOError
                t[nw] = ind[t[nw][0]][2:] + ind[t[nw][1]][2:]
                t[nw] = list(set(t[nw]))

            else:
                raise IndexError

            if (nw == 1):
                d = dict()
                for word in t[1]:
                    d[word] = 1
                t[nw] = d

            scores.append(0)
            for word in t[0]:
                if word in t[1]:
                    scores[-1] += 1
            scores[-1] = min(scores[-1],
                             len(t[0]) - scores[-1],
                             len(t[1]) - scores[-1])

        except ValueError:
            print("Non-integer found in output line at line " + str(i + 3) +
                  ": " + line)
            scores.append(0)
            a = []
        except IOError:
            print("Wrong orientation in line " + str(i + 3) + ": " + line)
            return 0
        except IndexError:
            print("IndexError in line " + str(i + 3) + ": " + line)
            return 0

    return sum(scores)


def main():
    if len(sys.argv) >= 4:
        """
        Assumes cli input::
        [0]: '-f' to indicate command, verbose -vf
        [1]: in_file (txt),
        [2]: out_folder
        """
        if sys.argv[1] == '-f' or sys.argv[1] == '-vf' or sys.argv[1] == '-fv':
            verbose = False
            if sys.argv[1] == '-vf' or sys.argv[1] == '-fv':
                verbose = True

            in_file = Path(sys.argv[2])
            out_folder = Path(sys.argv[3])
            out_files = out_folder.glob("{}.*.txt".format(in_file.stem))

            max_score = 0
            max_output_name = ''

            if verbose:
                print("{0:11} {1:7} {2:<9} {3:>14}".format(
                    'Outfile', 'Score', 'Best File', 'Best Score'))
                print("-" * 50)

            for out_file in out_files:
                score = score_file(in_file, out_file, verbose)
                if score > max_score:
                    max_output_name = out_file.name
                    max_score = score

                if verbose:
                    print("{0:9} {1:^9d} {2:9} {3:9d}".format(
                        out_file.name, score, max_output_name, max_score))

            print('Max score: ', max_score)
            print("Max filename: ", max_output_name)

        else:
            print('If more than 4 args provided, include -f as first argument.')

    elif len(sys.argv) == 3:
        """
        Assumes cli input::
        [0]: in_file (txt),
        [1]: out_file (txt)
        """
        in_file = Path(sys.argv[1])
        out_file = Path(sys.argv[2])

        score = score_file(in_file, out_file)

        print("Total score: ", score)

    else:
        print('Not enough inputs!')


if __name__ == "__main__":
    main()
