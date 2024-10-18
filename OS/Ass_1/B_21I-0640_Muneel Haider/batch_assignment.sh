# Muneel Haider
# 21i-0640
# Assignment 1 - OS

echo "/home/muneelhaider/Desktop/OS/Ass_1/B_21I-0640_Muneel Haider/assignment_data.txt"
echo

#Part 5
first_var="I love OS!"
echo $first_var >> second_bash.txt

# Part 6
filename="/home/muneelhaider/Desktop/OS/Ass_1/B_21I-0640_Muneel Haider/assignment_data.txt"
count=0
while IFS= read -r line
do
    if [[ $line == *80* ]]
    then
        echo $line >> second_bash.txt
    
    fi

done < "$filename"

# Part 7
second_var=0
for i in *
do
    if [ -f "$i" ]
    then
        second_var=$(($second_var + 1))

    fi
done

echo -n "Number of files in directory: " >> second_bash.txt
echo $second_var >> second_bash.txt