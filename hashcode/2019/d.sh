g++ graph.cpp -o d.out
for i in {1..10}; do
  echo $i
  d.out < ./d.txt > d_output/d.$i.txt
done
python judge.py -f d.txt d_output
