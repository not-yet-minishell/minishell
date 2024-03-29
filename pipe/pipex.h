#ifndef PIPEX_H
# define PIPEX_H

# include "../parse/parse_env.h"
# include "../libft/libft.h"
# include "../execute/execute.h"
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_fd
{
	int		fds[2];
	int		pid;
	int		temp_fd;
}	t_fd;

typedef struct s_arg
{
	char	**env_path;
	char	**arv;
	int		hd_flag;
	int		arc;
	char	**envp;
}	t_arg;


void	start_command(t_list *node, t_fd *fd_info);
void	redirect(t_rd_node *node);
int	start_process(t_list *head);

#endif