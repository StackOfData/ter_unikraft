DEBUG_OUTUP=$1_deb.txt
DEBUG_TIME=$1

for i in {0..99}
do
    { time ops run $DEBUG_TIME
    1>> $DEBUG_OUTUP ; } 2>> $DEBUG_TIME.txt
done

grep "real" $DEBUG_TIME.txt > tmp.txt
cp tmp.txt $DEBUG_TIME.txt
rm tmp.txt