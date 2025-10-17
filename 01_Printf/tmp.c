#include <stdio.h>    // printf, putchar のために必要
#include <stdarg.h>   // 可変長引数マクロのために必要

/* minprintf: 可変長引数リストを持つ最小限のprintf */
void minprintf(char *fmt, ...)
{
    va_list ap;     /* 可変長引数を順に指すポインタ */
    char *p, *sval;
    int ival;
    double dval;

    // apを最初の名前なし引数を指すように設定する
    va_start(ap, fmt);

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        // '%'の次の文字を評価する
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            // 文字列ポインタを取得し、1文字ずつ出力する
            for (sval = va_arg(ap, char *); *sval; sval++) {
                putchar(*sval);
            }
            break;
        default:
            // 対応していない変換文字は、そのまま出力する
            putchar(*p);
            break;
        }
    }

    // 終了時にクリーンアップ
    va_end(ap);
}

// 動作確認のためのmain関数
int main(void)
{
    minprintf("Hello, this is a minimal printf implementation.\n");
    minprintf("Integer: %d, Double: %f\n", 123, 456.789);
    minprintf("String: %s\n", "This is a test string.");
    minprintf("Unsupported specifier like %c is just printed.\n", 'X');
    return 0;
}
