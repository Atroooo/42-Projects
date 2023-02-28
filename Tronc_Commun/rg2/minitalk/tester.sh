#!/bin/bash
# by Maplepy

yellow="\e[1;93m"
green="\e[32m"
bold="\e[1m"
reset="\e[0m"

echo -e "${green}
					 888b     d888 d8b          d8b 888             888 888
					 8888b   d8888 Y8P          Y8P 888             888 888
					 88888b.d88888                  888             888 888
					 888Y88888P888 888 88888b.  888 888888  8888b.  888 888  888
					 888 Y888P 888 888 888 \"88b 888 888        \"88b 888 888 .88P
					 888  Y8P  888 888 888  888 888 888    .d888888 888 888888K
					 888   \"   888 888 888  888 888 Y88b.  888  888 888 888 \"88b
					 888       888 888 888  888 888  \"Y888 \"Y888888 888 888  888
					 ${reset}
"

print_info() {
	# printf '\e[1;93m%*s' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
	echo -e "\n\t${yellow}------------------------${reset}"
	echo -e "\t${yellow}*${reset} ${bold}$1${reset}"
}

print_success() {
	echo -e "\n\t\e[4m${green} ${bold}$1${reset}"
}

# compile the server and client programs
print_info "Compiling the programs"
make re

print_info "Launching server with Valgrind..."
./server &

# Wait for the server to start up
sleep 1

# Store the server PID
server_pid=$!

function run_client_test() {
	pid=$1
	message=$2
	print_info "Running client test with PID ${yellow}$pid${reset}${bold} and message '${yellow}$message${reset}'"
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

# extremely_long_string=$( head -c 500000 /dev/urandom | tr -dc '[:alnum:]' | head -c 100000)
# run_client_test $! "$extremely_long_string"

print_info "Running client test with PID ${yellow}$pid${reset}${bold} and too many parameters"
./client $! foo bar

sleep 1

# clean up
print_info "Cleaning the files"
make fclean

print_success "Every test has been done successfully"
