#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *str;

	while(1){
	str = readline("examshell : ");
	printf("%s\n",str);
	}
}