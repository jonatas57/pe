#!/bin/bash
./randstr 100 100 1 | for i in {00..99}; do read in; echo "$in" > ../in/file$i; done
cd ../in/
for f in file*; do ../bin/gabarito < $f | sort -z > ../out/$f; done
