#include "../includes/utils.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		icopy;
	int		istr;

	if (s1 == NULL)
		return (NULL);
	icopy = 0;
	istr = 0;
	copy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (! copy)
		return (NULL);
	while (s1[istr] != '\0')
		copy[icopy++] = s1[istr++];
	copy[icopy] = '\0';
	return (copy);
}
