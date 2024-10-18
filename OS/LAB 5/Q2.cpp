#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process (Receiver)
        close(pipe_fd[1]); // Close write end of the pipe

        int output_file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (output_file == -1) {
            perror("Failed to create output file");
            return 1;
        }

        char buffer[256];
        ssize_t bytes_read;

        while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
            write(output_file, buffer, bytes_read);
        }

        close(pipe_fd[0]);  // Close read end of the pipe
        close(output_file); // Close output file
    } else {
        // Parent process (Sender)
        close(pipe_fd[0]); // Close read end of the pipe

        int input_file = open("input.txt", O_RDONLY);
        if (input_file == -1) {
            perror("Failed to open input file");
            return 1;
        }

        char buffer[256];

        ssize_t bytes_read;

        while ((bytes_read = read(input_file, buffer, sizeof(buffer))) > 0) {
            write(pipe_fd[1], buffer, bytes_read);
        }

        close(pipe_fd[1]); // Close write end of the pipe
        close(input_file); // Close input file

        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
