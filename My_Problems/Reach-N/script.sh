set -e
g++ sol.cpp -o code
g++ gen.cpp -o gen
# g++ naiveSol.cpp -o naiveSol
for((i = 1; i < 2 ; ++i)); do
    ./gen > inp.txt
    ./code < inp.txt > out.txt
	# ./naiveSol < inp.txt > cAns.txt
	# diff -Z out.txt cAns.txt > /dev/null || break
done

