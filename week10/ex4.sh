touch tmp/file1.txt
touch tmp/file2.txt
ln tmp/file1.txt tmp/link1
gcc ex4.c -o ex4.out
./ex4.out > ex4.txt
