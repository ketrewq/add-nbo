#include <stdio.h>
#include <stdint.h>

uint32_t read_nbo(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    uint32_t number;
    if (fread(&number, sizeof(uint32_t), 1, file) != 1) {
        perror("Error reading file");
        fclose(file);
        return 0;
    }

    fclose(file);
    return ntohl(number);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Syntax: add-nbo <file1> <file2>\n");
        return 1;
    }

    uint32_t num1 = read_nbo(argv[1]);
    uint32_t num2 = read_nbo(argv[2]);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",
           num1, num1, num2, num2, num1 + num2, num1 + num2);

    return 0;
}
