#!/bin/sh

echo "File Name: $0"
echo "Argument 1: $1"
echo "Argument 2: $2"
echo "Quoted values: $@"
echo "Quoted values: $*"
echo "Total Number of Parameters : $#"
for TOKEN in $*
do
    echo $TOKEN
done
echo "Exit Status $?"