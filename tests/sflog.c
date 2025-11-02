#include "sflog/sflog.h"
int main() {
    sflog(info, "This is an info message.\n");
    sflog(debug, "This is a debug message.\n");
    sflog(success, "This is a success message.\n");
    sflog(warning, "This is a warning message.\n");
    sflog(error, "This is an error message.\n");
    sflog(critical, "This is a critical message.\n");
    return 0;
}