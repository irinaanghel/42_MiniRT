#include "../includes/utils.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*res;
	size_t	ires;

	if (s == NULL)
		return (NULL);
	ires = 0;
	res = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	while (ires < ft_strlen(s))
	{
		res[ires] = f(ires, s[ires]);
		ires++;
	}
	return (res);
}
