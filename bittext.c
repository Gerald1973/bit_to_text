#include <stdio.h>
#include <stdint.h>

char tmp_binary[9];
int counter_line = 0;

/**
 * @brief Convert a byte to a binary string.
 * 
 * @param bytes 
 * @param result 
 */
void write_binary(uint8_t byte, char *result)
{
    uint8_t tmp = byte;
    for (int i = 0; i < 8; i++)
    {
        if (tmp % 2 == 0)
        {
            result[7 - i] = '.';
        }
        else
        {
            result[7 - i] = '*';
        }
        tmp = tmp >> 1;
    }
}

void print_buffer(uint8_t *buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%04x %05d %03d %02x ", counter_line, counter_line, buffer[i], buffer[i]);
        write_binary(buffer[i], tmp_binary);
        printf("%s\n", tmp_binary);
        counter_line++;
        if (counter_line % 8 == 0)
        {
            printf("\n");
        }
    }
}

void print_buffer_for_c(uint8_t *buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", buffer[i]);
    }
    printf("\n");
}

void read_bin_file(char *fileName, int dir)
{
    static const int BUFFER_SIZE = 8;
    int read_bytes = 0;
    int i;
    FILE *file;
    uint8_t buffer[BUFFER_SIZE];
    file = fopen(fileName, "rb");
    if (file)
    {
        while ((read_bytes = fread(buffer, 1, BUFFER_SIZE, file)) == BUFFER_SIZE)
        {
            dir==0?print_buffer(buffer, read_bytes):print_buffer_for_c(buffer, read_bytes);
        };
        if (read_bin_file > 0)
        {
            dir==0?print_buffer(buffer, read_bytes):print_buffer_for_c(buffer, read_bytes);
        }
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    int result = 0;
    if (argc != 2)
    {
        printf("Wrong number of arguments.\n");
        printf("example:\n");
        printf("bittext my_file.bin\n");
        result = 1;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            tmp_binary[i] = '0';
        }
        tmp_binary[8] = 0;
        printf("File to parse: %s\n", argv[1]);
        read_bin_file(argv[1],0);
        read_bin_file(argv[1],1);
    }
    return result;
}