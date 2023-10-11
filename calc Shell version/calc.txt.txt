#!/bin/bash

read -p ">> " input
HIST=("" "" "" "" "")

while [ "$input" != "EXIT" ]; do
    read -a array <<< "$input"
    
    if [ "${array[0]}" = "HIST" ]; then
        for i in "${HIST[@]}"; do
            echo "$i"
        done
    else
        flag="OK"

        if [ "${array[0]}" = "ANS" ]; then
            array[0]=$ANS
        fi

        if [ "${array[2]}" = "ANS" ]; then
            array[2]=$ANS
        fi

        if [ "${array[1]}" = "+" ]; then
            ANS=$((array[0] + array[2]))
        elif [ "${array[1]}" = "-" ]; then
            ANS=$((array[0] - array[2]))
        elif [ "${array[1]}" = "*" ]; then
            ANS=$(echo "scale=2; ${array[0]} * ${array[2]}" | bc)
        elif [ "${array[1]}" = "/" ]; then
            if [ "${array[2]}" != "0" ]; then
                ANS=$(echo "scale=2; ${array[0]} / ${array[2]}" | bc)
            else
                flag="MATH ERROR"
            fi
        elif [ "${array[1]}" = "%" ]; then
            ANS=$((array[0] % array[2]))
        else
            flag="SYNTAX ERROR"
        fi

        if [ "$flag" = "OK" ]; then
            echo "$ANS"
            
            for ((i = 1; i < 5; i++)); do
                temp=$((i - 1))
                HIST[$temp]="${HIST[$i]}"
            done
      
            HIST[4]="${input} = ${ANS}"
        else
            echo "$flag"
        fi
    fi

    read -p ">> " input
done