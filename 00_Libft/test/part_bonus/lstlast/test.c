#include "libft.h"
#include <stdio.h>
#include <string.h>
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
    t_list *last;
    t_list *node1, *node2, *node3;

    printf("========= Test Cases for lstlast =========\n\n");

    // --- テストケース1: 空のリスト ---
    printf("--- Test Case 1: Empty list ---\n");
    last = ft_lstlast(head);
    if (last == NULL)
        printf("✅ OK: Returned NULL for an empty list.\n\n");
    else
        printf("❌ NG: Should return NULL for an empty list.\n\n");

    // --- テストケース2: 要素が1つのリスト ---
    printf("--- Test Case 2: List with one element ---\n");
    node1 = ft_lstnew("node1");
    head = node1;
    last = ft_lstlast(head);
    printf("Expected last content: \"node1\"\n");
    printf("Got last content:      \"%s\"\n", (char *)last->content);
    if (last == node1)
        printf("✅ OK: Returned a pointer to the only element.\n\n");
    else
        printf("❌ NG: Did not return the correct pointer.\n\n");
    
    // --- テストケース3: 要素が複数のリスト ---
    printf("--- Test Case 3: List with multiple elements ---\n");
    node2 = ft_lstnew("node2");
    node3 = ft_lstnew("node3");
    ft_lstadd_front(&head, node2); // List: node2 -> node1
    ft_lstadd_front(&head, node3); // List: node3 -> node2 -> node1
    
    last = ft_lstlast(head);
    printf("Expected last content: \"node1\"\n");
    printf("Got last content:      \"%s\"\n", (char *)last->content);
    if (last == node1) // 最後の要素は最初に作ったnode1のはず
        printf("✅ OK: Returned a pointer to the last element.\n\n");
    else
        printf("❌ NG: Did not return the correct pointer.\n\n");

    // 最後に確保した全メモリを解放
    free_list(head);

    return (0);
}
