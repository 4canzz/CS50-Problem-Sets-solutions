#include <cs50.h>
#include <stdio.h>

int main(){
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
    return 0;
}

/*Problem to Solve
In a file called hello.c, in a folder called me, implement a program in C that prompts the user for their name and 
then says hello to that user. For instance, if the user’s name is Adele, your program should print hello, Adele\n!*/