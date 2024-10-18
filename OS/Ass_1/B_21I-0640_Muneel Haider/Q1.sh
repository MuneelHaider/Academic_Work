# Muneel Haider
# 21i-0640
# Assignment 1 - OS

PrimeCheck() {
    num=$1

    if [ $num -lt 2 ] 
    then
        return 1
    fi

    for((i = 2; i * i <= num; i++))
    do
        if [ $((num % i)) -eq 0 ]
        then

            return 1
        fi
    done

    return 0  # Prime
}

echo "Enter the number of integers to check:"
read n

> first_bash.txt

count=0

while [ $count -lt $n ]
do

    echo "Enter integer:"
    read num

    if [ $num -gt 10 ] && [ $num -lt 100 ]
    then
    
        if PrimeCheck $num
        then

            echo "Wow, we’ve found a prime number: $num"
        else

            echo "$num" >> first_bash.txt
        fi

        ((count++))
    fi
done

echo "Username: $USER" >> first_bash.txt
echo "Timestamp: $(date)" >> first_bash.txt
echo "DONE."