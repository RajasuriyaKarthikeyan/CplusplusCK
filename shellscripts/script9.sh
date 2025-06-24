#!/bin/bash

Hello() {
    echo "Name $1 $2"
    return 10
}

Hello Suriya Karthikeyan
echo $?