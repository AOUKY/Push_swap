#include "push_swap.h"

static int	cw(char const *s, char c)
{
	int	i;
	int	ct;
	int	n;

	i = 0;
	ct = 0;
	n = 1;
	while (s[i] != 0)
	{
		if (s[i] == c)
			n = 1;
		if (s[i] != c && n == 1)
		{
			ct++;
			n = 0;
		}
		i++;
	}
	return (ct);
}

static int	lenw(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

void	free_dp(char **s, int i)
{
	while (i >= 0)
		free(s[i--]);
	free(s);
}

static char	**msp(char **str, char const *s, int word, char c)
{
	int	i;

	i = 0;
	while (i < word)
	{
		while (*s == c)
			s++;
		str[i] = ft_substr(s, 0, lenw(s, c));
		if (str[i] == 0)
		{
			free_dp(str, i);
			return (0);
		}
		s += lenw(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word;

	word = cw(s, c);
	if (!word)
	{
		ft_printf("error\n");
		fr_lst(0, 0, 0);
	}
	str = malloc((word + 1) * sizeof(char *));
	if (str == 0)
		return (0);
	return (msp(str, s, word, c));
}