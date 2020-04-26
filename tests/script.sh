#!/bin/bash

dir=$PWD
bold=$(tput bold)
normal=$(tput sgr0)
totalCorrect=0
totalWrong=0

vectorSelect="1"
listSelect="2"
all="3"
exit="4"

while true; do
{
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

    # VECTOR

    subdir=vector
    correct=0
    wrong=0

    declare -a vector=( "constructor"   "operator="     "begin"     "end"
                        "rbegin"        "rend"          "size"      "max_size"
                        "resize"        "capacity"      "empty"     "reserve"       
                        "operator[]"    "at"            "front"     "back"   
                        "assign"        "push_back"     "pop_back"  "insert"  
                        "erase"         "swap"          "clear"     "relational_operators")

    if [[ "$selection" == "$vectorSelect" || "$selection" == "$all" ]]; then
    {
        echo -e "\033[1;34m\n | TESTS VECTOR CONTAINER | \n "
        for val in ${vector[@]}; do
            cd $dir/srcs/mytest/$subdir/$val && clang++ -Wall -Wextra -Werror -g -std=c++98 *.cpp;
            cd $dir/srcs/cpptest/$subdir/$val && clang++ -Wall -Wextra -Werror -g -std=c++98 *.cpp;
            cd $dir;
            $dir/srcs/mytest/$subdir/$val/a.out > $dir/results/$subdir/$val/myresult.file;
            $dir/srcs/cpptest/$subdir/$val/a.out > $dir/results/$subdir/$val/cppresult.file;
            cd $dir/srcs/mytest/$subdir/$val/ && rm a.out;
            cd $dir/srcs/cpptest/$subdir/$val/ && rm a.out;

            echo -n ${normal} && printf '%-12s' $val:
            if diff -q $dir/results/$subdir/$val/myresult.file $dir/results/$subdir/$val/cppresult.file; then
            {
                echo -e "\033[1;32m CORRECT"
                let $[ correct += 1 ]
                let $[ totalCorrect += 1 ]
            }
            else
            {
                echo -e "\033[1;31m WRONG!"
                let $[ wrong += 1 ]
                let $[ totalWrong += 1 ]
            }
            fi
        done
        total=$((wrong + correct))
        if [ ${correct} != ${total} ]; then
            echo -e "\033[1;31m${correct}/${total} tests are correct "
        else
            echo -e "\033[1;32m${correct}/${total} tests are correct "
        fi
    }
    fi

    # LIST

    subdir=list
    correct=0
    wrong=0

    declare -a list=(   "constructor"   "operator="     "begin"     "end"
                        "rbegin"        "rend"          "empty"     "size"
                        "max_size"      "front"         "back"      "push_front"
                        "pop_front"     "push_back"     "pop_back"  "insert"
                        "erase"         "swap"          "resize"    "clear"
                        "splice"        "remove"        "remove_if" "unique"
                        "merge"         "sort"          "reverse"   "relational_operators"
                        "swap") 

    if [[ "$selection" == "$listSelect" || "$selection" == "$all" ]]; then
    {
        echo -e "\033[1;34m\n | TESTS LIST CONTAINER | \n "
        for val in ${vector[@]}; do
            cd $dir/srcs/mytest/$subdir/$val && clang++ -Wall -Wextra -Werror -g -std=c++98 *.cpp;
            cd $dir/srcs/cpptest/$subdir/$val && clang++ -Wall -Wextra -Werror -g -std=c++98 *.cpp;
            cd $dir;
            $dir/srcs/mytest/$subdir/$val/a.out > $dir/results/$subdir/$val/myresult.file;
            $dir/srcs/cpptest/$subdir/$val/a.out > $dir/results/$subdir/$val/cppresult.file;
            cd $dir/srcs/mytest/$subdir/$val/ && rm a.out;
            cd $dir/srcs/cpptest/$subdir/$val/ && rm a.out;

            echo -n ${normal} && printf '%-12s' $val:
            if diff -q $dir/results/$subdir/$val/myresult.file $dir/results/$subdir/$val/cppresult.file; then
            {
                echo -e "\033[1;32m CORRECT"
                let $[ correct += 1 ]
                let $[ totalCorrect += 1 ]
            }
            else
            {
                echo -e "\033[1;31m WRONG!"
                let $[ wrong += 1 ]
                let $[ totalWrong += 1 ]
            }
            fi
        done
        total=$((wrong + correct))
        if [ ${correct} != ${total} ]; then
            echo -e "\033[1;31m${correct}/${total} tests are correct "
        else
            echo -e "\033[1;32m${correct}/${total} tests are correct "
        fi
    }
    fi


    # TOTAUX

    echo -e "\033[1;34m\n | TOTAUX | \n "

    total=$((totalWrong + totalCorrect))
    if [ ${totalCorrect} != ${total} ]; then
        echo -e "\033[1;31m${totalCorrect}/${total} tests are correct "
    else
        echo -e "\033[1;32m${totalCorrect}/${total} tests are correct "
    fi
}
done

exit 0