#!/bin/bash
echo Enter two strings
read str1
read str2
string=$str1$str2
echo $string
count=${#string}

echo $count
