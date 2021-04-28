#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define CLEARFILE(X) fclose(fopen(X, "w"));

char *file_loading(char *path)
{
    struct stat f_stat;
    int buffsize;
    char *memory = malloc(sizeof(char));
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        memory[0] = '\0';
        return memory;
    }
    stat(path, &f_stat);
    buffsize = f_stat.st_size;
    memory = malloc(sizeof(char) * (buffsize + 1));
    read(fd, memory, buffsize);
    memory[buffsize] = '\0';
    close(fd);
    return (memory);
}

int main(int ac, char **av)
{
    char *memory = file_loading(av[1]);
    char delim[] = "\n";
    char *tab = strtok(memory, delim);

    for (; tab != NULL;) {
        if (tab[strlen(tab) - 1] == 'c')
            printf("\n//%s\n", tab);
        else if (tab[0] != '{')
            printf("%s;\n", tab);
        tab = strtok(NULL, delim);
    }
    (void)ac;
    return 0;
}