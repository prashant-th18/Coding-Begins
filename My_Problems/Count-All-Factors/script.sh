set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
# g++ brute.cpp -o brute
# for((i = 1; ; ++i)); do
    ./gen > inp.txt
	./code < inp.txt > ans.txt
    # ./brute < inp.txt > out.txt
    # diff -Z ans.txt out.txt > /dev/null || break
    echo "Passed test: "  $i
# done
# echo "WA on the following test:"
# cat inp.txt
# echo "Your answer is:"
# cat ans.txt
# echo "Correct answer is:"
# cat out.txt
