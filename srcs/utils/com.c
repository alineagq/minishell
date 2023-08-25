/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:15:37 by coder             #+#    #+#             */
/*   Updated: 2023/08/24 19:52:32 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Função para liberar a memória de todos os caminhos
void free_all_paths(char **all_paths) {
    if (all_paths) {
        char **ptr = all_paths;
        while (*ptr) {
            free(*ptr);
            ptr++;
        }
        free(all_paths);
    }
}

// Função para verificar acesso e retornar o primeiro caminho válido
char *access_all_paths(char **all_paths) {
    char **ptr = all_paths;
    while (*ptr) {
        if (access(*ptr, F_OK | X_OK) == 0) {
            return strdup(*ptr);
        }
        ptr++;
    }
    return NULL;
}

// Função para encontrar o índice da variável "PATH" em envp
int get_path_index_from_envp(char **envp) {
    char **ptr = envp;
    int index = 0;
    while (*ptr) {
        if (strncmp(*ptr, "PATH=", 5) == 0) {
            return index;
        }
        ptr++;
        index++;
    }
    return -1;
}

// Função para concatenar o comando com cada caminho
char **cat_cmd_to_all_paths(const char *cmd_arg, char **all_paths) {
    int all_paths_count = 0;
    char **ptr = all_paths;
    while (*ptr) {
        all_paths_count++;
        ptr++;
    }
    
    char **result = malloc(sizeof(char *) * (all_paths_count + 1));
    if (!result) {
        return NULL;
    }
    
    ptr = all_paths;
    char **result_ptr = result;
    while (*ptr) {
        int len = strlen(*ptr) + strlen(cmd_arg) + 2;
        *result_ptr = malloc(sizeof(char) * len);
        if (!(*result_ptr)) {
            free_all_paths(result);
            return NULL;
        }
        strcpy(*result_ptr, *ptr);
        strcat(*result_ptr, "/");
        strcat(*result_ptr, cmd_arg);
        
        ptr++;
        result_ptr++;
    }
    *result_ptr = NULL; // Marcar o final do array
    
    return result;
}

// Função principal para encontrar o caminho do comando
char *get_path(const char *cmd_arg, char **envp) {
    if (cmd_arg[0] == '.') {
        return strdup(cmd_arg);
    }
    
    int i = get_path_index_from_envp(envp);
    if (i == -1) {
        write(2, "Error getting path index from ENVP\n", 35);
        return NULL;
    }
    
    char **all_paths = cat_cmd_to_all_paths(cmd_arg, ft_split(envp[i] + 5, ':'));
    if (!all_paths) {
        return NULL;
    }
    
    char *path = access_all_paths(all_paths);
    free_all_paths(all_paths);
    
    return path;
}