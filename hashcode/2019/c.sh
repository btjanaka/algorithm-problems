for i in {1..100}; do
  c.out < c.txt > c_output/c.$i.txt
done
python judge.py -f c.txt c_output
