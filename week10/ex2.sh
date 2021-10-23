touch ../week1/file.txt
link ../week1/file.txt _ex2.txt
inode=$(ls -i _ex2.txt | cut -d ' ' -f 1)
find .. -inum "$inode" >> ex2.txt
find .. -inum "$inode" -exec rm {} \; >> ex2.txt
