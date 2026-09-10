/***************************************************************************
* Author: Matthew Vang
* Created: September 8th, 2026
* COMPSCI537-001
* Homework 1
************************************************************************** */

/*
 * A non-interactive shell.
 *
 * This shell executes exactly ONE command using fork() and execvp(),
 * waits for the command to complete, and then exits.
 *
 * Usage:
 *   ./myshell -c "command"
 *
 * Example:
 *   ./myshell -c "./myhead input.txt"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64

/* ------------------------------------------------------------
 * Parses a command string into an argument array suitable for execvp().
 * Input: "./myhead file.txt"
 * Output: args = {"./myhead", "file.txt", NULL}
 * ------------------------------------------------------------ */
void parse_command(char *command, char *args[]) {
    // Tokenize the command string by whitespace.
    //       Populate the args[] array.
    //       args[] must be NULL-terminated.
    char *p1 = command;
    int i = 0;
    while(*p1 != '\0') { 
        args[i] = p1; // save first char of arg
        while(*p1 != '\0' && *p1 != ' ') { // find end of arg
            p1++;
        }

        if(*p1 == ' ') {
            *p1 = '\0';
            p1++;
        }
        i++;
    }
    args[i] = NULL;
}

/* ------------------------------------------------------------
 * Executes a command using fork(), execvp(), and wait().
 * The command corresponds to another executable program: mycat, myhead, or myuniq
 * ------------------------------------------------------------ */
void execute_command(char *args[]) {
    //       Create a child process.
    //       In the child, run another process (other executable program).
    //       In the parent, wait for the child to finish.
    //       Handle errors appropriately.
    pid_t pid = fork();
    if(pid == -1) {
        perror("fork failed");
        return;
    } 

    if(pid == 0) { // child
        execvp(args[0], args);
        
        perror("execvp failed");
        exit(1);
    } 
    
    else { // parent 
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "-c") != 0) {
        fprintf(stderr, "Usage: %s -c \"command\"\n", argv[0]);
        return 1;
    }

    char *args[MAX_ARGS];

    parse_command(argv[2], args);
    execute_command(args);

    return 0;
}
