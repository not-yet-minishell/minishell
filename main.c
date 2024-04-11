/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/09 18:33:48 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "minishell.h"

void	do_sigterm(void);
void	set_terminal_print_off(void);
void	do_sigint(int signum);

void	leaks(void)
{
	system("leaks minishell");
}

void *Signal(int signum, void *handler)
{
	struct sigaction action, old_action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	if (sigaction(signum, &action, &old_action) < 0)
		ft_printf(1,"Signal error");
	return old_action.sa_handler;
}
// void signal_handle()
// {
// 	struct sigaction	sa1;
// 	struct sigaction	sa2;

// 	sigemptyset(&sa1.sa_mask);
// 	sa1.sa_flags = 0;
// 	sa1.sa_handler = do_sigint;
// 	sigemptyset(&sa2.sa_mask);
// 	sa2.sa_flags = 0;
// 	sa2.sa_handler = SIG_IGN;
// 	sigaction(SIGINT,&sa1,0); // 에러 예외 처리
// 	sigaction(SIGQUIT,&sa2,0); // 에러 예외처리
// 	set_terminal_print_off();
// }

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_list	*head;
	t_tree	*tree;

	(void)argc;
	(void)argv;
	(void)envp;

	//signal_handle();
	Signal(SIGINT, do_sigint);
	Signal(SIGQUIT,SIG_IGN);
	set_terminal_print_off();
	while (1)
	{
		line = readline("minishell: ");
		if (line == NULL)
			break;
		// line nuull 체크해서 exit 코드
		// ctrl + c 눌렀을때 프로그램 안꺼지고 다음 프롬프트
		// ctrl + \ 했을때 아무 동작도 안하게! 자식프로세스는 꺼지고 , 부모프로세스는 아무동작도 안하게
		// heredoc도 조금 다르다!
		add_history(line);
		head = tokenizer(line);
		if (!head)
		{
			free(line);
			continue;
		}
		tree = parse_tree(&head);
		//leaks();
		inorder_cmd_tree(tree);
		clear_tree(tree);
		free(line);
	}
	do_sigterm();
}

void	do_sigint(int signum)
// 기본 minishell 상태에서 ctrl+c입력을 받았을때 실행되는 함수
{
	(void)signum;
	ft_putstr_fd("\n", 2); // 줄바꿈 출력
	rl_on_new_line(); // 커서가 다음줄로 옮겨간것을 readline에 적용
	rl_replace_line("", 0); // 현재 버퍼를 비워줌
	rl_redisplay(); // readline 메시지를 다시 출력
	//change_exit_status(1); // 저장중이던 최근 반환값을 1로 수정해줌 (ctrl+c 시그널을 작동할때 1의 반환값을 가져야함)
}

void	set_terminal_print_off(void)
// 터미널에 ^C, ^\등의 시그널표식을 출력하도록 설정
{
	struct termios	term; // 터미널 설정이 담겨있는 termios 구조체

	tcgetattr(1, &term); // 현재 터미널의 설정을 term에 가져옴
	term.c_lflag &= ~(ECHOCTL); // 시그널표식 출력이 false 라면 true로 변경
	tcsetattr(1, 0, &term);  // 변경한 term 설정을 현재 터미널에 적용
}

void	do_sigterm(void)
// ctrl+d를 눌렀을때 작동
{
	ft_putstr_fd("\033[1A", 2); // 현재 커서의 위치를 한칸 위로 올려줌 
	ft_putstr_fd("\033[11C", 2); // 현재 커서의 위치를 12번째칸으로 이동
	ft_putstr_fd("exit\n", 2); // exit를 출력
}