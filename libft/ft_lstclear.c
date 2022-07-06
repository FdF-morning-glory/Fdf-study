/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:47:53 by hogkim            #+#    #+#             */
/*   Updated: 2021/12/27 00:36:45 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!(*lst))
		return ;
	p = *lst;
	while (p)
	{
		*lst = (*lst)->next;
		ft_lstdelone(p, del);
		p = *lst;
	}
}
