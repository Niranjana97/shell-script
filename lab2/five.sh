#!/bin/bash

echo Enter the number
read num
rev=0
while [ $num -gt 0 ]
do
	temp=`expr $num % 10`
	rev=`expr $rev \* 10`
	rev=`expr $rev + $temp`
	num=`expr $num / 10`
done
echo $rev
