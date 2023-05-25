#! /bin/bash
manx_axis=$(( $RANDOM % 30 )) # variable to store the position of man in x axis.
Bombx_axis=$(( $RANDOM % 30 )) # variable to store the position of the Bomb in x axis.
fruity_axis=0 # fruit`s location on y axis
echo 'Fruit location : ' $fruitx_axis
right_boundry=27 # at most boundary for man to go
left_boundry=1 # The minimum boundary for man to walk
lower_boundry=9 # Upper boundary for fruit
upper_boundry=1 # Lower boundary for fruit
fruitCount=0 # Variable to count the fruits
# The fruit and bomb array
SPRITEARRAY=( [0]='🍎' [1]='🍊' [2]='🍇' [3]='🍑' [4]='💣︎' [5]='👹' [6]=' 💀' [7]='👽' )
FRUITPOS=(0 0 0 0 0 0 0 0)

RANDTIME=(0 0 0 0 0 0 0 0)

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
    if isexist? $fruitx_axis, "${FRUITPOS[@]}"
    then
      ((i--))

    else
      RANDTIME[$i]=$fruitx_axis
    fi
  done
  RANDTIME[0]=0;
}

generatefruitpositions(){ # method for generating fruit positions
  for (( i=0; i< ${#FRUITPOS[@]}; i++ ))
  do
    fruitx_axis=$(( 1 + $RANDOM % 29 ))
    if isexist? $fruitx_axis, "${FRUITPOS[@]}"
    then
      ((i--))
      continue
    else
      FRUITPOS[$i]=$fruitx_axis
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
    if [[ $j -eq ${FRUITPOS[0]} ]] # printing the fruit
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
  printf " " * 2
  printf "\t" * 4
  for (( i = 0; i <= 31; i++ )) # The upper wall
  do
    echo -n '*'
  done
  echo
  #printFruit
  for (( i = 0; i < 10; i++ ))
  do
    if [[ $i -eq ${RANDTIME[$i]} ]]
    then
      printFruit
    else
      printf "\t" * 4
      echo -n '*'
      for (( k = 0; k < 30; k++ ))
      do
        echo -n ' '
      done
      echo -en '\033[1m*'
      echo
    fi
    #printFruit
  done
  printf " " * 2
  printf "\t" * 4
  printf '*'
  for (( i = 0; i < 29; i++ ))
  do
    if [[ $i -eq $manx_axis ]]
    then
      echo -en "\033[33;5m🧍\033[0m" # The blinking man
    else
      echo -n ' '
    fi
  done
  printf '*'
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
echo 'Fruits : '${FRUITPOS[*]}
echo 'time : '${RANDTIME[*]}
while true
do
    grid
    echo '$fruity_axis : '$fruity_axis
    if resetfruitpos? $fruity_axis # reset the fruit position
    then
      fruity_axis=0
    else
      ((fruity_axis++))
    fi
    read -r -sn1 t
    case $t in
        A) 
    ;;
        B) 
    ;;
        C) # the right par
          if isValidRight? $manx_axis
          then
            echo $((manx_axis++))
          else
            continue
          fi
          #clear
        ;;
        D) # the left part
          if isValidLeft? $manx_axis
          then
            echo $((manx_axis--))
          else
            continue
          fi
          #clear
        ;;
    esac
done

center() { # method to stabilize padding and spacing
  termwidth="$(tput cols)"
  padding="$(printf '%0.1s' ={1..500})"
  printf '%*.*s %s %*.*s\n' 0 "$(((termwidth-2-${#1})/2))" "$padding" "$1" 0 "$(((termwidth-1-${#1})/2))" "$padding"
}