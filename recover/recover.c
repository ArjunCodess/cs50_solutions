#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Can't open file: %s\n", argv[1]);
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];

    int jpegCount = 0;

    FILE *jpegFile = NULL;

    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpegFile != NULL)
            {
                fclose(jpegFile);
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", jpegCount);
            jpegFile = fopen(filename, "w");

            if (jpegFile == NULL)
            {
                fprintf(stderr, "Could not create JPEG file: %s\n", filename);
                return 1;
            }

            jpegCount++;
        }

        if (jpegFile != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, jpegFile);
        }
    }

    if (jpegFile != NULL)
    {
        fclose(jpegFile);
    }

    fclose(file);
    return 0;
}
