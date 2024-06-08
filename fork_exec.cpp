#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Error handling
        std::cerr << "Fork failed" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child process (PID: " << getpid() << ")" << std::endl;

        // Replace the child process image with a new program
        // Here, we're using `execlp` to run `/bin/ls`
        execlp("ls", "ls", "-l", NULL);

        // If exec() returns, it must have failed
        std::cerr << "Exec failed" << std::endl;
        return 1;
    } else {
        // Parent process
        std::cout << "Parent process (PID: " << getpid() << "), waiting for child process (PID: " << pid << ") to finish..." << std::endl;

        // Wait for the child process to complete
        wait(NULL);

        std::cout << "Child process finished." << std::endl;
    }

    return 0;
}
