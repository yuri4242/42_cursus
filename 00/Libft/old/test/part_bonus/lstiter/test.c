#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. content（文字列と仮定）を表示する関数
void    print_content(void *content)
{
    printf(" -> [\"%s\"]", (char *)content);
}

// 2. content（intへのポインタと仮定）の値をインクリメントする関数
void    increment_content(void *content)
{
    int *num_ptr = (int *)content;
    (*num_ptr)++;
}


// リストのメモリを解放するためのヘルパー関数
void    free_list_with_content(t_list *head)
{
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->content);
        free(tmp);
    }
}

int main(void)
{
    t_list *head1 = NULL;
    t_list *head2 = NULL;
    int n1 = 10, n2 = 20, n3 = 30;

    printf("========= Test Cases for lstiter =========\n\n");

    // --- テストケース1: 各要素のcontentを表示する ---
    printf("--- Test Case 1: Print each element's content ---\n");
    ft_lstadd_back(&head1, ft_lstnew(strdup("first")));
    ft_lstadd_back(&head1, ft_lstnew(strdup("second")));
    ft_lstadd_back(&head1, ft_lstnew(strdup("third")));
    
    printf("Applying print_content function:\nList");
    ft_lstiter(head1, &print_content);
    printf("\n\n");

    // --- テストケース2: 各要素のcontent（整数）をインクリメントする ---
    printf("--- Test Case 2: Increment each element's integer content ---\n");
    ft_lstadd_back(&head2, ft_lstnew(&n1));
    ft_lstadd_back(&head2, ft_lstnew(&n2));
    ft_lstadd_back(&head2, ft_lstnew(&n3));

    printf("Before ft_lstiter: n1=%d, n2=%d, n3=%d\n", n1, n2, n3);
    ft_lstiter(head2, &increment_content);
    printf("After ft_lstiter:  n1=%d, n2=%d, n3=%d\n", n1, n2, n3);
    if (n1 == 11 && n2 == 21 && n3 == 31)
        printf("✅ OK\n\n");
    else
        printf("❌ NG\n\n");
        
    // --- テストケース3: 空のリスト ---
    printf("--- Test Case 3: Iterate over an empty list ---\n");
    ft_lstiter(NULL, &print_content);
    printf("✅ OK: Did not crash with a NULL list.\n\n");


    // --- テストケース4: 空のリスト ---
    printf("--- Test Case 4: Invaild fucntion ---\n");
    ft_lstiter(head1, NULL);
    printf("✅ OK: Did not crash with a NULL function.\n");

    // 最後に確保した全メモリを解放
    int i = 0;
    t_list *tmp;
    while(head1)
    {
        tmp = head1;
        head1 = head1->next;
        free(tmp->content);
        free(tmp);
    }
    // head2はcontentを解放しない
    while(head2)
    {
        tmp = head2;
        head2 = head2->next;
        free(tmp);
    }


    return (0);
}
