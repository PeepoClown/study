#!/bin/bash
gcc -Wall -Werror -Wextra main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=1 -o ./gnl_bonus_1
gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1 -o ./gnl_1
gcc -Wall -Werror -Wextra main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=7 -o ./gnl_bonus_7
gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=7 -o ./gnl_7
gcc -Wall -Werror -Wextra main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=32 -o ./gnl_bonus_32
gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=32 -o ./gnl_32
gcc -Wall -Werror -Wextra main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=64 -o ./gnl_bonus_64
gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=64 -o ./gnl_64
gcc -Wall -Werror -Wextra main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=100 -o ./gnl_bonus_100
gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=100 -o ./gnl_100
gcc -Wall -Werror -Wextra main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=1024 -o ./gnl_bonus_1024
gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1024 -o ./gnl_1024
gcc -Wall -Werror -Wextra main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=9999 -o ./gnl_bonus_9999
gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=9999 -o ./gnl_9999

rm -rf results/output.txt results/output_bonus.txt
./gnl_1 >> results/output.txt
./gnl_7 >> results/output.txt
./gnl_32 >> results/output.txt
./gnl_64 >> results/output.txt
./gnl_100 >> results/output.txt
./gnl_1024 >> results/output.txt
./gnl_9999 >> results/output.txt
./gnl_bonus_1 >> results/output_bonus.txt
./gnl_bonus_7 >> results/output_bonus.txt
./gnl_bonus_32 >> results/output_bonus.txt
./gnl_bonus_64 >> results/output_bonus.txt
./gnl_bonus_100 >> results/output_bonus.txt
./gnl_bonus_1024 >> results/output_bonus.txt
./gnl_bonus_9999 >> results/output_bonus.txt

rm -rf ./gnl_1 ./gnl_7 ./gnl_32 ./gnl_64 ./gnl_100 ./gnl_1024 ./gnl_9999
rm -rf ./gnl_bonus_1 ./gnl_bonus_7 ./gnl_bonus_32 ./gnl_bonus_64 ./gnl_bonus_100 ./gnl_bonus_1024 ./gnl_bonus_9999

rm -rf results/diff.txt results/diff_bonus.txt
echo -n "Result :"
if diff results/expected_output.txt results/output.txt > results/diff.txt ; then
  echo -e "\t\033[0;32m[OK]\033[0m"
else
  echo -e "\t\033[0;31m[KO]\033[0m"
fi

echo -n "Result Bonus :"
if diff results/expected_output_bonus.txt results/output_bonus.txt > results/diff_bonus.txt ; then
  echo -e "\t\033[0;32m[OK]\033[0m"
else
  echo -e "\t\033[0;31m[KO]\033[0m"
fi
