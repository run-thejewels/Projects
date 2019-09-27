/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:03:48 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/03 13:46:58 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnltests.h"

char	*line = NULL;

void	my_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

static int	generic_tester(char *expected, int fd)
{
	GNLRETURN(get_next_line(fd, &line));
	if (line && !strcmp(line, expected))
	{
		PRINTFSUCCESS;
		return (1);
	}
	else
	{
		PRINTFFAILURE;
		printf("your line =\n|%s|\ninstead of\n|%s|\n", line, expected);
	}
	return (0);
}

void	basic_test(void)
{
	NAME("One line, 8 chars no \\n");
	int fd = open("./tests/test1", O_RDONLY);
	generic_tester("teeeeest", fd);
	my_memdel((void**)&line);
	close(fd);

///////////////=================================================

	NAME("7 lines, different line sizes");
	fd = open("./tests/test2", O_RDONLY);
	generic_tester("1234fjdskfjdskfjdskjfhds1", fd);
	generic_tester("fdsfjhdskfjhdskfjh dskfjhds2", fd);
	generic_tester("kfjhdskfjhdskjfhdskjfh3", fd);
	generic_tester("dskjfhdskfjhsdk fjhsdkjfhsdkf4", fd);
	generic_tester("jhsdkfjhdskfjhdskfjhdskfjhdskfjhdskfjhds fsdf 5", fd);
	generic_tester(" fjdslfkjdslkfjdslk fjdslfj dslkfjdslfkjsdlfkjsdlkfjdslkfjsdlkjfldskfjoidjfgodigjfodgjfd lgjfdkl gjfdlgj dfigjfdoi jgodfjg ofdijgofdijg6", fd);
	generic_tester(" fsdjflisdjfsdjfidsjfidsjfoisdjfodsijfodsijgidfjgoifdjgopdfkgdf7", fd);
	
	if (!get_next_line(fd, &line))
		PRINTFSUCCESS;
	else
		PRINTFFAILURE;

	my_memdel((void**)&line);
	close(fd);

///////////////================================================

	NAME("4 lines, no final \\n");
	fd = open("./tests/gnl7_3.txt", O_RDONLY);
	generic_tester("1234567", fd);
	generic_tester("abcdefg", fd);
	generic_tester("4567890", fd);
	generic_tester("defghijk", fd);
	my_memdel((void**)&line);
	close(fd);

///////////////=================================================

	NAME("2 lines, 7 and 8 chars, no final \\n");
	fd = open("./tests/gnl7_2.txt", O_RDONLY);
	generic_tester("1234567", fd);
	generic_tester("abcdefgh", fd);
	my_memdel((void**)&line);
	close(fd);

///////////////=================================================

	NAME("One line, 100k chars, no final \\n");
	char	*bigstr;
	int		testfd;
	int		cursor;

	if (!(bigstr = (char*)malloc(sizeof(char) * 150001)))
		printf("test error, not your program fault\n");
	testfd = open("./tests/test5", O_RDONLY);
	cursor = read(fd, bigstr, 150000);
	close(testfd);
	if (cursor >= 0)
		bigstr[cursor] = '\0';
	else
		printf("Test error, not your gnl fault\n");
	fd = open("./tests/test5", O_RDONLY);
	get_next_line(fd, &line);
	if (line && bigstr && !strcmp(line, bigstr))
		PRINTFSUCCESS;
	else
		PRINTFFAILURE;
	close(fd);
	free(bigstr);

///////////////=================================================

	NAME("Wrong fd test");
	fd = 42;
	if (get_next_line(fd, &line) == -1)
		PRINTFSUCCESS;
	else
	{
		PRINTFFAILURE;
		printf("Your gnl doesn't handle wrong fd errors\n");
	}
}
