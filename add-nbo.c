#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    FILE* file1 = fopen(argv[1], "rb");
    if (file1 == NULL) {
        printf("첫 번째 파일을 열 수 없습니다.\n");
        return 1;
    }

    FILE* file2 = fopen(argv[2], "rb");
    if (file2 == NULL) {
        printf("두 번째 파일을 열 수 없습니다.\n");
        fclose(file1);
        return 1;
    }

    uint32_t number1;
    if (fread(&number1, sizeof(uint32_t), 1, file1) != 1) {
        printf("첫 번째 파일에서 숫자를 읽을 수 없습니다.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }
    number1 = ntohl(number1);

    uint32_t number2;
    if (fread(&number2, sizeof(uint32_t), 1, file2) != 1) {
        printf("두 번째 파일에서 숫자를 읽을 수 없습니다.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }
    number2 = ntohl(number2);

    fclose(file1);
    fclose(file2);

    uint32_t sum = number1 + number2;
    printf("두 숫자의 합:%u (0x%x) + %u (0x%x) =  %u (0x%x)\n", number1,number1,number2, number2,  sum, sum);

    return 0;
}

