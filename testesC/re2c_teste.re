#include <stdio.h>

static int lex(const char *YYCURSOR)
{
    const char *YYMARKER;
    /*!re2c
        re2c:define:YYCTYPE = char;
        re2c:yyfill:enable = 0;

        end = "\x00";
        hex = "0x" [0-9a-fA-F]+;

        *       { printf("err\n"); return 1; }
        hex end { printf("hex\n"); return 0; }
    */
}

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i) {
        lex(argv[i]);
    }
    return 0;
}
