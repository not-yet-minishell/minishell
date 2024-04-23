/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:11:48 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 17:13:24 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	heredoc_tree(t_tree *tree, t_list *envp, \
	int *heredoc_count, int *signal_flag);

int	herdoc_tree_init(t_tree *tree, t_list *envp)
{
	int	heredoc_count;
	int	signal_flag;

	heredoc_count = 0;
	signal_flag = 0;
	heredoc_tree(tree,envp,&heredoc_count, &signal_flag);
	if (signal_flag == SIGINT)
		((t_builtin *)envp->content)->exit_num = 1;
	return signal_flag;
}

static void	heredoc_tree(t_tree *tree, t_list *envp, \
	int *heredoc_count, int *signal_flag)
{
	char *filename;
	
	if ((*signal_flag) == SIGINT)
		return ;
	if (tree->left)
		heredoc_tree(tree->left, envp, heredoc_count, signal_flag);
	if (tree->token && tree->token->type == REDIRECT_HEREDOC)
	{
		filename = heredoc(tree->redirect->filename, heredoc_count, envp, signal_flag);
		tree->token->type = REDIRECT_IN;
		free(tree->redirect->filename);
		tree->redirect->filename = filename;
		(*heredoc_count)++;
	}
	if (tree->right)
		heredoc_tree(tree->right, envp, heredoc_count, signal_flag);
}