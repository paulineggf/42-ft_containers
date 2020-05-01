#!/bin/bash

dir=$PWD
bold=$(tput bold)
normal=$(tput sgr0)

declare -i totalCorrect
declare -i totaux
declare -i total
declare -i correct
declare -A tab

vectorSelect="1"
listSelect="2"
all="3"
exit="4"

# Set your absolute INCLUDES path directory below
includes="/home/pauline/CPP/ft_containers/includes"

while true; do
{
    totalCorrect=0
    totaux=0

    echo ${normal} "
    Do you want to test leaks memory? y/n"

    read leaks

    echo ${normal} "

    Enter the container number you want to correct:
            -1 Vector
            -2 List
            -3 All
            -4 Exit"

    read selection

    if [ "$selection" == "$exit" ]; then
        break ;
    fi

    declare -a vector=( "constructor"   "operator="     "begin"     "end"
                        "rbegin"        "rend"          "size"      "max_size"
                        "resize"        "capacity"      "empty"     "reserve"       
                        "operator[]"    "at"            "front"     "back"   
                        "assign"        "push_back"     "pop_back"  "insert"  
                        "erase"         "swap"          "clear"     "relational_operators"
                        "swap_overload" "bool")

    declare -a list=(   "constructor"   "operator="     "begin"     "end"
                        "rbegin"        "rend"          "empty"     "size"
                        "max_size"      "front"         "back"      "push_front"
                        "pop_front"     "push_back"     "pop_back"  "insert"
                        "erase"         "swap"          "resize"    "clear"
                        "splice"        "remove"        "remove_if" "unique"
                        "merge"         "sort"          "reverse"   "relational_operators"
                        "swap") 

    tab=()
    if [[ "$selection" == "$vectorSelect" || "$selection" == "$all" ]]; then
        tab[vector]+="${vector[@]}"
    fi
    if [[ "$selection" == "$listSelect" || "$selection" == "$all" ]]; then
        tab[list]+="${list[@]}"
    fi

    for subdir in ${!tab[@]}; do
        total=0
        correct=0
        echo -e "\033[1;34m\n | TESTS ${subdir^^} CONTAINER | \n "
        for val in ${tab[$subdir]}; do
            sed -i "s/ft::${subdir}/std::${subdir}/g" $dir/srcs/$subdir/$val/*.cpp
            cd $dir/srcs/$subdir/$val && clang++ -o cpptest -Wall -Wextra -Werror -g -std=c++98 -I $includes/* *.cpp;
            sed -i "s/std::${subdir}/ft::${subdir}/g" $dir/srcs/$subdir/$val/*.cpp
            cd $dir/srcs/$subdir/$val && clang++ -o mytest -Wall -Wextra -Werror -g -std=c++98 -I $includes/* *.cpp;
            if [ $leaks == "y" ] ; then
                valgrind ./mytest >&- 2> $dir/results/$subdir/$val/valgrind.file
            fi
            $dir/srcs/$subdir/$val/cpptest > $dir/results/$subdir/$val/cppresult.file;
            $dir/srcs/$subdir/$val/mytest > $dir/results/$subdir/$val/myresult.file;

            (echo -n ${normal} && printf '%-12s' $val) | head -c 18; echo -n :
            if cmp -s $dir/results/$subdir/$val/myresult.file $dir/results/$subdir/$val/cppresult.file \
            && test -s $dir/results/$subdir/$val/myresult.file; then
            {
                let $[ correct += 1, totalCorrect += 1 ]
                if [ $leaks == "y" ]; then
                {
                    echo -ne "\033[1;32m CORRECT  " ${normal}
                    grep "All heap blocks were freed -- no leaks are possible" $dir/results/$subdir/$val/valgrind.file
                    if [ $? -eq 1 ]; then
                    {
                        echo -ne "\033[1;31m LEAKS memory" ${normal}
                        grep "definitely lost:" $dir/results/$subdir/$val/valgrind.file
                    }
                    fi
                }
                else
                    echo -e "\033[1;32m CORRECT  " ${normal}
                fi
            }
            else
                echo -e "\033[1;31m WRONG!" ${normal}
            fi
            let $[ total += 1, totaux += 1 ]
        done
        if [ ${correct} != ${total} ]; then
            echo -e "\033[1;31m${correct}/${total} ${subdir} tests are correct "
        else
            echo -e "\033[1;32m${correct}/${total} ${subdir} tests are correct "
        fi
    done

    # TOTAUX

    if [ "$selection" == "$all" ]; then
    {
        echo -e "\033[1;34m\n | TOTAUX | \n "

        if [ ${totalCorrect} != ${totaux} ]; then
            echo -e "\033[1;31m${totalCorrect}/${totaux} tests are correct "
        else
            echo -e "\033[1;32m${totalCorrect}/${totaux} tests are correct "
        fi
    }
    fi
}
done

exit 0