#!/bin/bash

echo "Enter a number"
read n
ans=1
for (( i=1; i<=$n; i++ ))
do 
	let ans=ans*$i
done
echo $ans
