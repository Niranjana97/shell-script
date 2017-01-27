#!/bin/bash

echo Enter the filename
read fil

sort -n $fil > sorted
SMALLEST=`head -1 sorted` 
LARGEST=`tail -1 sorted`
rm sorted
echo Smallest is $SMALLEST
echo Largest is $LARGEST

