#include <stdio.h>
#include "unit_test.h"
#include "../include/push_swap.h"

// void		test_ft_parsing(void)
// {
// 	setbuf(stdout, NULL); // disable buffering on STDOUT
//
// 	t_plst	*ret = NULL;
// 	char	*av[4];
// 	int		ac = 4;
// 	av[0] = "a.out";
// 	av[1] =	"56";
// 	av[2] = "-89";
// 	av[3] = "2";
//
// 	printf("Test normal:\t");
// 	ret = ft_parsing(ac, av);
// 	print_la(ret);
//
// 	printf("\nTest int max:\t");
// 	av[0] = "a.out";
// 	av[1] =	"2147483647";
// 	av[2] = "1";
// 	av[3] = "2";
// 	ret = ft_parsing(ac, av);
// 	print_la(ret);
//
// 	printf("\nTest int min:\t");
// 	av[0] = "a.out";
// 	av[1] =	"-2147483648";
// 	av[2] = "1";
// 	av[3] = "2";
// 	ret = ft_parsing(ac, av);
// 	print_la(ret);

// The following tests should return "Error" and exit program

	// printf("\nTest int max plus:\t");
	// av[0] = "a.out";
	// av[1] =	"2147483789";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nTest int min less:\t");
	// av[0] = "a.out";
	// av[1] =	"-2147483893";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nTest double:\t");
	// av[0] = "a.out";
	// av[1] =	"2";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nNot digit:\t");
	// av[0] = "a.out";
	// av[1] =	"56";
	// av[2] = "87";
	// av[3] = "pow";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
// }

// void		test_ft_operations(void)
// {
// 	setbuf(stdout, NULL);
// 	t_plst	*la = NULL;
// 	t_plst	*lb;
// 	char	*av[6];
// 	int		ac = 6;
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "2";
// 	av[3] = "3";
// 	av[4] = "6";
// 	av[5] = "5";
// // Initializing lists
// 	la = ft_parsing(ac, av);
// 	lb = ft_pslstnew();
//
// 	printf("%-30s\n", "Liste initiale:");
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Test apres swap a:");
// 	ft_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
//
// 	printf("%-30s\n", "Push b:");
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Push b:");
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push b:");
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "2*push a:");
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap a:");
// 	ft_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push b:");
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Push b:");
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap a:");
// 	ft_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Push a:");
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap a:");
// 	ft_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap b:");
// 	ft_swap(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap b:");
// 	ft_swap(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push a:");
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate a:");
// 	ft_rotate(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate a:");
// 	ft_rotate(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate b:");
// 	ft_rotate(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push b:");
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate b:");
// 	ft_rotate(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "RevRotate a:");
// 	ft_revrotate(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "6*Push b:");
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "RevRotate b:");
// 	ft_revrotate(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate b:");
// 	ft_rotate(lb);
// 	print_la(la);
// 	print_lb(lb);
// }

// void		test_ft_plst_len(void)
// {
// 	setbuf(stdout, NULL);
// 	t_plst	*la = NULL;
// 	t_plst	lb;
// 	char	*av[6];
// 	int		ac = 6;
//
// 	av[0] = "a.out";
// 	av[1] = "56";
// 	av[2] = "15";
// 	av[3] = "78";
// 	av[4] = "-56";
// 	av[5] = "4";
// // Initializing my first list
// 	la = ft_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("%-30s", "Liste initiale:");
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres deux push b");
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres un push a");
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres un push a");
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres un push a inutile");
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
// }

// void		test_ft_example(void)
// {
// 	setbuf(stdout, NULL);
// 	t_plst	*la = NULL;
// 	t_plst	lb;
// 	char	*av[7];
// 	int		ac = 7;
//
// 	av[0] = "a.out";
// 	av[1] = "2";
// 	av[2] = "1";
// 	av[3] = "3";
// 	av[4] = "6";
// 	av[5] = "5";
// 	av[6] = "8";
// // Initializing my first list
// 	la = ft_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("%-30s", "Liste initiale:");
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Swap a:");
// 	ft_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "3*push b:");
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	ft_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Swap a:");
// 	ft_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "3*push a:");
// 	ft_push_a(la, lb);
// 	ft_push_a(la, lb);
// 	ft_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// }

