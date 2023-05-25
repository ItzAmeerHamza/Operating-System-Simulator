#! /bin/bash
echo -e '\e[38:5:42m\n\n\t\tEnter your name to start : '
read name
clear
manx_axis=$(( $RANDOM % 30 )) # variable to store the position of man in x axis.
Bombx_axis=$(( $RANDOM % 30 )) # variable to store the position of the Bomb in x axis.
fruity_axis=0 # fruit`s location on y axis
right_boundry=27 # at most boundary for man to go
left_boundry=1 # The minimum boundary for man to walk
lower_boundry=12 # Upper boundary for fruit
upper_boundry=1 # Lower boundary for fruit
fruitCount=-1 # Variable to count the fruits
bool_var=true
score_count=0
# The fruit and bomb array
SPRITEARRAY=( [0]='🍎' [1]='🍊' [2]='🍇' [3]='🍑' [4]='💣︎' [5]='👹' [6]=' 💀' [7]='👽' )
FRUITPOSX=(0 0 0 0 0 0 0 0)
FRUITPOSY=(0 0 0 0 0 0 0 0)
RANDTIME=(0 0 0 0 0 0 0 0)
timeCount=0
f1=0
f2=1
f3=2
f4=3
b1=4
b2=5
b3=6
b4=7
df1=true
df2=false
df3=false
df4=false
db1=false
db2=false
db3=false
db4=false
CATCHSPRITEARR=(0 0 0 0 0 0 0 0)
CATCHSCOREARR=(5 10 15 20 -5 -10 -15 -20)
score=0
count=0

isexist?(){ # method for verifying the redundant positions for fruit
  local value=$1
  shift # Shift all arguments to the left (original $1 gets lost)
  local array=("$@") # rebuild the array with rest of the arguments
  if [[ " ${array[@]} " =~ " ${value} " ]]
  then
    true
  else
    false
  fi
}

