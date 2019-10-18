/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:02:14 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:09:11 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (cs1[i] != '\0' && cs2[i] != '\0')
	{
		if (cs1[i] - cs2[i] != 0)
			return (cs1[i] - cs2[i]);
		i++;
	}
	if (cs1[i] == '\0' && cs2[i] == '\0')
		return (0);
	else if (cs1[i] == '\0')
		return (-cs2[i]);
	else
		return (cs1[i]);
}
