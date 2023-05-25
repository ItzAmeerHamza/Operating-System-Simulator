clear
figlet -t -k -c -c '      Instructions' | lolcat
echo -e '\e[38:5:42m\n\n\t\t-> On every attemp you are given only one life.\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> There is a blinking man in the bottom arear of the grid.\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> You can move the man left and right by pressing the respective arrow keys on your key board.\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> Fruits of diffrent ctegories will apears at the top of the grid moving downwards.\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> There are four diffrent kinds of fruits moving downwards and apprearing on diffrent time.\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> Every fruit has it`s own score.This means that hitting any fruit will give you, benifit diffrently.\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> There are diffrent kind of bombs appearing on the top of the screen.\n\n\e[39m'
echo -e '\e[38:5:42m\n\n\t\t-> Press ESC to go back.\n\n\e[39m'

read -s -n1  key

 case $key in
	 # caliing the files`s content
     $'\e') source readme.sh s;;
     $'') source instructions.sh s;;
 esac