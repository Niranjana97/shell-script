#!/bin/bash

echo Enter the filename
read file
echo Enter the number to search
read num
grep $num $file
echo number of lines is
grep  -c $num $file
