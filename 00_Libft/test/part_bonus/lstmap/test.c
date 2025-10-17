#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// f関数1: 文字列の先頭に "new_" を追加する
void    *map_add_prefix(void *content)
{
    char *str = (char *)content;
    char *new_str = malloc(strlen(str) + 5);
    if (!new_str)
        return (NULL);
    strcpy(new_str, "new_");
    strcat(new_str, str);
    return (new_str);
}

// del関数1: 文字列contentを解放する
void    del_content(void *content)
{
    free(content);
}

// リストの内容を分かりやすく表示するためのヘルパー関数
void    print_list(t_list *head)
{
    printf("List -> ");
    if (!head)
    {
        printf("NULL\n");
        return;
    }
    while (head)
    {
        printf("[\"%s\"] -> ", (char *)head->content);
        head = head->next;
    }
    printf("NULL\n");
}


int main(void)
{
    t_list *head_orig = NULL;
    t_list *head_new;

    printf("========= Test Cases for lstmap =========\n\n");

    // --- テストケース1: 通常のmap操作 ---
    printf("--- Test Case 1: Normal map operation ---\n");
    // 元のリストを作成: [elem3] -> [elem2] -> [elem1] -> NULL
    ft_lstadd_front(&head_orig, ft_lstnew(strdup("element 1")));
    ft_lstadd_front(&head_orig, ft_lstnew(strdup("element 2")));
    ft_lstadd_front(&head_orig, ft_lstnew(strdup("element 3")));
    
    printf("Original list:\n");
    print_list(head_orig);

    // ft_lstmapを呼び出し
    head_new = ft_lstmap(head_orig, &map_add_prefix, &del_content);

    printf("\nNew list created by ft_lstmap:\n");
    print_list(head_new);
    if (head_new)
        printf("✅ OK: New list was created.\n\n");
    else
        printf("❌ NG: New list is NULL.\n\n");

    // --- テストケース2: 空のリストを渡す ---
    printf("--- Test Case 2: Map on an empty list ---\n");
    t_list *empty_list = NULL;
    t_list *result_from_empty = ft_lstmap(empty_list, &map_add_prefix, &del_content);
    printf("Result from empty list is: ");
    if (result_from_empty == NULL)
        printf("NULL\n✅ OK\n\n");
    else
        printf("NOT NULL\n❌ NG\n\n");

    // --- テストケース3: 無効な関数を渡す ---
    printf("--- Test Case 3: Map on an Invalid function ---\n");
    t_list *result_from_invalid = ft_lstmap(head_orig, NULL, &del_content);
    printf("Result from Invaild function is: ");
    if (result_from_invalid == NULL)
        printf("NULL\n✅ OK\n\n");
    else
        printf("NOT NULL\n❌ NG\n\n");


    // 最後に確保した全メモリを解放
    ft_lstclear(&head_orig, &del_content);
    ft_lstclear(&head_new, &del_content);

    printf("Run with valgrind to check for memory leaks, especially if a malloc fails.\n");
    
    return (0);
}
