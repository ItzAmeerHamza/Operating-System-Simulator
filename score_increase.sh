clear
figlet -c -t -k 'Score Increase Information' | lolcat
echo -e '\e[91m\n\n  => Fruit Scores:\e[39m'
echo -e '\e[38:5:42m\n\n\t\tIf catched fruit is 🍎 then score will increase by 5 points.\n\n\t\tIf the catched fruit is 🍊 then score will increase by 10 points.\n\n\t\tIf catched fruit is 🍇 then score will increase by 15 points.\n\n\t\tIf catched fruit is 🍑 then score will increase by 20 points.\n\n\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> Press ESC to go back.\n\n\e[39m'

read -s -n1  key

 case $key in
	 # caliing the files`s content
     $'\e') source readme.sh s;;
     $'') source instructions.sh s;;
 esac