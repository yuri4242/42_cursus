#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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
    int     size;

    printf("========= Test Cases for lstsize =========\n\n");

    // --- テストケース1: 空のリスト ---
    printf("--- Test Case 1: Empty list ---\n");
    size = ft_lstsize(head);
    printf("Expected: 0, Got: %d -> %s\n\n", size, size == 0 ? "✅ OK" : "❌ NG");
    
    // --- テストケース2: 要素が1つのリスト ---
    printf("--- Test Case 2: List with one element ---\n");
    ft_lstadd_front(&head, ft_lstnew("first"));
    size = ft_lstsize(head);
    printf("Expected: 1, Got: %d -> %s\n\n", size, size == 1 ? "✅ OK" : "❌ NG");

    // --- テストケース3: 要素が複数のリスト ---
    printf("--- Test Case 3: List with multiple elements ---\n");
    ft_lstadd_front(&head, ft_lstnew("second"));
    ft_lstadd_front(&head, ft_lstnew("third"));
    size = ft_lstsize(head);
    printf("Expected: 3, Got: %d -> %s\n\n", size, size == 3 ? "✅ OK" : "❌ NG");

    // --- テストケース4: 無効のリスト ---
    printf("--- Test Case 4: Unvails list ---\n");
    size = ft_lstsize(NULL);
    printf("Expected: 0, Got: %d -> %s\n\n", size, size == 0 ? "✅ OK" : "❌ NG");

    // 最後に確保した全メモリを解放
    free_list(head);

    return (0);
}
