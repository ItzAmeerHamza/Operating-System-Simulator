clear
figlet -c -t -k 'Score Reduce Information' | lolcat
echo -e '\e[91m\n\n  => Dead-Fruits Scores:\e[39m'
echo -e '\e[38:5:42m\n\n\t\tIf the bomb 💣︎ will hit the man then score will decrease by 5 points.\n\n\t\tIf the bomb 👹 will hit the man then score will decrease by 10 points.\n\n\t\tIf the bomb 💀 will hit the man then score will decrease by 15 points.\n\n\t\tIf the bomb 👽 will hit the man then score will decrease by 20 points.\n\n\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> Press ESC to go back.\n\n\e[39m'

read -s -n1  key

 case $key in
	 # caliing the files`s content
     $'\e') source readme.sh s;;
     $'') source score_reduce.sh s;;
 esac