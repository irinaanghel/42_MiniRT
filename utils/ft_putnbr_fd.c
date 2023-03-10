#include "../includes/utils.h"

void	ft_putnbr_fd(long n, int fd)
{
	char			cnbr;
	char			minus;
	unsigned int	nbr;

	minus = '-';
	if (n < 0)
	{
		write(fd, &minus, 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	if (nbr < 10)
	{
		cnbr = nbr + '0';
		write(fd, &cnbr, 1);
	}
}
