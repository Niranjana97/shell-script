#!/bin/bash

echo "Enter two numbers"
read a
read b
read c
read d
sum=0.0
prod=`expr $a \* $b \* $c \* $d`
sum=`expr $a + $b + $c + $d`
echo "sum is $sum"
echo average is $(echo "scale=2; $sum / 4 " | bc )
echo "product is $prod"
