#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BUFFER_SIZE 100

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./filestat <file_path>\n");
        return 1;
    }
    printf("File name: %s \n", argv[1]);

    struct stat filestat;

    const char *pathname = argv[1];
    int fd = open(pathname, O_CREAT | O_RDONLY);
    
    if (fd == -1) {
        printf("open error");
        return 1;
    } else {
        if (lstat(pathname, &filestat) == - 1) {
            printf("lstat error \n");
        }

        if (S_ISREG(filestat.st_mode))
            printf("Regular File \n");
        else if (S_ISDIR(filestat.st_mode))
            printf("Directory \n");
        else if (S_ISLNK(filestat.st_mode))
            printf("Symbolic Link \n");
        else
            printf("Other \n");

        printf("Size: %ld bytes\n", filestat.st_size);

        char buffer[BUFFER_SIZE];
        struct tm *time_last_modify;
        
        time_last_modify = localtime(&filestat.st_mtime);
        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", time_last_modify);

        printf("%s", buffer);
    }
    
    return 0;
}