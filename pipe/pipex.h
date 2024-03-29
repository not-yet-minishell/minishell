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

char	**make_path_array(char **env);
int		*pipe_init(void);
void	start_pipe(t_arg *arg_info, t_fd *fd_info);
void	exec_cmd(int *fds, char *av[], char **path, int count);
int		check_access(char *command, char **argument, \
					int idx, t_arg *arg_info);
void	open_outfile(char *av[], int ac);
void	open_infile(char *av[]);

void	cmd_exec(t_arg *arg_info, t_fd *fd_info);
t_arg	*init_arg(char **path, char **av, int ac, char **env);
t_fd	*init_fd(void);
void	which_execve(t_arg *arg_info, char *arg, int fork_count);
char	**parser(char *command);
char	**make_tr(char *cmd);
char	**make_awk(char *cmd);
char	**make_sed(char *cmd);
void	error_handler(char *filename, char *msg, int errnum);
void	heredoc(t_arg *arg_info, t_fd *fd_info);
void	open_heredoc(t_fd *fd_info);
void	start_read(t_arg *arg_info, t_fd *fd_info);
char	*check_bs(char	*arg);
void	exit_process(t_fd	*fd_info);
char	*make_limiter(char *lim);


#endif