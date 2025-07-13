#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    int max_iterations = 5;

    // Parse command-line argument
    if (argc >= 2) {
        max_iterations = std::atoi(argv[1]);
        if (max_iterations <= 0 || max_iterations > 20)
            max_iterations = 10;
    }

    // Fork the current process
    pid = fork();

    if (pid < 0) {
        std::cerr << "Fork error\n";
        return 1;
    }

    if (pid == 0) {
        // Child process

        // Open file for daemon logging
        std::ofstream logfile("DAEMON.txt", std::ios::out | std::ios::trunc);
        if (!logfile) {
            std::cerr << "Failed to open log file\n";
            return 1;
        }

        std::cout << "Child: pid is " << getpid() << " and ppid is " << getppid() << "\n";
        std::cout << "\nChild process before becoming session leader\n";

        // Show process status before setsid
        std::stringstream cmd_before;
        cmd_before << "ps -ef | grep " << argv[0];
        system(cmd_before.str().c_str());

        // Detach from terminal and become session leader
        setsid();

        std::cout << "\nChild process after becoming session leader\n";
        std::stringstream cmd_after;
        cmd_after << "ps -ef | grep " << argv[0];
        system(cmd_after.str().c_str());

        // Close standard file descriptors
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        // Logging loop
        for (int counter = 0; counter < max_iterations; ++counter) {
            logfile << "Daemon process: pid is " << getpid()
                    << " and ppid is " << getppid() << std::endl;
            logfile.flush();
            sleep(2);
        }

        logfile << "Done" << std::endl;
        logfile.close();

    } else {
        // Parent process
        std::cout << "Parent: pid is " << getpid() << " and ppid is " << getppid() << "\n";
        std::cout << "Parent: Exiting\n";
        exit(0);
    }

    return 0;
}
