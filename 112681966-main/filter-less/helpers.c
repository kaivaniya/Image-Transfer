#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;
            float avg = round((red + blue + green) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg;
            //converting image into black and white by avraging rgb values

        }
    }
    return;
}




// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;


            float sep_red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            float sep_green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            float sep_blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (sep_red > 255)
            {
                sep_red = 255;
            }

            if(sep_green > 255)
            {
                sep_green = 255;
            }

            if(sep_blue > 255)
            {
                sep_blue = 255;
            }

            image[i][j].rgbtBlue = sep_blue;
            image[i][j].rgbtGreen = sep_green;
            image[i][j].rgbtRed = sep_red;

        }
    }
    return;
}




// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width / 2 ; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1) ];
            image[i][width - (j + 1) ] = temp;
        }
    }
    return;
}




// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i , j , cnt;
    RGBTRIPLE temp[height][width];
    for (i = 0 ; i < height ; i++)
    {
        for (j = 0 ; j < width ; j++)
        {
            temp[i][j] = image[i][j];
        }
    }




    for (i = 0 ; i < height ; i++)
    {
        for (j = 0 ; j < width ; j++)
        {


            float red_sum = image[i][j].rgbtRed ;
            float blue_sum = image[i][j].rgbtBlue ;
            float green_sum = image[i][j].rgbtGreen;

            cnt = 1;

            //counting for number of pixcells and also the sum of all three colours differently
            if (i + 1 < height && j >= 0)
            {
                red_sum = red_sum + image[i + 1][j].rgbtRed;
                blue_sum = blue_sum + image[i + 1][j].rgbtBlue;
                green_sum = green_sum + image[i + 1][j].rgbtGreen;
                cnt++;
            }

            if (i - 1 >= 0 && j >= 0)
            {
                red_sum = red_sum + image[i - 1][j].rgbtRed;
                blue_sum = blue_sum + image[i - 1][j].rgbtBlue;
                green_sum = green_sum + image[i - 1][j].rgbtGreen;
                cnt++;
            }

            if (i >= 0 && j + 1 < width)
            {
                red_sum = red_sum + image[i][j + 1].rgbtRed;
                blue_sum = blue_sum + image[i][j + 1].rgbtBlue;
                green_sum = green_sum + image[i][j + 1].rgbtGreen;
                cnt++;
            }

            if (i >= 0 && j - 1 >= 0)
            {
                red_sum = red_sum + image[i][j - 1].rgbtRed;
                blue_sum = blue_sum + image[i][j - 1].rgbtBlue;
                green_sum = green_sum + image[i][j - 1].rgbtGreen;
                cnt++;
            }

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red_sum = red_sum + image[i - 1][j - 1].rgbtRed;
                blue_sum = blue_sum + image[i - 1][j - 1].rgbtBlue;
                green_sum = green_sum + image[i - 1][j - 1].rgbtGreen;
                cnt++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                red_sum = red_sum + image[i + 1][j + 1].rgbtRed;
                blue_sum = blue_sum + image[i + 1][j + 1].rgbtBlue;
                green_sum = green_sum + image[i + 1][j + 1].rgbtGreen;
                cnt++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                red_sum = red_sum + image[i - 1][j + 1].rgbtRed;
                blue_sum = blue_sum + image[i - 1][j + 1].rgbtBlue;
                green_sum = green_sum + image[i - 1][j + 1].rgbtGreen;
                cnt++;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                red_sum = red_sum + image[i + 1][j - 1].rgbtRed;
                blue_sum = blue_sum + image[i + 1][j - 1].rgbtBlue;
                green_sum = green_sum + image[i + 1][j - 1].rgbtGreen;
                cnt++;
            }



            //calculating avrage
            float red_avg = round(red_sum / (float)cnt);
            float blue_avg = round(blue_sum / (float)cnt);
            float green_avg = round(green_sum / (float)cnt);


            temp[i][j].rgbtRed = red_avg;
            temp[i][j].rgbtBlue = blue_avg;
            temp[i][j].rgbtGreen = green_avg;
        }
    }

    for (i = 0 ; i < height ; i++)
    {
        for (j = 0 ; j < width ; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
