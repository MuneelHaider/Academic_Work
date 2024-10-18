# Muneel Haider
# 21i-0640
# Assignment 1 - OS

filetodel=$1
trashpath="/home/muneelhaider/Desktop/OS/Ass_1/safe_rm_recycle/"

if [ ! -d "$trashpath" ]
then
    mkdir -p "$trashpath"

else
    echo "Directory '$trashpath' already exists."

fi

cp "$filetodel" "$trashpath"

rm $1