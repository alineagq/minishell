/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:44:58 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/22 00:02:24 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void t_split(void)
{
	printf("Testing: %s\n", strrchr(__FILE__, '/') + 1);
    init_report();

    // Test case 1: Splitting a string with a single delimiter
    const char *s1 = "Hello,World!";
    char c1 = ',';
    char **result1 = ft_split(s1, c1);
    assert(strcmp(result1[0], "Hello") == 0);
    assert(strcmp(result1[1], "World!") == 0);
    assert(result1[2] == NULL);
    free(result1[0]);
    free(result1[1]);
    free(result1);

    // Test case 2: Splitting a string with multiple delimiters
    const char *s2 = "This is a test";
    char c2 = ' ';
    char **result2 = ft_split(s2, c2);
    assert(strcmp(result2[0], "This") == 0);
    assert(strcmp(result2[1], "is") == 0);
    assert(strcmp(result2[2], "a") == 0);
    assert(strcmp(result2[3], "test") == 0);
    assert(result2[4] == NULL);
    free(result2[0]);
    free(result2[1]);
    free(result2[2]);
    free(result2[3]);
    free(result2);

    // Test case 3: Splitting an empty string
    const char *s3 = "";
    char c3 = ' ';
    char **result3 = ft_split(s3, c3);
    assert(result3[0] == NULL);
    free(result3);

    // Test case 4: Splitting a string without any delimiter
    const char *s4 = "NoDelimiter";
    char c4 = '.';
    char **result4 = ft_split(s4, c4);
    assert(strcmp(result4[0], "NoDelimiter") == 0);
    assert(result4[1] == NULL);
    free(result4[0]);
    free(result4);

    // Test case 5: Splitting a string with leading and trailing delimiters
    const char *s5 = "  Trim this   ";
    char c5 = ' ';
    char **result5 = ft_split(s5, c5);
    assert(strcmp(result5[0], "Trim") == 0);
    assert(strcmp(result5[1], "this") == 0);
    assert(result5[2] == NULL);
    free(result5[0]);
    free(result5[1]);
    free(result5);

    // Test case 6: Splitting a string with consecutive delimiters
    const char *s6 = "Consecutive,,,Delimiters";
    char c6 = ',';
    char **result6 = ft_split(s6, c6);
    assert(strcmp(result6[0], "Consecutive") == 0);
    assert(strcmp(result6[1], "Delimiters") == 0);
    assert(result6[2] == NULL);
    free(result6[0]);
    free(result6[1]);
    free(result6);

    // Test case 7: Splitting a string with a non-existent delimiter
    const char *s7 = "NoDelimiter";
    char c7 = ',';
    char **result7 = ft_split(s7, c7);
    assert(strcmp(result7[0], "NoDelimiter") == 0);
    assert(result7[1] == NULL);
    free(result7[0]);
    free(result7);

    // Test case 8: Splitting a NULL string
    const char *s8 = NULL;
    char c8 = ' ';
    char **result8 = ft_split(s8, c8);
    assert(result8 == NULL);

	 report();
}
