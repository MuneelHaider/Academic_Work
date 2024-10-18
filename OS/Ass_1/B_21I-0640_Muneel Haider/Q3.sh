# Muneel Haider
# 21i-0640
# Assignment 1 - Operating Systems

# I have made an extra file by the name "modifierDate.sh"
# It automatically generates a file "example.txt"
# which has a modified date of a year ago
# It can be used to test the 4th part of this Question.

# Directly run this script and a file shall be made in the current directory

numeric_to_rwx() {

    local numeric="$1"
    local result=""

    for ((i = 0; i < 3; i++))
    do
        digit="${numeric:i:1}"
    
        if ((digit & 4))
        then
    
            result+="r"
        else
    
            result+="-"
        fi
    
        if ((digit & 2))
        then
    
            result+="w"
        else
    
            result+="-"
        fi
    
        if ((digit & 1))
        then
    
            result+="x"
        else
    
            result+="-"
        fi
    done

    echo "$result"
}

touch third_2_bash.txt
touch third_1_bash.txt

while true
do

  echo
  echo "Select an option:"
  echo "1. View and update file permissions."
  echo "2. Search for a string in a file."
  echo "3. Copy N lines into new file."
  echo "4. Date modified check."
  echo "0. Press anything else to exit."
  read option

  echo

  case "$option" in

    1)
  
      echo
      echo "Enter filename:"
      read filename

      permissions_numeric=$(stat -c "%a" "$filename")
      permissions_rwx=$(numeric_to_rwx "$permissions_numeric")
  
      echo "Current permissions: $permissions_rwx"

      inverted_permissions=""
  
      for ((i = 0; i < ${#permissions_numeric}; i++))
      do
  
          digit="${permissions_numeric:i:1}"
          inverted_digit="$((7 - digit))"

          inverted_permissions+="$inverted_digit"
      done

      chmod "$inverted_permissions" "$filename"

      updated_permissions_numeric=$(stat -c "%a" "$filename")
      updated_permissions_rwx=$(numeric_to_rwx "$updated_permissions_numeric")
  
      echo "Updated permissions: $updated_permissions_rwx"
   
      echo
    ;;

    2)

      echo "Enter the filename:"
      read filename

      echo "Enter the string to search:"
      read search_string

      grep -E "$(echo "$search_string" | sed 's/\././g')" "$filename"

      echo
    ;;

    3)
     
      > third_1_bash.txt

      echo "Enter the value of N:"
      read N

      counter=1

      for file in *
      do
      
        if [ $((counter % 2)) -eq 0 ]
        then
        
          head -n "$N" "$file" >> third_1_bash.txt
        
        else
        
          tail -n "$N" "$file" >> third_1_bash.txt
        
        fi
        
        ((counter++))
      done

      echo
      
      ;;

    4)
      echo "Enter the filename:"
      read filename

      modified_date=$(stat -c '%Y' "$filename")
      current_date=$(date +%s)

      time_difference=$((current_date - modified_date))

      if [ "$time_difference" -gt 86400 ]
      then
      
        echo "The file was modified more than 24 hours ago."
        echo "Updated the modification date to current date."
        echo

        touch "$filename"
        echo "Updated the modification date to current date." >> third_2_bash.txt
      
      else
      
        echo "The file was modified within the last 24 hours."
        echo
        echo "No update required." >> third_2_bash.txt
      fi
      
    ;;
      
    *)
    
      break;

    ;;

  esac

done