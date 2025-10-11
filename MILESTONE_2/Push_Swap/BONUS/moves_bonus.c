#include "push_swap_bonus.h"

// Rotate
void	ft_rotate_bonus(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast_node_bonus(*stack);
	last->next = first;
}

void	ft_rr_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_rotate_bonus(stack_a);
	ft_rotate_bonus(stack_b);
}

// Reverse rotate
void	ft_reverse_rotate_bonus(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rrr_bonus(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate_bonus(stack_a);
	ft_reverse_rotate_bonus(stack_b);
}
