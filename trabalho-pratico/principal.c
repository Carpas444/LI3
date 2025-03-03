#include "include/appManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main (int argc , char ** argv) {
    if (argc != 3) {
        printf("Wrong Ammount of Arguments\n");
        return 1;
    }
    app_principal(argv);
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
    return 0;
}
