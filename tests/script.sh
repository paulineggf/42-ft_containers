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
stackSelect="3"
mapSelect="4"
queueSelect="5"
all="6"
exit="7"

# Set your absolute INCLUDES path directory below
includes="/home/pauline/CPP/ft_containers/includes"

while true; do
{
    totalCorrect=0
    totaux=0

    echo ${normal} "

    Enter the container number you want to correct:
            -1 Vector
            -2 List
            -3 Stack
            -4 Map
            -5 Queue
            -6 All
            -7 Exit"

    read selection

    if [ "$selection" == "$exit" ]; then
        break ;
    fi

    echo ${normal} "
    Do you want to test memory leaks? y/n"

    read leaks

    declare -a vector=( "constructor"   "operator="     "begin"     "end"
                        "rbegin"        "rend"          "size"      "max_size"
                        "resize"        "capacity"      "empty"     "reserve"       
                        "operator[]"    "at"            "front"     "back"   
                        "assign"        "push_back"     "pop_back"  "insert"  
                        "erase"         "swap"          "clear"     "relational_operators"
                        "swap_overload" "iterator"      "const_iterator"
                        "reverse_iterator" "const_reverse_iterator")

    declare -a list=(   "constructor"   "assign"        "push_back" "clear"
                        "iterator"      "insert"        "size"      "pop_back"
                        "back"          "empty"         "pop_front" "front"
                        "max_size"      "resize"        "erase"     "rbegin"
                        "rend"          "push_front"    "swap"      "splice"
                        "remove"        "remove_if"     "sort"      "unique"
                        "merge"         "reverse"       "relational_operators"
                        "swap_overload" "operator=")

    declare -a stack=(  "constructor"   "size"          "pop"       "push"
                        "top"           "empty"         "relational_operators")                        

    declare -a map=(    "constructor"   "value_comp"    "begin"     "empty"
                        "erase"         "find"          "size"      "max_size"
                        "insert"        "swap"          "clear"     "count"
                        "lower_bound"   "upper_bound"   "equal_range")

    declare -a queue=(  "constructor"   "back"          "empty"     "front"
                        "pop"           "push"          "size"      "relational_operators")

    tab=()
    if [[ "$selection" == "$vectorSelect" || "$selection" == "$all" ]]; then
        tab[vector]+="${vector[@]}"
    fi
    if [[ "$selection" == "$listSelect" || "$selection" == "$all" ]]; then
        tab[list]+="${list[@]}"
    fi
    if [[ "$selection" == "$stackSelect" || "$selection" == "$all" ]]; then
        tab[stack]+="${stack[@]}"
    fi
    if [[ "$selection" == "$mapSelect" || "$selection" == "$all" ]]; then
        tab[map]+="${map[@]}"
    fi
    if [[ "$selection" == "$queueSelect" || "$selection" == "$all" ]]; then
        tab[queue]+="${queue[@]}"
    fi

    for subdir in ${!tab[@]}; do
        total=0
        correct=0
        echo -e "\033[1;34m\n | TESTS ${subdir^^} CONTAINER | \n "
        for val in ${tab[$subdir]}; do
            sed -i "s/ft::${subdir}/std::${subdir}/g" $dir/srcs/$subdir/$val/*.cpp
            sed -i "s/ft::reverse_iterator/std::reverse_iterator/g" $dir/srcs/$subdir/$val/*.cpp
            sed -i "s/ft::pair/std::pair/g" $dir/srcs/$subdir/$val/*.cpp
            cd $dir/srcs/$subdir/$val && clang++ -o cpptest -Wall -Wextra -Werror -g -std=c++98 -pedantic -I $includes/$subdir/ ${val}.cpp;
            sed -i "s/std::${subdir}/ft::${subdir}/g" $dir/srcs/$subdir/$val/*.cpp
            sed -i "s/std::reverse_iterator/ft::reverse_iterator/g" $dir/srcs/$subdir/$val/*.cpp
            sed -i "s/std::pair/ft::pair/g" $dir/srcs/$subdir/$val/*.cpp
            cd $dir/srcs/$subdir/$val && clang++ -o mytest -Wall -Wextra -Werror -g -std=c++98 -pedantic -I $includes/$subdir/ ${val}.cpp;
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