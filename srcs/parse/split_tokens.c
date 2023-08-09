#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_quote(char c) {
    return c == '\'' || c == '"';
}

char **split_string(const char *input, int *num_tokens) {
    const int max_tokens = 100;  // Maximum number of tokens
    char **tokens = (char **)malloc(sizeof(char *) * max_tokens);
    int token_count = 0;
    int token_start = 0;
    bool inside_quote = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (is_quote(input[i])) {
            inside_quote = !inside_quote;
        }

        if (!inside_quote && input[i] == ' ') {
            int token_length = i - token_start;
            if (token_length > 0) {
                tokens[token_count] = (char *)malloc(token_length + 1);
                strncpy(tokens[token_count], input + token_start, token_length);
                tokens[token_count][token_length] = '\0';
                token_count++;
            }
            token_start = i + 1;
        }
    }

    if (token_start < strlen(input)) {
        int token_length = strlen(input) - token_start;
        tokens[token_count] = (char *)malloc(token_length + 1);
        strncpy(tokens[token_count], input + token_start, token_length);
        tokens[token_count][token_length] = '\0';
        token_count++;
    }

    *num_tokens = token_count;
    return tokens;
}

int main() {
    const char input[] = "echo 'Hello World' | \"Another quote\"";
    int num_tokens = 0;
    char **tokens = split_string(input, &num_tokens);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }

    // Free memory
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}
