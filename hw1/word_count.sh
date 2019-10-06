#!/bin/bash
# This script returns the number of words containing both of the given 
# arguments. Throws error if wrong number of args are passed

if [ "$#" -lt "2" ]; then
   echo "Incorrect number of arguments given, expected 2"
   exit 1
fi

STR1=$1
STR2=$2

OUT="$(grep $STR1 /usr/share/dict/words | grep $STR2 | wc -w)"
echo "There are $OUT words that have '$STR1' and '$STR2'"
