#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int success)
{
    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG\n");
}

int main(void)
{
    t_list *elem;

    printf("========= Test Cases for lstnew =========\n\n");

    // --- テストケース1: contentが文字列の場合 ---
    printf("--- Test Case 1: Content is a string ---\n");
    char *str_content = "Hello";
    elem = ft_lstnew(str_content);
    
    print_result("Node was created (not NULL)", elem != NULL);
    if (elem)
    {
        print_result("Content pointer is correct", elem->content == str_content);
        print_result("Content value is correct", strcmp((char *)elem->content, "Hello") == 0);
        print_result("Next pointer is NULL", elem->next == NULL);
        free(elem); // 確保したメモリを解放
    }
    printf("\n");

    // --- テストケース2: contentがintの場合 ---
    printf("--- Test Case 2: Content is an int ---\n");
    int num = 42;
    // intのアドレスをvoid*として渡す
    elem = ft_lstnew(&num);
    
    print_result("Node was created (not NULL)", elem != NULL);
    if (elem)
    {
        print_result("Content pointer is correct", elem->content == &num);
        print_result("Content value is correct", *(int *)elem->content == 42);
        print_result("Next pointer is NULL", elem->next == NULL);
        free(elem);
    }
    printf("\n");

    // --- テストケース3: contentがNULLの場合 ---
    printf("--- Test Case 3: Content is NULL ---\n");
    elem = ft_lstnew(NULL);
    
    print_result("Node was created (not NULL)", elem != NULL);
    if (elem)
    {
        print_result("Content pointer is NULL", elem->content == NULL);
        print_result("Next pointer is NULL", elem->next == NULL);
        free(elem);
    }
    
    return (0);
}
