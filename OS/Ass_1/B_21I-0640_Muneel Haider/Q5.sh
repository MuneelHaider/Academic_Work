# Muneel Haider
# 21i-0640
# Assignment 1 - OS

option=$1
num1=$2

if [ $option = "left" ]
then
    
    for ((i=1; i <= num1; i++))
    do
        for((j=1; j <= $(($num1 - i + 1)); j++))
        do
            echo -n "*"

        done

        echo
    done

elif [ $option = "inverted_full" ]
then

    for((i=1; i <= num1; i++))
    do
        for((j=1; j <= i; j++))
        do
            echo -n "*"

        done

        for((j=0; j < $num1 - i; j++))
        do
            echo -n " "

        done

        for((j=1; j <= $num1 - i + 1; j++))
        do
            echo -n " "

        done

        for((j=1; j <= i; j++))
        do
            echo -n "*"

        done

        echo
    done

elif [ $option = "full_right" ]
then

    for((i=1; i <= num1; i++))
    do
        for((j=1; j <= i; j++))
        do
            echo -n " "

        done

        for((j=1; j <= $(($num1 - i + 1)); j++))
        do
            echo -n "*"

        done

        echo
    done
fi