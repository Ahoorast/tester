mx=0
read code
rm $code.verdict
TLE=7000

g++ $code.cpp -o run

for ((i = 1; i <= 100; i++))
do 

echo -e "\e[1;34m Running on test $i... \e[0m"

start=`date +%s%N`

./run < $i.in > out

end=`date +%s%N`

runtime=$((end-start))
runtime=$(($runtime/1000000))

if [[ $runtime -gt $mx ]]
then
	mx=$runtime
fi

diff $i.out out
iscor=$?

echo Test $i >> $code.verdict

if [[ $runtime -gt $TLE ]]
then 
	echo Time Limit Exceeded >> $code.verdict
elif [ $iscor != 0 ] 
then
	echo WRONG ANSWER >> $code.verdict
else 
	echo ACCEPTED >> $code.verdict
fi

done

rm out
rm run
echo $mx
vim $code.verdict


