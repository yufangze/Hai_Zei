#!/bin/bash 
max=200000
prime=(for 1 in max+5)
for ((i=0; i<=max+5; i++));do
    prime[i]=0
done
for ((i=2; i<=max; i++));do
    if [[ ${prime[i]} -eq 0 ]];then
        ((prime[++prime[0]]=${i}))
    fi
    for ((j=1; j<=prime[0]; j++));do
        if [[ ${prime[j]}\*${i} -gt max ]];then
            break
        fi
        ((prime[prime[j]*i]=1))
        if [[ ${i}\%${prime[j]} -eq 0 ]];then
            break
        fi
    done
done
for ((i=1; i<=prime[0]; i++));do
    echo ${prime[i]}
done
