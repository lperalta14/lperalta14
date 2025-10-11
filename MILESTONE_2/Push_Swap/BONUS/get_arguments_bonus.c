#include "push_swap_bonus.h"

static t_node	*ft_new_node(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = num;
	new->index = -1;
	new->pos = -1;
	new->target = -1;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}
static void	ft_add_back_node(t_node **stack, t_node *new)
{
	t_node	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_getnode_bonus(t_stack *stack_a, char **split)
{
	int		j;
	long	num;
	t_node	*new_node;

	j = 0;
	while (split[j])
	{
		if (!ft_valid_digit_bonus(split[j]))
			ft_error_bonus(split, stack_a);
		num = ft_atolints(split[j]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error_bonus(split, stack_a);
		new_node = ft_new_node((int)num);
		if (!stack_a->stack)
			ft_error_bonus(split, stack_a);
		ft_add_back_node(stack_a->stack, new_node);
		stack_a->size++;
		j++;
	}
	ft_free_split_bonus(split);
}

void	ft_get_arguments_bonus(int argc, char **argv, t_stack *stack_a)
{
	char	**split;
	int		i;

	split = NULL;
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			ft_error_bonus(NULL, stack_a);
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_error_bonus(split, stack_a);
		ft_getnode_bonus(stack_a, split);
		i++;
	}
}