// void		test_ft_sorts()
// {
// 	setbuf(stdout, NULL);
// 	t_plst	*la = NULL;
// 	t_plst	lb;
// 	char	*av[7];
// 	int		ac = 7;
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "2";
// 	av[3] = "3";
// 	av[4] = "4";
// 	av[5] = "5";
// 	av[6] = "8";
// // Initializing my first list
// 	la = ft_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("Liste est-elle trie ascending/croissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", ft_issortasc(la));
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "3";
// 	av[3] = "2";
// 	av[4] = "4";
// 	av[5] = "5";
// 	av[6] = "8";
// // Initializing my first list
// 	la = ft_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("Liste est-elle trie ascending/croissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", ft_issortasc(la));
//
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "2";
// 	av[3] = "3";
// 	av[4] = "4";
// 	av[5] = "5";
// 	av[6] = "6";
// // Initializing my first list
// 	la = ft_parsing(ac, av);
// 	t_node *tmp = la->head;
// 	la->head = la->tail;
// 	la->tail = tmp;
//
// 	printf("Liste est-elle trie descending/decroissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", ft_issortdes(la));
//
// 	ac = 2;
// 	av[0] = "a.out";
// 	av[1] = "0";
// // Initializing my first list
// 	la = ft_parsing(ac, av);
// 	tmp = la->head;
// 	la->head = la->tail;
// 	la->tail = tmp;
//
// 	printf("Liste est-elle trie descending/decroissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", ft_issortdes(la));
//
// }

// void		test_ft_sortmin(void)
// {
// 	setbuf(stdout, NULL);
// 	t_plst	*la = NULL;
// 	t_plst	*lb;
// 	char	*av[7];
// 	int		ac = 7;
// 	int		min;
//
// 	av[0] = "a.out";
// 	av[1] = "9";
// 	av[2] = "2";
// 	av[3] = "53";
// 	av[4] = "49";
// 	av[5] = "22";
// 	av[6] = "7";
// // Initializing my first list
// 	la = ft_parsing(ac, av);
// 	lb = ft_pslstnew();
//
// 	ft_sortmin(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// }

// void		test_ft_dyn_copy()
// {
// 	setbuf(stdout, NULL);
// 	t_plst	*mv = NULL;
// 	t_plst	*sol;
// 	char	*av[7];
// 	int		ac = 7;
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "6";
// 	av[3] = "3";
// 	av[4] = "4";
// 	av[5] = "5";
// 	av[6] = "8";
// // Initializing my first list
// 	mv = ft_parsing(ac, av);
// 	sol = ft_pslstnew();
//
// 	print_la(mv);
// 	print_lb(sol);
// 	sol = ft_dyn_copy(mv, sol);
// 	print_la(mv);
// 	print_lb(sol);
// }

void		test_ft_dyn_resolve()
{
	setbuf(stdout, NULL);
	t_plst	*l = NULL;
	t_plst	*mv;
	char	*av[9];
	int		ac = 9;

	av[0] = "a.out";
	av[1] = "4";
	av[2] = "6";
	av[3] = "10";
	av[4] = "12";
	av[5] = "19";
	av[6] = "25";
	av[7] = "36";
	av[8] = "29";

// Initializing my first list
	l = ft_parsing(ac, av);
	ft_print_l(l, "l");
	mv = ft_dyn_resolve(l);
	ft_print_l(mv, "mv");
	ft_display(mv);
	ft_lstclear(mv);
	ft_lstclear(l);
	while (1);
}

int			main()
{
	// test_ft_parsing();
	// test_ft_operations();
	// test_ft_plst_len();
	// test_ft_example();
	// test_ft_sorts();
	// test_ft_sortmin();
	// test_ft_dyn_copy();
	test_ft_dyn_resolve();
	return (0);
}
