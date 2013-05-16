#!/bin/bash

set -u

types="$(cat types.txt)"
features="$(cat features.txt)"

col_step=8
tput clear

# Header
echo " *                        SLIST    LIST   STAILQ  TAILQ  CIRCLEQ"

# Features
tput cup 1 0
for feature in $features
do
    echo " * $feature"
done

# Table
col=28
for tipo in $types
do
    row=1
    for feature in $features
    do
        tput cup $row $col
        grep -qwF "#define $tipo$feature" ../queue.h && echo + || echo -
        let "row += 1"
    done
    let "col += $col_step"
done
