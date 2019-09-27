#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_c.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_c_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_c_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_c";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%c|%-c|%12c|%-12c\", 0, 0, 0, 0",
			&conv_c_char_null, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c|%c\", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127",
			&conv_c_ascii_chars, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c\", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127",
			&conv_c_ascii_chars_8_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c|%-14c\", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127",
			&conv_c_ascii_chars_8_width_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c|%-c|%12c|%-12c\", 1345, 1345, 1345, 1345",
			&conv_c_short_max, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}