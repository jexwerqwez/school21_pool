#include "logger.h"
#define SIZE 256

void printfile(const char* filename);
void encrypt(FILE *fp, int key);
void clear_header(FILE *fp);

int main() {
    char filename[SIZE];
    char text[SIZE];
    FILE* fp, *fp1, *fp2, *fp3, *fp4;
    #ifdef LOGGER_LIB
    FILE* logfp, *logfp1, *logfp2, *logfp3, *logfp4;
    #endif
    int mode = 0;
    int exit_flag = 1;
    char ch;
    int key = 0;
    while (exit_flag) {
        scanf("%d", &mode);
        if (mode == 1) {
            scanf("%s", filename);
            #ifdef LOGGER_LIB
            logfp = log_init(filename);
            #endif
            if ((fp = fopen(filename, "r")) == NULL) {
                printf("n/a\n");
                #ifdef LOGGER_LIB
                logcat(logfp, "Невозможно открыть файл", 4);
                #endif
                continue;
            }
            #ifdef LOGGER_LIB
            logcat(logfp, "открыт", 2);
            log_close(logfp);
            #endif
            fclose(fp);
            printfile(filename);
        } else if (mode == 2) {
            #ifdef LOGGER_LIB
            logfp = log_init(filename);
            #endif
            if ((fp = fopen(filename, "r")) == NULL) {
                printf("n/a\n");
                #ifdef LOGGER_LIB
                logcat(logfp, "Невозможно открыть файл", 4);
                #endif
                if (scanf("%s", text) != 1) {
                    #ifdef LOGGER_LIB
                    logcat(logfp, "Ошибка записи в файл", 3);
                    #endif
                }
                printf("%s\n", text);
                fclose(fp);
                continue;
            } else {
                fp = fopen(filename, "a");
                while ((ch = getchar()) != '\n')
                    fputc(ch, fp);
                #ifdef LOGGER_LIB
                logcat(logfp, "Файл дописан", 0);
                #endif
            }
            #ifdef LOGGER_LIB
            logcat(logfp, "Файл закрыт", 2);
            log_close(logfp);
            #endif
            fclose(fp);
            printfile(filename);
        } else if (mode == 3) {
            #ifdef LOGGER_LIB
            logfp1 = log_init("ai_modules/m1.c");
            logfp2 = log_init("ai_modules/m1.h");
            logfp3 = log_init("ai_modules/m2.c");
            logfp4 = log_init("ai_modules/m2.h");
            #endif
            if ((fp1 = fopen("ai_modules/m1.c", "r+")) == NULL) {
                #ifdef LOGGER_LIB
                logcat(logfp1, "Невозможно открыть файл", 4);
                #endif
                printf("n/a\n");
                continue;
            } else if ((fp2 = fopen("ai_modules/m2.c", "r+")) == NULL) {
                #ifdef LOGGER_LIB
                logcat(logfp2, "Невозможно открыть файл", 4);
                #endif
                printf("n/a\n");
                continue;
            } else if ((fp3 = fopen("ai_modules/m1.h", "w")) == NULL) {
                #ifdef LOGGER_LIB
                logcat(logfp3, "Невозможно открыть файл", 4);
                #endif
                printf("n/a\n");
                continue;
            } else if ((fp4 = fopen("ai_modules/m2.h", "w")) == NULL) {
                #ifdef LOGGER_LIB
                logcat(logfp4, "Невозможно открыть файл", 4);
                #endif
                printf("n/a\n");
                continue;
            } else {
                if (scanf("%d", &key) != 1) {
                    #ifdef LOGGER_LIB
                    logcat(logfp, "Ошибка установки ключа", 3);
                    #endif
                    continue;
                } else {
                    encrypt(fp1, key);
                    encrypt(fp2, key);
                    clear_header(fp3);
                    clear_header(fp4);
                    #ifdef LOGGER_LIB
                    logcat(logfp1, "Файл зашифрован", 0);
                    logcat(logfp2, "Файл зашифрован", 0);
                    logcat(logfp3, "Файл очищен", 0);
                    logcat(logfp4, "Файл очищен", 0);
                    #endif
                }
            }
            #ifdef LOGGER_LIB
            log_close(logfp1);
            log_close(logfp2);
            log_close(logfp3);
            log_close(logfp4);
            #endif
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
            fclose(fp4);
        }
        if (mode == -1 || (mode != 1 && mode != 2 && mode != 3)) {
            exit_flag = 0;
        }
    }
    return 0;
}

void printfile(const char* filename) {
    int ch;
    FILE *fp = fopen(filename, "r");
    while (!feof(fp) && !ferror(fp)) {
        ch = getc(fp);
        if (ch != EOF) {
            putchar(ch);
        }
    }
    putchar('\n');
}

void encrypt(FILE *fp, int key) {
    int size;
    int pos = 0;
    int i = 0;
    unsigned char ch, res;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    while (pos < (size)) {
        fseek(fp, pos * sizeof(ch), SEEK_SET);
        ch = fgetc(fp);
        res = ch + key;
        fputc(res, fp);
        pos++;
    }
    fseek(fp, 0, SEEK_SET);
    while (i < size) {
        fputc('\0', fp);
        i++;
    }
}

void clear_header(FILE *fp) {
    int size;
    int pos = 0;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    while (pos < size) {
        fputc('\0', fp);
        pos++;
    }
}
