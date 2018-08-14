#!/bin/bash
max=""
maxlen=0
path=""

function traverse(){
    file=$1
    if [[ -f $file ]];then
        for i in `cat $file`;do
            if [[ ${#i} -gt $maxlen ]];then
                ((maxlen=${#i}))
                max=$i
                path=$file
            fi
        done
    elif [[ -d $file ]];then
        for i in `ls $1`
        do
            traverse $1"/"$i
        done
    fi
}

traverse $1
echo $maxlen
echo $max
echo $path
