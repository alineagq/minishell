/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_putchar_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:52:59 by fsuomins          #+#    #+#             */
/*   Updated: 2023/07/22 01:25:48 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../files/test.h"

void	t_putchar_fd(void)
{
	init_report();
	// Test case 1: Valid character (e.g., 'A') and valid file descriptor (STDOUT_FILENO)
    char test_char1 = 'A';
    int file_descriptor1 = open("test_output1.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(file_descriptor1 != -1);
    
    ft_putchar_fd(test_char1, file_descriptor1);
    
    // Test case 2: Another valid character (e.g., 'Z') and valid file descriptor
    char test_char2 = 'Z';
    int file_descriptor2 = open("test_output2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(file_descriptor2 != -1);
    
    ft_putchar_fd(test_char2, file_descriptor2);

    // Test case 3: Invalid file descriptor (e.g., -1)
    char test_char3 = '!';
    int invalid_fd = -1;
    
    // Redirect stderr to a file
    int error_fd = open("test_error_output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(error_fd != -1);
    int stderr_backup = dup(STDERR_FILENO);
    dup2(error_fd, STDERR_FILENO);
    
    // This call to ft_putchar_fd with an invalid file descriptor should trigger an error message
    ft_putchar_fd(test_char3, invalid_fd);
    
    // Restore stderr
    fflush(stderr);
    close(error_fd);
    dup2(stderr_backup, STDERR_FILENO);
    close(stderr_backup);

    // Clean up and assert that there are no errors
    close(file_descriptor1);
    close(file_descriptor2);
    
    // Read the contents of the files to check if characters are inside
    FILE* file1 = fopen("test_output1.txt", "r");
    assert(file1 != NULL);
    char content1[2]; // Assuming the file contains only one character and null terminator
    assert(fread(content1, sizeof(char), 1, file1) == 1);
    fclose(file1);

    FILE* file2 = fopen("test_output2.txt", "r");
    assert(file2 != NULL);
    char content2[2]; // Assuming the file contains only one character and null terminator
    assert(fread(content2, sizeof(char), 1, file2) == 1);
    fclose(file2);

    // Read the contents of the error file and check for the error message
    FILE* error_file = fopen("test_error_output.txt", "r");
    assert(error_file != NULL);
    fseek(error_file, 0, SEEK_END);
    long file_size = ftell(error_file);
    fseek(error_file, 0, SEEK_SET);

    char error_content[file_size + 1];
    size_t read_size = fread(error_content, 1, file_size, error_file);
    fclose(error_file);

    // Null-terminate the error_content
    error_content[read_size] = '\0';

    // Check the contents of the files
    assert(content1[0] == test_char1);
    assert(content2[0] == test_char2);

    // Clean up and destroy all files created during testing
    remove("test_output1.txt");
    remove("test_output2.txt");
    remove("test_error_output.txt");
	report();
}
