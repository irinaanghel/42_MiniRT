#include "../includes/utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i1;
	int		i2;
	int		ires;

	ires = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (! res)
		return (NULL);
	i1 = 0;
	while (s1[i1] != '\0')
		res[ires++] = s1[i1++];
	i2 = 0;
	while (s2[i2] != '\0')
		res[ires++] = s2[i2++];
	res[ires] = '\0';
	return (res);
}
