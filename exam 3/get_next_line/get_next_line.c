#include "get_next_line.h"
#include "fcntl.h"
#include "unistd.h"

char    *get_next_line(int fd)
{
    int total = 0;
    int read_bites = 0;
    int cap = BUFFER_SIZE;
    char buff[BUFFER_SIZE + 1];
    char *stash;
    char *line;
    while((read_bites = read(fd, buff, cap)) > 0)
    {
        total += read_bites;
        if (read_bites == buff)
        {
            
            
        }
    }
    if (read_bites == -1)
    {
        return (NULL);
    }
    
}

int main(void)
{
    char *line;
    int fd = open("file.txt", O_RDONLY);
    while (line = get_next_line(fd))
    {
        printf("%s", line);
        free(line);
    }
    return (0);
}