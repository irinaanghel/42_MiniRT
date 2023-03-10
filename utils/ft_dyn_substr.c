#include "../includes/utils.h"

char	*ft_dyn_substr(char **s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	isub;

	isub = 0;
	if ((*s) == NULL)
		return (NULL);
	if (start > ft_strlen(*s))
		return (ft_strdup(""));
	if ((ft_strlen(*s) - start) < len)
		substr = malloc((ft_strlen(*s) - start + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (! substr)
		return (NULL);
	while (isub < len && (*s)[start] != '\0')
		substr[isub++] = (*s)[start++];
	substr[isub] = '\0';
	free(*s);
	return (substr);
}
