#include "ft_malloc.h"

int         main()
{
    char        *ret;
    char        str[] = "Hello world";
    size_t		len = 0;

    len = sizeof(char) * strlen(str) + 1;
    ret = (char*)ft_malloc(len);
    strcpy(ret, str);
    // printf("ret: %s\n", ret);
    munmap((void*)ret, len);
    ret = (char*)ft_malloc(len);
    strcpy(ret, str);
    munmap((void*)ret, len);
    ret = (char*)ft_malloc(len);
    strcpy(ret, str);
    munmap((void*)ret, len);
    ret = (char*)ft_malloc(len);
    strcpy(ret, str);
    munmap((void*)ret, len);
    return (0);
}