DEBUG_OUTUP=$1_deb.txt
DEBUG_TIME=$1

for i in $(seq 0 99)
do
    ops run $DEBUG_TIME\
    | tail -n1 1>> $DEBUG_TIME.txt
done
