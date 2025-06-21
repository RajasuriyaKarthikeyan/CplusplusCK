#!/bin/bash

a=0

while [ $a -lt 10 ]
do
    echo $a 
    ((a++))
done

for fruit in apple banana apricot
do
    echo $fruit
    for i in {1..5}
    do
        echo $i
        if [ $i -eq 2 ]; then
            break 2             #break the fruit loop
        fi
    done
done

for ((j=0; j<10; j++))
do
    echo $j
    if [ $j -eq 5 ]; then
        echo "Continue loop 5"
        continue 
    fi
done

for file in $(ls)
do  
    echo $file
done

b=0
until [ $b -eq 5 ]
do
    if [ $b -eq 3 ]; then
        break
    fi
    echo "No break until $b"
    ((b++))
done
