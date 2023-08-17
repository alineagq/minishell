/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:47 by fsuomins          #+#    #+#             */
/*   Updated: 2023/08/17 17:24:13 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_list	*create_env_list(char **env)
{
    t_env_list *head = NULL;
    t_env_list *current = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        char *envVar = env[i];
        char *key = strtok(envVar, "=");
        char *value = strtok(NULL, "=");

        if (value == NULL) {
            continue;  // Skip this iteration if value is null
        }

        t_env_list *node = (t_env_list*)malloc(sizeof(t_env_list) + 1);
        node->key = strdup(key);
        node->value = strdup(value);
        node->next = NULL;

        if (head == NULL) {
            head = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }
    return head;
}

void print_env_list(t_env_list *head)
{
    t_env_list *current = head;

    while (current != NULL) {
        printf("%s=%s\n", current->key, current->value);
        current = current->next;
    }
}

char* get_value_env(t_env_list *head, const char *key) {
    t_env_list *current = head;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;  // Key not found
}

void update_or_insert_value(t_env_list **head, const char *key, const char *new_value)
{
    t_env_list *current = *head;
    t_env_list *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            free(current->value);
            current->value = strdup(new_value);
            return;
        }
        prev = current;
        current = current->next;
    }

    // Key not found, insert a new node
    t_env_list *new_node = (t_env_list*)malloc(sizeof(t_env_list) + 1);
    new_node->key = strdup(key);
    new_node->value = strdup(new_value);
    new_node->next = NULL;

    if (prev == NULL) {
        // Insert at the beginning of the list
        *head = new_node;
    } else {
        // Insert at the end of the list
        prev->next = new_node;
    }
}
