#!/bin/sh

gcc test_main.c ../src/ft_bonusdisplaystack.c\
				../src/ft_display.c\
				../src/ft_dynamicalgorithm.c\
				../src/ft_error.c\
				../src/ft_operations.c\
				../src/ft_optimization.c\
				../src/ft_parsing.c\
				../src/ft_sortcocktail.c\
				../src/ft_sortmin.c\
				../lib/*.c\
				../ft_printf/libftprintf.a
