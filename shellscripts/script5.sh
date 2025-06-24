#!/bin/bash

# NAME[0]="Max"
# NAME[1]="Lewis"
# NAME[2]="Alonso"
# NAME[3]="Carlos"
# NAME[4]="Lando"
NAME=("Max" "Lewis" "Alonso" "Carlos" "Lando")
echo "Reb bull ${NAME[0]}"
echo "Ferrari ${NAME[1]}"
echo "Aston Martin ${NAME[2]}"
echo "Williams ${NAME[3]}"
echo "Mclaren ${NAME[4]}"
echo "Print all round 1 : ${NAME[*]}"
echo "Print all round 2 : ${NAME[@]}"