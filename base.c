#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>

typedef struct {
    char *message;
} Exception;

#define try(x, y) do { jmp_buf c; Exception exception; if (setjmp(c) != 0) { y; break; }; x; } while (0)
#define throw(e) exception = e; longjmp(c, 1);

int main() {
    try({
        printf("Try..\n");
        
        throw((Exception) {"Hello world"});
    }, {
        printf("Catch: %s\n", exception.message);
    });
    
    return 0;
}
