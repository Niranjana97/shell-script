#!/bin/bash

echo enter two numbers
read a
read b
echo Select the operation
echo 1:Add
echo 2:Subtract
echo 3:Multiply
echo 4:Divide

read op
if [ $op -eq 1 ]
then
	echo Sum is $(echo "scale=2; $a + $b" | bc)
elif [ $op -eq 2 ]
then
	echo Difference is $(echo "scale=2; $a - $b"  | bc)
elif [ $op -eq 3 ]
then
	echo Product is $(echo "scale=2; $a * $b " | bc)
elif [ $op -eq 4 ]
then 
	echo Quotient is $(echo "scale=2; $a / $b" | bc)
else
	echo Invalid operation
fi

