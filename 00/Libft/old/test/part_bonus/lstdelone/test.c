#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ft_lstdeloneに渡すための、contentを解放する関数
void    del_content(void *content)
{
    // contentはmallocで確保されたメモリを指していると仮定
    free(content);
}

int main(void)
{
    t_list *elem1;
    t_list *elem2;
    char   *content1;
    char   *content2;

    printf("========= Test Cases for lstdelone =========\n\n");

    // --- テストケース1: 通常の要素を解放 ---
    printf("--- Test Case 1: Deleting a normal element ---\n");
    
    // strdupはmallocでメモリを確保するので、解放対象として適切
    content1 = strdup("Hello");
    elem1 = ft_lstnew(content1);

    printf("Before deletion:\n");
    printf("elem1 pointer: %p\n", elem1);
    printf("content pointer: %p, value: \"%s\"\n", elem1->content, (char *)elem1->content);
    
    // ft_lstdeloneを呼び出して要素を解放
    ft_lstdelone(elem1, &del_content);
    
    printf("\nAfter deletion:\n");
    printf("The pointers above are now freed and should not be accessed.\n");
    printf("Check for memory leaks with valgrind.\n\n");

    // --- テストケース2: contentがNULLの要素を解放 ---
    // (ft_lstnewがcontentにNULLを許容する場合)
    printf("--- Test Case 2: Deleting an element with NULL content ---\n");
    elem2 = ft_lstnew(NULL);
    printf("Created an element with NULL content at address: %p\n", elem2);
    // del関数は何もしない（free(NULL)は安全）ので、del_contentをそのまま使える
    ft_lstdelone(elem2, &del_content);
    printf("Element with NULL content freed successfully.\n");
    printf("Check for memory leaks with valgrind.\n");

    return (0);
}
