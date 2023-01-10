g++ gen.cpp -o run
g++ frogjump.cpp -o cor

for ((i = 12; i <= 100; i++))
do

./run > $i.in
./cor < $i.in > $i.out

done

rm run
