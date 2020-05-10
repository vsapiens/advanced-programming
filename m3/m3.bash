#!/bin/bash

grep -oE '#[[:alnum:]_]+' kulturform.html | sort --unique > hashtags.txt

while read LINE; do
    grep -o -i "$LINE" kulturform.html | wc -l >>  count.txt
done <hashtags.txt

paste -d " " hashtags.txt count.txt > result.txt
cat result.txt