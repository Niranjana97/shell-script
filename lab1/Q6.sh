#!/bin/bash
echo Enter two valid file names
read fl1
read fl2
cat $fl1 > new
cat $fl2 >> new
echo Content is 
cat new
