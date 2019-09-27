/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:17:08 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/17 19:18:13 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLTESTS_H
#define GNLTESTS_H

#include "../gnl/get_next_line.h"
#include "../gnl/libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define NAME(name) printf("=== %s ===\n", name);
#define SUCCESSMSG "\e[32m[Success]\e[39m\n"
#define PRINTFSUCCESS printf("%s", SUCCESSMSG)
#define FAILUREMSG "\e[31m[Failure]\e[39m\n"
#define PRINTFFAILURE printf("%s", FAILUREMSG)
#define EASYTESTFAIL printf("Echec d'un test de fonctionnement basique\n");
#define INTMIN "-2147483648"
#define INTMAX "2147483647"
#define GNLRETURN(ret) printf("Return Value : %d\n", ret)

void	basic_test(void);
void	buffer_test(void);
void	fd0_test(void);

#endif
