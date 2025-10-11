#include "push_swap_bonus.h"

static int	ft_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

void	ft_checkervalids_bonus(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		if (ft_strlen(args[i]) < 1)
			ft_error_bonus(NULL, NULL);
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]) && !ft_sign(args[i][j])
				&& !ft_isspace(args[i][j]))
				ft_error_bonus(NULL, NULL);
			j++;
		}
		i++;
	}
}

int	ft_valid_digit_bonus(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (ft_sign(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_dups_bonus(t_stack *stack)
{
	t_node	*now;
	t_node	*dup;

	now = *stack->stack;
	while (now)
	{
		dup = now->next;
		while (dup)
		{
			if (dup->value == now->value)
				ft_error_bonus(NULL, stack);
			dup = dup->next;
		}
		now = now->next;
	}
}
