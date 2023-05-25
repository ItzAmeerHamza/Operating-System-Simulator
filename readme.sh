clear
figlet -t -k -c 'Read   Me' | lolcat
echo
echo
echo -e "\033[1;34m\t1.Instructions\t\t\t\t(Press 1)\n"
echo -e "\033[1;34m\t2.Score Increasing Information\t\t(Press 2)\n"
echo -e "\033[1;34m\t3.Score Reducing Information.\t\t(Press 3)\n"
echo -e "\033[1;34m\t4.Back.\t\t\t\t\t(Press Esc)\n"
echo -n "        = "
read -s -n1  key

 case $key in
	 # caliing the files`s content
     $'\e') source menu.sh s;;
     $'1')  source instructions.sh ;;
     $'2') source score_increase.sh ;;
     $'3') source score_reduce.sh ;;
 esac
