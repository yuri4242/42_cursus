#include <stdio.h> // printf を使うために必要

int main(void)
{
    int i = 123;
    double d = 456.789;
    char *s = "Hello";
    char c = 'A'; // 'A' のASCIIコードは 65

    printf("--- 型と引数が正しい場合 (比較用) ---\n");
    printf("int (%%d):     %d\n", i);
    printf("double (%%f):   %f\n", d);
    printf("string (%%s):   %s\n", s);
    printf("char (%%c):     %c\n", c);

    printf("\n--- 型と引数がミスマッチな場合 (未定義動作) ---\n");

    // 1. int型 (i) を double (%%f) として表示しようとする
    // 期待: 123.000000 -> 実際: 0.000000 やゴミのような値
    printf("%%f に int を渡す:    %f\n", i);

    // 2. double型 (d) を int (%%d) として表示しようとする
    // 期待: 456 -> 実際: 0 や巨大な負の数など、全く異なる値
    printf("%%d に double を渡す: %d\n", d);

    // 3. char* (s) を int (%%d) として表示しようとする
    // 期待: (表示不可) -> 実際: ポインタのアドレス値 (環境による)
    printf("%%d に char* を渡す:  %d\n", s);
    
    // 4. int (i) を char* (%%s) として表示しようとする
    // 期待: (表示不可) -> 実際: 123 をアドレスと解釈しようとしてクラッシュ (Segmentation fault) する可能性が高い
    printf("%%s に int を渡す:    %s\n", i);
    
    // 5. char (c) を int (%%d) として表示
    // (補足) これは例外的に「うまくいく」ことが多い
    // なぜなら、char は int に「格上げ」(Integer Promotion) されてから渡されるため
    printf("%%d に char を渡す:   %d\n", c); // 65 が表示されるはず

    printf("\n--- 確認終わり ---\n");
    
    return 0;
}