generatefruitfalltime(){ # method for generating random time for fruit to fall
  for ((i=0; i< ${#RANDTIME[@]}; i++))
  do
    fruitx_axis=$(( $RANDOM % 9 ))
    if isexist? $fruitx_axis, "${FRUITPOSX[@]}"
    then
      ((i--))

    else
      RANDTIME[$i]=$fruitx_axis
    fi
  done
  RANDTIME[0]=0;
}

generatefruitpositions(){ # method for generating fruit positions
  for (( i=0; i< ${#FRUITPOSX[@]}; i++ ))
  do
    fruitx_axis=$(( 1 + $RANDOM % 28 ))
    if isexist? $fruitx_axis, "${FRUITPOSX[@]}"
    then
      ((i--))
      continue
    else
      FRUITPOSX[$i]=$fruitx_axis
    fi
  done
}

isValidRight?(){ # method to check is it valid to right any more ?
  if [[ $1 -le right_boundry ]]
  then
    true
  else
    false
  fi
}

isValidLeft?(){ # method to check is it valid to left any more ?
  if [[ $1 -ge left_boundry ]]
  then
    true
  else
    false
  fi
}

printFruit(){ # method for printing fruit
  printf " " * 2
  printf "\t" * 4
  echo -n '*'
  for (( j = 0; j < 29; j++ ))
  do
    if [[ $j -eq ${FRUITPOSX[0]} ]] # printing the fruit
    then
      echo -n '🍑'
    else
      echo -n ' '
    fi
  done
  echo -n '*'
  echo
}

grid(){ # The grid for printing and game layout
  if [ $timeCount -ge 8 ]
  then
    timeCount=0
  fi
  
  if [[ $timeCount -eq ${RANDTIME[$f2]} ]]
  then
    df2=true
  fi
  if [[ $timeCount -eq ${RANDTIME[$f3]} ]]
  then
    df3=true
  fi
  if [[ $timeCount -eq ${RANDTIME[$f4]} ]]
  then
    df4=true
  fi
  if [[ $timeCount -eq ${RANDTIME[$b1]} ]]
  then
    db1=true
  fi
  if [[ $timeCount -eq ${RANDTIME[$b2]} ]]
  then
    db2=true
  fi
  if [[ $timeCount -eq ${RANDTIME[$b3]} ]]
  then
    db3=true
  fi
  if [[ $timeCount -eq ${RANDTIME[$b4]} ]]
  then
    db4=true
  fi
  printf " " * 2
  printf "\t" * 4
  for (( i = 0; i <= 31; i++ )) # The upper wall
  do
    echo -n '*'
  done
  echo
  #printFruit
  for (( i = 0; i <= 12; i++ ))
  do
    printf " " * 2
    printf "\t" * 4
    printf "*"
    for (( k = 0; k < 30; k++ ))
    do
      if [[ $i -eq ${FRUITPOSY[$f1]} ]] && [[ $k -eq ${FRUITPOSX[$f1]} ]] && [[ "$df1" = true ]]
      then
        echo -n ${SPRITEARRAY[$f1]}
        ((k++)) #skipping the iteration
        continue
      elif [[ $i -eq ${FRUITPOSY[$f2]} ]] && [[ $k -eq ${FRUITPOSX[$f2]} ]] && [[ "$df2" = true ]]
      then
        echo -n ${SPRITEARRAY[$f2]}
        ((k++))
        continue
      elif [[ $i -eq ${FRUITPOSY[$f3]} ]] && [[ $k -eq ${FRUITPOSX[$f3]} ]] && [[ "$df3" = true ]]
      then
        echo -n ${SPRITEARRAY[$f3]}
        ((k++))
        continue
      elif [[ $i -eq ${FRUITPOSY[$f4]} ]] && [[ $k -eq ${FRUITPOSX[$f4]} ]] && [[ "$df4" = true ]]
      then
        echo -n ${SPRITEARRAY[$f4]}
        ((k++))
        continue
      elif [[ $i -eq ${FRUITPOSY[$b1]} ]] && [[ $k -eq ${FRUITPOSX[$b1]} ]] && [[ "$db1" = true ]]
      then
        echo -n ${SPRITEARRAY[$b1]}
        ((k++))
        continue
      elif [[ $i -eq ${FRUITPOSY[$b2]} ]] && [[ $k -eq ${FRUITPOSX[$b2]} ]] && [[ "$db2" = true ]]
      then
        echo -n ${SPRITEARRAY[$b2]}
        ((k++))
        continue
      elif [[ $i -eq ${FRUITPOSY[$b3]} ]] && [[ $k -eq ${FRUITPOSX[$b3]} ]] && [[ "$db3" = true ]]
      then
        echo -n ${SPRITEARRAY[$b3]}
        ((k++))
        continue
      elif [[ $i -eq ${FRUITPOSY[$b4]} ]] && [[ $k -eq ${FRUITPOSX[$b4]} ]] && [[ "$db4" = true ]]
      then
        echo -n ${SPRITEARRAY[$b4]}
        ((k++))
        continue
      elif [[ $k -eq $manx_axis ]] && [[ $i -eq 12 ]]
      then
        echo -en "\033[33;5m🧍\033[0m" # The blinking man
        ((k++))
        continue
      else
        echo -n ' '
      fi
    done
      printf "*"
      echo
    #printFruit
  done
  echo
  printf " " * 2
  printf "\t" * 4
  for (( i = 0; i <= 31; i++ )) # The Lower wall
  do
    echo -n '*'
  done
  echo
  echo
  echo
}

resetfruitpos?(){
  if [[ $1 -ge lower_boundry ]]
  then
    true
  else
    false
  fi
}

generatefruitpositions
generatefruitfalltime

BEGIN=$(date +%s)

while true
do
  echo -e "\033[1;37m"
  NOW=$(date +%s)
  DIFF=$(($NOW - $BEGIN))
  MINS=$(($DIFF / 60))
  SECS=$(($DIFF % 60))
  HOURS=$(($DIFF / 3600))
  DAYS=$(($DIFF / 86400))
  printf " " * 2
  printf "\t" * 4
  printf "****"
  printf "%3d Time, %02d:%02d:%02d" $DAYS $HOURS $MINS $SECS
  printf " ****"
  echo
  if [ $MINS -ge 2 ]
  then
    echo
    figlet -c -t -k '**** Your Time Is Being Out ****' | lolcat
    break
  fi
    echo -e "\033[0m"
    grid
    for(( i=0; i< ${#SPRITEARRAY[@]}; i++))
    do
      if [[ ${FRUITPOSX[$i]} -eq  $manx_axis ]] && [[ ${FRUITPOSY[$i]} -eq 12 ]]
      then
        CATCHSPRITEARR[$i]=1 # set certain fruit to be catched
      fi
    done
    # the scoring criterion
    for((i=0; i< ${#SPRITEARRAY[@]}; i++))
    do
      if [[ ${CATCHSPRITEARR[$i]} -eq  1 ]] && [[ ${FRUITPOSY[$i]} -eq 12 ]] && [[ ${FRUITPOSX[$i]} -eq  $manx_axis ]]
      then
        score=$(( ${CATCHSCOREARR[$i]} + score ))
        CATCHSPRITEARR[$i]=0
        FRUITPOSY[$i]=0
        FRUITPOSX[$i]=$(( 1 + $RANDOM % 29 ))
      fi
    done
    echo -e "\033[1;37mYour Score : "$score
    echo -e "\033[0m"
    read -r -sn1 t
    case $t in
        A) 
    ;;
        B) 
    ;;
        C) # the right par
          if isValidRight? $manx_axis
          then
            ((manx_axis++))
          fi

          if resetfruitpos? "${FRUITPOSY[f1]}" && [ "$df1" = true ] # reset the fruit position
          then
            FRUITPOSY[$f1]=0
          elif [ "$df1" = true ]
          then
            ((FRUITPOSY[$f1]++))
          fi
          if resetfruitpos? "${FRUITPOSY[f2]}" && [ "$df2" = true ] # reset the fruit position
          then
            FRUITPOSY[$f2]=0
          elif [ "$df2" = true ]
          then
            ((FRUITPOSY[$f2]++))
          fi
          if resetfruitpos? "${FRUITPOSY[f3]}" && [ "$df3" = true ] # reset the fruit position
          then
            FRUITPOSY[$f3]=0
          elif [ "$df3" = true ]
          then
            ((FRUITPOSY[$f3]++))
          fi
          if resetfruitpos? "${FRUITPOSY[f4]}" && [ "$df4" = true ] # reset the fruit position
          then
            FRUITPOSY[$f4]=0
          elif [ "$df4" = true ]
          then
            ((FRUITPOSY[$f4]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b1]}" && [ "$db1" = true ] # reset the fruit position
          then
            FRUITPOSY[$b1]=0
          elif [ "$db1" = true ]
          then
            ((FRUITPOSY[$b1]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b2]}" && [ "$db2" = true ] # reset the fruit position
          then
            FRUITPOSY[$b2]=0
          elif [ "$db2" = true ]
          then
            ((FRUITPOSY[$b2]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b3]}" && [ "$db3" = true ] # reset the fruit position
          then
            FRUITPOSY[$b3]=0
          elif [ "$db3" = true ]
          then
            ((FRUITPOSY[$b3]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b4]}" && [ "$db4" = true ] # reset the fruit position
          then
            FRUITPOSY[$b4]=0
          elif [ "$db4" = true ]
          then
              ((FRUITPOSY[$b4]++))
          fi
          ((timeCount++))
          #clear
        ;;
        D) # the left part
          if isValidLeft? $manx_axis
          then
            ((manx_axis--))
          else
            continue
          fi

          if resetfruitpos? "${FRUITPOSY[f1]}" && [ "$df1" = true ] # reset the fruit position
          then
            FRUITPOSY[$f1]=0
          elif [ "$df1" = true ]
          then
            ((FRUITPOSY[$f1]++))
          fi
          if resetfruitpos? "${FRUITPOSY[f2]}" && [ "$df2" = true ] # reset the fruit position
          then
            FRUITPOSY[$f2]=0
          elif [ "$df2" = true ]
          then
            ((FRUITPOSY[$f2]++))
          fi
          if resetfruitpos? "${FRUITPOSY[f3]}" && [ "$df3" = true ] # reset the fruit position
          then
            FRUITPOSY[$f3]=0
          elif [ "$df3" = true ]
          then
            ((FRUITPOSY[$f3]++))
          fi
          if resetfruitpos? "${FRUITPOSY[f4]}" && [ "$df4" = true ] # reset the fruit position
          then
            FRUITPOSY[$f4]=0
          elif [ "$df4" = true ]
          then
            ((FRUITPOSY[$f4]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b1]}" && [ "$db1" = true ] # reset the fruit position
          then
            FRUITPOSY[$b1]=0
          elif [ "$db1" = true ]
          then
            ((FRUITPOSY[$b1]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b2]}" && [ "$db2" = true ] # reset the fruit position
          then
            FRUITPOSY[$b2]=0
          elif [ "$db2" = true ]
          then
            ((FRUITPOSY[$b2]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b3]}" && [ "$db3" = true ] # reset the fruit position
          then
            FRUITPOSY[$b3]=0
          elif [ "$db3" = true ]
          then
            ((FRUITPOSY[$b3]++))
          fi
          if resetfruitpos? "${FRUITPOSY[b4]}" && [ "$db4" = true ] # reset the fruit position
          then
            FRUITPOSY[$b4]=0
          elif [ "$db4" = true ]
          then
              ((FRUITPOSY[$b4]++))
          fi
          ((timeCount++))
          #clear
        ;;
    esac
done
echo "$name	| $score" >> data.txt
sleep 1
clear
source menu.sh
center() { # method to stabilize padding and spacing
  termwidth="$(tput cols)"
  padding="$(printf '%0.1s' ={1..500})"
  printf '%*.*s %s %*.*s\n' 0 "$(((termwidth-2-${#1})/2))" "$padding" "$1" 0 "$(((termwidth-1-${#1})/2))" "$padding"
}