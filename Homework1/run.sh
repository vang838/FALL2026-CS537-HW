#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

run_test () {
    test_num="$1"
    command="$2"
    expected_cmd="$3"

    echo -e "\n=============================="
    echo "TEST $test_num: ./myshell -c \"$command\""
    echo "=============================="

    ./myshell -c "$command" > out.txt
    eval "$expected_cmd" > expected.txt

    if diff out.txt expected.txt; then
        echo -e "${GREEN}PASS${RESET}"
    else
        echo -e "${RED}FAIL${RESET}"
    fi
}

# -----------------------------
# myhead tests
# -----------------------------

run_test 1 "./myhead infiles/swan.txt" \
    "head -n 6 infiles/swan.txt"

run_test 2 "./myhead infiles/summer.txt" \
    "head -n 6 infiles/summer.txt"

# -----------------------------
# myuniq tests
# -----------------------------

run_test 3 "./myuniq infiles/dup.txt" \
    "uniq infiles/dup.txt"

run_test 4 "./myuniq infiles/summer.txt" \
    "uniq infiles/summer.txt"

# -----------------------------
# cleanup (easy to remove later)
# -----------------------------
rm -f out.txt expected.txt
