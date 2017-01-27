#!/bin/bash

echo Enter two numbers
read a
read b
echo Odd numbers are 
i=`expr $a + 1`
while [ $i -lt $b ]
do
	if [ `expr $i % 2` -eq 1 ]
	then 
		echo $i
	fi
	i=`expr $i + 1`
done
