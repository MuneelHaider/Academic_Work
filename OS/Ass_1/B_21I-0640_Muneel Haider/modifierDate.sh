# Muneel Haider
# 21i-0640
# Assignment 1 - Operating Systems

# EXTRA FILE

file_to_modify="example.txt"

current_date=$(stat -c %y "$file_to_modify")

new_date=$(date -d "$current_date - 1 year" +"%Y%m%d%H%M.%S")

touch -t "$new_date" "$file_to_modify"

ls -l "$file_to_modify"
