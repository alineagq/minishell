/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:29:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/06/10 19:41:26 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minunit.h"
#include "../libft.h"
#include <ctype.h>
#include <fcntl.h>

// Test case for get_next_line with a simple line
MU_TEST(test_get_next_line_simple_line)
{
	// Set up the test
	FILE *file = fopen("test.txt", "w");
	fprintf(file, "Hello, world!\n");
	fclose(file);
	int fd = open("test.txt", O_RDONLY);

	// Execute the function
	char *line = get_next_line(fd);

	// Perform the assertions
	mu_assert( strlen(line) != 0, "Error: line is NULL");
	mu_assert (strcmp(line, "Hello, world!") == 0, "Error: line does not match expected value");

	// Clean up
	close(fd);
	remove("test.txt");
	free(line);
}

// Test case for get_next_line with an empty file
MU_TEST(test_get_next_line_empty_file)
{
	// Set up the test
	FILE *file = fopen("test.txt", "w");
	fclose(file);
	int fd = open("test.txt", O_RDONLY);

	// Execute the function
	char *line = get_next_line(fd);

	// Perform the assertions
	mu_assert(line == NULL, "Error: line is not NULL");

	// Clean up
	close(fd);
	remove("test.txt");
}

// Test case for get_next_line with multiple lines
MU_TEST(test_get_next_line_multiple_lines)
{
	// Set up the test
	FILE *file = fopen("test.txt", "w");
	fprintf(file, "Line 1\nLine 2\nLine 3\n");
	fclose(file);
	int fd = open("test.txt", O_RDONLY);

	// Execute the function for the first line
	char *line = get_next_line(fd);

	// Perform the assertions for the first line
	mu_assert(line != NULL, "Error: line is NULL");
	mu_assert(strcmp(line, "Line 1") == 0 , "Error: line does not match expected value");
	free(line);

	// Execute the function for the second line
	line = get_next_line(fd);

	// Perform the assertions for the second line
	mu_assert( line != NULL, "Error: line is NULL");
	mu_assert(strcmp(line, "Line 2") == 0, "Error: line does not match expected value");
	free(line);

	// Execute the function for the third line
	line = get_next_line(fd);

	// Perform the assertions for the third line
	mu_assert( line != NULL, "Error: line is NULL");
	mu_assert(strcmp(line, "Line 3") == 0, "Error: line does not match expected value");
	free(line);

	// Execute the function after reaching the end of the file
	line = get_next_line(fd);

	// Perform the assertions after reaching the end of the file
	mu_assert(line != NULL, "Error: line is not NULL");

	// Clean up
	close(fd);
	remove("test.txt");
}

// Test suite initialization
MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_get_next_line_simple_line);
	MU_RUN_TEST(test_get_next_line_empty_file);
	MU_RUN_TEST(test_get_next_line_multiple_lines);
}

// Entry point
int main()
{
    MU_RUN_SUITE(test_suite);
	MU_REPORT();
    return (0);
}
