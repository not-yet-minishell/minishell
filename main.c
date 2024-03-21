#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *str;

	while(1)
	{
		// '|', '(', ')', ' ' , '\t', '\n' 기준으로 자르기
		// | 는 다음거 있는지 볼것  * 바로 |가 있어야 ||임,
		//token - redirection,
		str = readline("examshell : ");
		add_history(str); 
		printf("%s\n",str);
	}
}