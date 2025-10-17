#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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
        // contentが文字列であると仮定して表示
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

    printf("========= Test Cases for lstadd_front =========\n\n");

    // --- テストケース1: 空のリストに最初の要素を追加 ---
    printf("--- Test Case 1: Add to an empty list ---\n");
    printf("Initial state:\n");
    print_list(head);
    
    new_node = ft_lstnew("first element");
    ft_lstadd_front(&head, new_node);
    
    printf("After adding \"first element\":\n");
    print_list(head);
    printf("\n");

    // --- テストケース2: 既存のリストの先頭に要素を追加 ---
    printf("--- Test Case 2: Add to a non-empty list ---\n");
    new_node = ft_lstnew("second element");
    ft_lstadd_front(&head, new_node);

    printf("After adding \"second element\":\n");
    print_list(head);
    printf("\n");
    
    // --- テストケース3: さらに要素を追加 ---
    printf("--- Test Case 3: Add another element ---\n");
    new_node = ft_lstnew("third element");
    ft_lstadd_front(&head, new_node);

    printf("After adding \"third element\":\n");
    print_list(head);
    printf("\n");

    // --- テストケース4: NULLの要素を追加 ---
    printf("--- Test Case 4: Add a NULL element ---\n");
    // このテストは関数がNULLをどう扱うかによる
    // ft_lstadd_front(NULL, new_node); // lstがNULL
    // ft_lstadd_front(&head, NULL);    // newがNULL
    printf("Passing NULL to the function should not cause a crash.\n");
    ft_lstadd_front(&head, NULL);
    print_list(head);
    
    // 最後に確保した全メモリを解放
    free_list(head);

    return (0);
}
