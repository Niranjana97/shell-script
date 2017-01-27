#!/bin/bash

echo Enter the number
read num
sum=0
while [ $num -gt 0 ]
do
	temp=`expr $num % 10`
	sum=`expr $sum + $temp`
	num=`expr $num / 10`
done
echo $sum
