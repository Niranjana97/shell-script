#!/bin/bash

echo Enter number to find factorial
read num
i=1
fact=1
while [ $i -le $num ]
do 
	fact=`expr $fact \* $i`
	i=`expr $i + 1`
done
echo $fact
