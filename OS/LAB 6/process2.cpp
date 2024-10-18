#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "/tmp/myfifo";
    mkfifo(fifo_path, 0666);

    int fifo_fd = open(fifo_path, O_RDONLY);
    if (fifo_fd == -1) {
        perror("open");
        return 1;
    }

    while (true) {
        char buffer[100];
        ssize_t bytes_read = read(fifo_fd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            perror("read");
            break;
        }

        std::cout << "Process 2 (Receiver): " << buffer << std::endl;
    }

    close(fifo_fd);
    unlink(fifo_path); // Remove the FIFO file
    return 0;
}
