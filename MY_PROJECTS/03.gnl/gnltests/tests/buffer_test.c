#include "../gnltests.h"
#include <stdio.h>
#include <fcntl.h>

///////////////=================================================
//Thanks to sacrimento for this test idea

void buffer_test(void)
{
	NAME("Buffer test");
	printf ("This test cannot be completed if you store the whole file at the first gnl call\nIt doesn't mean you're wrong !\n");
	char	*str;
	int		count = 0;
	int		res = 0;
	int fd = open("/dev/random", O_RDONLY);
	while ((res = get_next_line(fd, &str)) == 1 && count < 10000)
		count++;
	if (res)
		PRINTFSUCCESS;
	else
	{
		PRINTFFAILURE;
		printf("Votre get_next_line ne manipule pas correctement son buffer\n");
	}
}
