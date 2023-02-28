#!/bin/bash
# by Maplepy

echo -e "\ec"
echo -e "\e[32m
					 888b     d888 d8b          d8b 888             888 888
					 8888b   d8888 Y8P          Y8P 888             888 888
					 88888b.d88888                  888             888 888
					 888Y88888P888 888 88888b.  888 888888  8888b.  888 888  888
					 888 Y888P 888 888 888 \"88b 888 888        \"88b 888 888 .88P
					 888  Y8P  888 888 888  888 888 888    .d888888 888 888888K
					 888   \"   888 888 888  888 888 Y88b.  888  888 888 888 \"88b
					 888       888 888 888  888 888  \"Y888 \"Y888888 888 888  888

					 by Maplepy
					 \e[0m
"

print_info() {
	# printf '\e[1;93m%*s' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
	echo -e "\n\t\e[1;93m------------------------\e[0m"
	echo -e "\t\e[1;93m*\e[0m \e[1m$1\e[0m"
}

print_success() {
	echo -e "\n\t\e[4m\e[32m \e[1m$1\e[0m"
}

# compile the server and client programs
print_info "Compiling the programs"
make re

print_info "Launching server with Valgrind..."
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./server &

# Wait for the server to start up
sleep 1

function run_client_test() {
	pid=$1
	message=$2
	print_info "Running client test with PID \e[1;93m$pid\e[0m\e[1m and message '\e[1;93m$message\e[0m'"
	./client $pid "$message"
	sleep 1
}

run_client_test -1 "hello world"

run_client_test $! "hi"

run_client_test $! "👋🌍🌞👍🏽🍕"

long_string=$(head -c 50000 /dev/urandom | tr -dc '[:alnum:]' | head -c 10000)
run_client_test $! "$long_string"

very_long_string=$( head -c 250000 /dev/urandom | tr -dc '[:alnum:]' | head -c 50000)
run_client_test $! "$very_long_string"

extremely_long_string=$( head -c 500000 /dev/urandom | tr -dc '[:alnum:]' | head -c 100000)
run_client_test $! "$extremely_long_string"

print_info "Running client test with PID \e[1;93m$pid\e[0m\e[1m and too many parameters"
./client $! foo bar

print_info "Killing server..."
kill $!
sleep 1

# clean up
print_info "Cleaning the files"
make fclean

print_success "Every test has been done successfully"
