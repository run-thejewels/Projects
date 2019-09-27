#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define DEBUG fprintf(stderr, "In %s, line %d of %s\n", __func__, __LINE__, __FILE__);

#define MY_TEST(name, ft) printf("\033[0m%s -- \033[0m", name); ft(); \
	printf("\n");

#define MY_UNIT_TEST(ft) void	ft()

#define check_int_eq(std, own) if(std ==  own) { printf("\033[32mo\033[32m"); }\
									   else { printf("\033[31mx\033[31m"); }

#define check_str_eq(std, own) if(!strcmp(std, own)) \
{ printf("\033[32mo\033[32m"); } else { printf("\033[31mx\033[31m"); }

#define check(cond) if(cond) { printf("\033[32mo\033[32m"); }\
	else { printf("\033[31mx\033[31m"); }

/*
** This is how to use this unit-test header:
** void	test_fpf_test()
** {
**	check(fpf_test(sthing) == "sthing");
** }
**
** int		main(void)
** {
**	MY_TEST("name of your function", test_fpf_test);
**	return (0);
** }
*/

#endif
