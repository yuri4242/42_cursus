#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// リストのメモリを解放するためのヘルパー関数
void    free_list(t_list *head)
{
    t_list *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void)
{
    t_list *head = NULL;
    t_list *new_node;
    t_list *last;

    printf("========= Test Cases for lstadd_back =========\n\n");

    // --- テストケース1: 空のリストに最初の要素を追加 ---
    printf("--- Test Case 1: Add to an empty list ---\n");
    printf("Initial state:\n");
    print_list(head);
    
    new_node = ft_lstnew("first element");
    ft_lstadd_back(&head, new_node);
    
    printf("After adding \"first element\":\n");
    print_list(head);
    // 最後の要素を確認
    last = ft_lstlast(head);
    if (last && strcmp(last->content, "first element") == 0)
        printf("✅ OK: Last element is correct.\n\n");
    else
        printf("❌ NG: Last element is incorrect.\n\n");

    // --- テストケース2: 既存のリストの末尾に要素を追加 ---
    printf("--- Test Case 2: Add to a non-empty list ---\n");
    new_node = ft_lstnew("second element");
    ft_lstadd_back(&head, new_node);

    printf("After adding \"second element\":\n");
    print_list(head);
    // 最後の要素を確認
    last = ft_lstlast(head);
    if (last && strcmp(last->content, "second element") == 0)
        printf("✅ OK: Last element is correct.\n\n");
    else
        printf("❌ NG: Last element is incorrect.\n\n");
    
    // --- テストケース3: さらに要素を追加 ---
    printf("--- Test Case 3: Add another element ---\n");
    new_node = ft_lstnew("third element");
    ft_lstadd_back(&head, new_node);

    printf("After adding \"third element\":\n");
    print_list(head);
    // 最後の要素を確認
    last = ft_lstlast(head);
    if (last && strcmp(last->content, "third element") == 0)
        printf("✅ OK: Last element is correct.\n\n");
    else
        printf("❌ NG: Last element is incorrect.\n\n");
    
    // 最後に確保した全メモリを解放
    free_list(head);

    return (0);
}
