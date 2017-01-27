#!/bin/sh
echo Enter the length and breadth of rectangle
read l
read b
echo Enter the radius of circle
read r
pi=3.14

echo perimeter of rectangle is $(echo "scale=2; 2 * ($l + $b )" | bc)
echo Area of rectangle is $(echo "scale=2; $l * $b" | bc)
echo Circumference of circle is $(echo "scale=2; (2 * $pi) * $r" | bc) 
echo Area of circle is $(echo "scale=2; $pi * ($r * $r)" | bc)

