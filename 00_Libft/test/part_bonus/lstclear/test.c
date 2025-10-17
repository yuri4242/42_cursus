#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ft_lstclearに渡すための、contentを解放する関数
void    del_content(void *content)
{
    // contentはmallocで確保されたメモリを指していると仮定
    free(content);
}

// リストの状態を表示するヘルパー関数
void    print_list_state(t_list *head)
{
    if (head == NULL)
        printf("List is now NULL.\n");
    else
        printf("List is NOT NULL. (Error!)\n");
}

int main(void)
{
    t_list *head1 = NULL;
    t_list *head2 = NULL;

    printf("========= Test Cases for lstclear =========\n\n");

    // --- テストケース1: 複数の要素を持つリストをクリア ---
    printf("--- Test Case 1: Clear a multi-node list ---\n");
    // テスト用リストを作成: [elem3] -> [elem2] -> [elem1] -> NULL
    ft_lstadd_front(&head1, ft_lstnew(strdup("element 1")));
    ft_lstadd_front(&head1, ft_lstnew(strdup("element 2")));
    ft_lstadd_front(&head1, ft_lstnew(strdup("element 3")));
    printf("Before clear, head pointer is: %p\n", head1);

    ft_lstclear(&head1, &del_content);

    printf("After clear:\n");
    print_list_state(head1);
    if (head1 == NULL)
        printf("✅ OK: Head pointer is NULL.\n\n");
    else
        printf("❌ NG: Head pointer is NOT NULL.\n\n");
    
    // --- テストケース2: 空のリスト（NULLポインタ）をクリア ---
    printf("--- Test Case 2: Clear an empty list (NULL) ---\n");
    printf("Before clear, head pointer is: %p\n", head2);
    
    ft_lstclear(&head2, &del_content); // head2は元々NULL

    printf("After clear:\n");
    print_list_state(head2);
    if (head2 == NULL)
        printf("✅ OK: Head pointer remains NULL.\n\n");
    else
        printf("❌ NG: Head pointer changed.\n\n");

    printf("Run with valgrind to check for memory leaks.\n");
    
    return (0);
}
