/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_multicharset.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: plamtenz <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 03:40:07 by plamtenz     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 11:54:45 by plamtenz    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//#include "miniRT.h"

#include <stdbool.h>
#include <stdlib.h>

bool	is_sep(char c, char *charset)
{
	int it;

	it = 0;
	while (charset[it])
	{
		if (c == charset[it])
			return (true);
		it++;
	}
	return (false);
}

int		count_word(char *str, char *charset)
{
	int		it;
	int		count;
	bool	bcount;

	it = 0;
	count = 0;
	bcount = true;
	while (str[it])
	{
		while (is_sep(str[it], charset) && str[it])
			it++;
		while (!is_sep(str[it], charset) && str[it])
		{
			it++;
			if (bcount == true)
				count++;
			bcount = false;
		}
		bcount = true;
	}
	return (count);
}

int		len_word(char *str, char *charset)
{
	int it;

	it = 0;
	while (!is_sep(str[it], charset) && str[it])
		it++;
	return (it);
}

char	*copy_word(char *str, char *charset)
{
	int		it;
	int		len;
	char	*tab;

	it = 0;
	len = len_word(&str[it], charset);
	tab = (char*)malloc((len + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (!is_sep(str[it], charset) && str[it])
	{
		tab[it] = str[it];
		it++;
	}
	tab[it] = '\0';
	return (tab);
}

char	**split_multicharset(char *str, char *charset)
{
	int		it;
	int		it_tab;
	char	**tab;

	it = 0;
	it_tab = 0;
	tab = (char**)malloc((count_word(str, charset) + 1) * sizeof(char*));
	if (tab == NULL)
		return (NULL);
	while (str[it])
	{
		while (is_sep(str[it], charset) && str[it])
			it++;
		if (!is_sep(str[it], charset) && str[it])
		{
			tab[it_tab] = copy_word(&str[it], charset);
			it += len_word(&str[it], charset);
			it_tab++;
		}
	}
	tab[it_tab] = 0;
	return (tab);
}
