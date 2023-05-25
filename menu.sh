#! /bin/bash
# Figlet inbuilt library to print animated objects and banners.
# lolcat inbuilt library to print colored gradient for objects.
# Toilet inbuilt library for printing matalic and other options.
# Box library to print boxed banner.
clear
figlet -c -t -k THE CATCH GAME | boxes -d santa -a hc -p h8 |  lolcat
figlet -c -t -k '**********************' | lolcat
toilet -t -k -f mono12 -F metal '     **********************'
echo -e '\e[25m'
#for i in {16..21} {21..16} ; do echo -en "\e[48;5;${i}m \e[0m" ; done ; echo
bold=$(tput rev)
normal=$(tput sgr0)

figlet -c -t -k 'Main  Menu' | lolcat
echo
echo
echo -e -n "\033[1;31m\t1.Read Me\t\t"
echo -e "\033[1;31m ${bold}(Press 1)${normal}"

echo -e -n "\033[1;32m\n\t2.Credits\t\t"
echo -e "\033[1;32m ${bold}(Press 2)${normal}"

echo -e -n "\033[1;33m\n\t3.Previous Best Scores\t"
echo -e  "\033[1;33m ${bold}(Press 3)${normal}"

echo -e -n "\033[1;35m\n\t4.Play Game\t${normal}\t"
echo -e  "\033[1;35m ${bold}(Press 4)${normal}\n"
read -p "        = " option
if [[ option -eq 1 ]]
then
	source readme.sh # caliing the files`s content
elif [[ option -eq 2 ]]
then
	source credits.sh # caliing the files`s content
elif [[ option -eq 3 ]]
then
	source best_scores.sh # caliing the files`s content
elif [[ option -eq 4 ]]
then
	source annimation.sh # caliing the files`s content
else
	source menu.sh
fi
