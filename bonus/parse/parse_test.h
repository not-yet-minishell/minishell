/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:11:27 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/08 12:46:07 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEST_H
# define PARSE_TEST_H
# include "../minishell.h"

void	print_node(t_token *node);
void	tree_inorder_print(t_tree *tree);
void	curr_list_print(t_list *list);
void	print_cmd(char *cmd);
void	print_rdnode(t_rd_node *rd_node);
void	print_pipenode(t_cmd_node *pipenode);
#endif