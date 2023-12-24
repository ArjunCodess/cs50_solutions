#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // looping through the height
    for (int i = 0; i < height; i++)
    {
        // looping through the width
        for (int j = 0; j < width; j++)
        {
            // if black pixel found - replace it with a blue pixel
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtBlue = 0xff;
            }
        }
    }
}
