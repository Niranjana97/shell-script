#!/bin/bash

echo Enter two numbers
read num
read n
temp=$num
num=$n
n=$temp
echo "After swap $num $n"
