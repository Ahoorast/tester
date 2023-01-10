g++ make.cpp -o gen
g++ correct.cpp -o cor
g++ perhapsCorrect.cpp -o sub

for ((i = 0; i < 100; i++))
do
    echo $i;
    ./gen > inp
    ./cor < inp > ansCor
    ./sub < inp > ansSub
    diff ansCor ansSub
    isCor=$?
    if [[ $isCor != 0 ]]
    then
        echo "Found bad testcase"
        exit
    else
        echo "OK"
    fi
done

