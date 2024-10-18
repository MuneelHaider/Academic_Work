# Muneel Haider
# 21i-0640
# Assignment 1 - OS

filetodel=$1
trashpath="/home/muneelhaider/Desktop/OS/Ass_1/B_21I-0640_Muneel Haider/safe_rm_recycle/"

if [ ! -d "$trashpath" ]
then
    mkdir -p "$trashpath"

else
    echo "Directory '$trashpath' already exists."

fi

cp "$filetodel" "$trashpath"

rm $1