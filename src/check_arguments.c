/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:32:44 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/11 10:59:39 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	ft_isrepeated(char **args, int pos, int num)
{
	int	count;

	count = 0;
	while (args[count] && count < pos)
	{
		if (ft_atoi(args[count]) == num)
			return (false);
		count++;
	}
	return (true);
}

static bool	ft_isnumber(char *arg)
{
	int	count;

	count = 0;
	if (arg[count] == '-' || arg[count] == '+')
		count++;
	while (arg[count])
	{
		if (!ft_isdigit(arg[count]))
			return (false);
		count++;
	}
	return (true);
}

static bool	ft_checklen(char *str)
{
	long int	num;
	int			count;
	int			sign_num;

	count = 0;
	sign_num = 1;
	num = 0;
	while (str[count] == ' ' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\t' || str[count] == '\v')
		count++;
	if (str[count] == '-')
		sign_num *= -1;
	if (str[count] == '+' || str[count] == '-')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = (str[count] - 48) + (num * 10);
		count++;
	}
	num *= sign_num;
	if (num > 2147483647 || num < -2147483648)
		return (false);
	return (true);
}

void	check_arguments(int argc, char **args)
{
	int	count;

	count = 0;
	while (args[count])
	{
		if (!ft_isnumber(args[count]))
			exit_with_errors(argc, args);
		else if (!ft_checklen(args[count]))
			exit_with_errors(argc, args);
		else if (!ft_isrepeated(args, count, ft_atoi(args[count])))
			exit_with_errors(argc, args);
		count++;
	}
}
