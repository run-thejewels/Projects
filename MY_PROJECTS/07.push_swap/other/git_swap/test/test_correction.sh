#!/bin/sh -x

if [ ! -f ./push_swap ];
then
	make

elif [ "$1" = "big1" ];
then
	printf "\033[34;1mWhat is happening with a lot of parameters?\033[0m\n"
	echo './push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"`'
	./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"`

elif [ "$1" = "big2" ];
then
	printf "\033[34;1mWhat is happening with even more parameters?\033[0m\n"
	echo './push_swap `ruby -e "puts (-5000..5000).to_a.reverse.insert(rand(8000) + 1000, 10001).join(' ')"`'
	./push_swap `ruby -e "puts (-5000..5000).to_a.reverse.insert(rand(8000) + 1000, 10001).join(' ')"`

elif [ "$1" = "big3" ];
then
	printf "\033[34;1mWith 2000 arguments from 0 to 1999 random\033[0m\n"
	echo './push_swap `python randomnb.py`'
	./push_swap `python test/randomnb.py`

elif [ "$1" = "bonus" ];
then
	printf "\033[34;1mBonus: display moves number\033[0m\n"
	echo './push_swap -v 5 6 2 9 1 3'
	./push_swap -v 5 6 2 9 1 3

	printf "\033[34;1mBonus: display in color\033[0m\n"
	echo './push_swap -c 5 6 2 9 1 3'
	./push_swap -c 5 6 2 9 1 3

else
	printf "\033[34;1mShould return 0 (or nothing)\033[0m\n"
	echo './push_swap 4 5 12 25 89'
	./push_swap 4 5 12 25 89

	printf "\n\033[34;1mShould be done in 2 operations (okay for 3)\033[0m\n"
	echo './push_swap 3 2 1'
	./push_swap 3 2 1

	printf "\n\033[34;1mShould be done in only one swap\033[0m\n"
	echo './push_swap 2 1 3'
	./push_swap 2 1 3

	printf "\n\033[34;1mShould be done in less than 8 operations (5 is good)\033[0m\n"
	echo './push_swap 4 6 10 12 19 25 36 29'
	./push_swap 4 6 10 12 19 25 36 29

	printf "\n\033[34;1mShould be done between 5 and 20 operations\033[0m\n"
	echo './push_swap 100 1000 10 100000 10000'
	./push_swap 100 1000 10 100000 10000

	printf "\n\033[34;1mShould be done between 5 and 20 operations too\033[0m\n"
	echo './push_swap 12 25 5 154 89'
	./push_swap 12 25 5 154 89

	printf "\n\033[34;1mShould return nothing (or empty line, it's okay)\033[0m\n"
	echo './push_swap'
	./push_swap

	printf "\n\033[34;1mShould return Error (non digit arguments)\033[0m\n"
	echo './push_swap 56 76 sig 67 62'
	./push_swap 56 76 sig 67 62
	echo './push_swap sig 56 121 45 5'
	./push_swap sig 56 121 45 5
	echo './push_swap s'
	./push_swap s

	printf "\n\033[34;1mShould return Error (double)\033[0m\n"
	echo './push_swap 15 15'
	./push_swap 15 15
	echo './push_swap 45 12 57 52 33 33'
	./push_swap 45 12 57 52 33 33
	echo './push_swap 45 12 57 52 33 45'
	./push_swap 45 12 57 52 33 45

	printf "\n\033[34;1mShould return Error (bigger than integer)\033[0m\n"
	echo './push_swap 2147483648'
	./push_swap 2147483648
	echo './push_swap 29999999999'
	./push_swap 29999999999
	echo './push_swap -2147483649'
	./push_swap -2147483649
	echo './push_swap -29999999999'
	./push_swap -29999999999

	printf "\n\033[34;1mTest the limit int, should work\033[0m\n"
	echo './push_swap 2147483647 1'
	./push_swap 2147483647 1
	echo './push_swap -2147483648 1'
	./push_swap -2147483648 1

	printf "\n\033[34;1mShould return no operations\033[0m\n"
	echo './push_swap 2'
	./push_swap 2

	printf "\n\033[34;1mCheck by yourself if the operations solve this : 5 6 2 9 1 3\033[0m\n"
	echo './push_swap 5 6 2 9 1 3'
	./push_swap 5 6 2 9 1 3

	printf "\n\033[34;1mTests with negatives and positives\033[0m\n"
	echo './push_swap 2 -5 26 -7888 -998 564 12'
	./push_swap 2 -5 26 -7888 -998 564 12

	printf "\n\033[34;1mTests with only negatives\033[0m\n"
	echo './push_swap -2 -5 -26 -7888 -998 -564 -12'
	./push_swap -2 -5 -26 -7888 -998 -564 -12
fi
