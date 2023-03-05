set -e
g++ Solution.cpp -o code
g++ gen.cpp -o gen
for((i = 1; i < 2 ; ++i)); do
    ./gen > inp.txt
    ./code < inp.txt > out.txt
done
