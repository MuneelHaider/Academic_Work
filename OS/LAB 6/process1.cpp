#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "/tmp/myfifo";
    mkfifo(fifo_path, 0666);

    int fifo_fd = open(fifo_path, O_WRONLY);
    if (fifo_fd == -1) {
        perror("open");
        return 1;
    }

    while (true) {
        std::cout << "Process 1 (Sender): ";
        std::string message;
        std::getline(std::cin, message);

        write(fifo_fd, message.c_str(), message.size() + 1);
    }

    close(fifo_fd);
    unlink(fifo_path); // Remove the FIFO file
    return 0;
}
