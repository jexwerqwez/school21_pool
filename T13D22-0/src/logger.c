#include "logger.h"

FILE* log_init(char *filename) {
    char logname[SIZE];
    snprintf(logname, sizeof logname, "%s%s", "log_", filename);
    FILE* logfp = fopen(logname, "a+");
    return logfp;
}

int logcat(FILE* log_file, char *message, log_level level) {
    long int ttime;
    ttime = time(NULL);
    char lvl[][10] = { "DEBUG", "TRACE", "INFO", "WARNING", "ERROR" };
    fprintf(log_file, "%s %s %s", lvl[level], message, ctime(&ttime));
    return 0;
}

int log_close(FILE* log_file) {
    logcat(log_file, "Файл закрыт", 2);
    fclose(log_file);
    return 0;
}
