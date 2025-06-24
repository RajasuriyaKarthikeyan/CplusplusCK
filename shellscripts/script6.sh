#!/bin/bash

num1=0
num2=10
sum=$(expr $num1 + $num2)
echo "Sum $sum"
dif=$(expr $num2 - $num1)
echo "dif $dif"
mul=$(expr $num1 \* $num2)
echo "mul $mul"
div=$(expr $num1 / $num2)
echo "div $div"
mod=$(expr $num1 % $num2)
echo "mod $mod"
equality=$(expr $num1 == $num2)
echo "equal check $equality"
not_equality=$(expr $num1 != $num2)
echo "not equal $not_equality"


if [ $num1 -ne $num2 ];then
    echo "$num1 is not equal to $num2"
fi

if [ $num1 -le $num2 ];then
    echo "$num1 is less than or equal to $num2"
else 
    echo "$num1 is great than to $num2"
fi

str1="Suriya"
str2="Deeksha"

if [ "$str1" = "$str2" ]; then
    echo "Strings are equal"
else
    echo "Strings are not equal"
fi

if [ -z "$str1" ]; then
    echo "String is empty"
else
    echo "String is not empty"
fi

file="script1.sh"

if [ -e "$file" ]; then
    echo "$file exists"
else
    echo "$file does not exist"
fi

if [ -f "$file" ]; then
    echo "$file is a regular file"
else
    echo "$file is not a regular file"
fi

if [ $num1 -eq $num2 ] || [ $num1 -le $num2 ];then
    echo "OR operator works"
else 
    echo "OR not woriking"
fi

if [ $num1 -eq $num2 ] && [ $num1 -le $num2 ];then
    echo "AND Operator not works"
else 
    echo "AND working "
fi