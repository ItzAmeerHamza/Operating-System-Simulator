#!/bin/bash
############Read from file############
clear
figlet -t -k -c -c 'Score Board' | lolcat
echo
echo
filename='data.txt'
n=1
while read line; do
# reading each line
echo -e '\e[38:5:42m\t\t\t\t\t\t\t'$line'\n\e[39m' 

#echo "$line"
n=$((n+1))
done < $filename
echo -e "\033[1;34m Press ESC to go back"
read -s -n1  key

 case $key in
	 # caliing the files`s content
     $'\e') source menu.sh;;
 esac
