#include "libftprintf.h"

void	ftpf_del(t_ftpf **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = NULL;
	}
}
