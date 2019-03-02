# g++ graph.cpp -o b.out
for i in {101..200}; do
  echo $i
  b.out < ./b.txt > b_output/b.$i.txt
done
python judge.py -f b.txt b_output
