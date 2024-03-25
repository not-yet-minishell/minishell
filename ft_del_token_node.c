#include "structure.h"

void ft_del_token_node(t_token *node)
{
	if (!node)
		return ;
	free(node->str);
	free(node);
}