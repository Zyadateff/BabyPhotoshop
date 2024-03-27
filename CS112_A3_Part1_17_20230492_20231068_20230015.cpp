// Program: Baby photoshop.
// Authors: Youssef Hassan Fahmy Ahmed, S17, 20230492 => Filter 2, 5, 8, 11
//          Ahmed Hussein Ahmed Mohammed, S17, 20230015 => 1, 4, 7, 10
//          Zyad Atef Al-Abiad, S17, 20231068 => 3, 6, 9, 12

#include "Image_Class.h"
using namespace std;

int main()
{
    while (true)
    {
        cout << "Choose the filter you want: " << endl;
        cout << "0.  Exit\n1.  Grayscale\n2.  Black and White\n3.  Invert Image\n4.  Merge Images\n5.  Flip Image\n6.  Rotate Image\n7.  Darken and Lighten Image\n8.  Crop Images\n9.  Adding a Frame to the Picture\n10. Detect Image Edges\n11. Resize Images\n12. Blur Images\n => ";
        short int filterNumber;
        cin >> filterNumber;
        while (!cin || filterNumber < 0 || filterNumber > 12)
        {
            cin.clear();
            cin.ignore();
            cout << "Enter an integer from 0 to 12: ";
            cin.clear();
            cin.ignore();
            cin >> filterNumber;
        }

        if (filterNumber)
        {
            cin.clear();
            cin.ignore();
            cout << "Enter the name of the image you want to edit: ";
            string imageName;
            getline(cin, imageName);
            while (!imageName.size())
            {
                cout << "Enter the name of the image you want to edit: ";
                getline(cin, imageName);
            }

            Image photo(imageName);

            cout << "Enter the name of the new image to save: ";
            string newImage;
            getline(cin, newImage);
            while (!newImage.size())
            {
                cout << "Enter the name of the new image to save: ";
                getline(cin, newImage);
            }

            // Grayscale.
            if (filterNumber == 1)
            {
                for (short int i = 0; i < photo.height; i++)
                    for (short int j = 0; j < photo.width; j++)
                        photo(j, i, 0) = photo(j, i, 1) = photo(j, i, 2) = ((photo(j, i, 0) + photo(j, i, 1) + photo(j, i, 2)) / 3);
                photo.saveImage(newImage);
            }
            // Black and White.
            else if (filterNumber == 2)
            {
                for (short int i = 0; i < photo.height; i++)
                    for (short int j = 0; j < photo.width; j++)
                        photo(j, i, 0) = photo(j, i, 1) = photo(j, i, 2) = ((photo(j, i, 0) + photo(j, i, 1) + photo(j, i, 2)) / 3 > (255 / 2) ? 255 : 0);
                photo.saveImage(newImage);
            }
            // Invert Image.
            else if (filterNumber == 3)
            {
                cout << "Coming soon!" << endl;
            }
            // Merge Images.
            else if (filterNumber == 4)
            {
                cout << "Coming soon!" << endl;
            }
            // Flip Image.
            else if (filterNumber == 5)
            {
                cout << "Enter the direction of flip (V - H): ";
                char flipDir;
                cin >> flipDir;
                if (toupper(flipDir) == 'H')
                    for (short int i = 0; i < photo.height / 2; i++)
                        for (short int j = 0; j < photo.width; j++)
                            for (short int h = 0; h < 3; h++)
                                swap(photo(i, j, h), photo(photo.height - i - 1, j, h));
                else if (toupper(flipDir) == 'V')
                    for (short int i = 0; i < photo.height; i++)
                        for (short int j = 0; j < photo.width / 2; j++)
                            for (short int h = 0; h < 3; h++)
                                swap(photo(i, j, h), photo(i, photo.height - j - 1, h));
                photo.saveImage(newImage);
            }
            // Rotate Image.
            else if (filterNumber == 6)
            {
                cout << "Coming soon!" << endl;
            }
            // Darken and Lighten Image.
            else if (filterNumber == 7)
            {
                cout << "1. Darken\n2. Lighten" << endl;
                short int value;
                cin >> value;
                while (!cin || value < 1 || value > 2)
                {
                    cout << "Enter (1 or 2): ";
                    cin >> value;
                }
                cout << "How much (%)? \"Without \'%\'\": ";
                float perc;
                cin >> perc;
                while (!cin || perc < 0)
                {
                    cout << "Enter a non-negative number: ";
                    cin >> perc;
                }
                for (short int i = 0; i < photo.height; i++)
                {
                    for (short int j = 0; j < photo.width; j++)
                    {
                        for (short int k = 0; k < 3; k++)
                        {
                            if (photo(j, i, k) * (perc / 100) > 255)
                                photo(j, i, k) = 255;
                            else if (photo(j, i, k) * (perc / 100) < 0)
                                photo(j, i, k) = 0;
                            else
                                photo(j, i, k) = photo(j, i, k) * (perc / 100);
                        }
                    }
                }
                photo.saveImage(newImage);
            }
            // Crop Image.
            else if (filterNumber == 8)
            {
                cout << "Enter the starting dimension of the croped photo (in order): ";
                short int x, y;
                cin >> x >> y;
                cout << "Enter the width and the height of the croped photo (in order): ";
                short int h, w;
                cin >> w >> h;
                Image cropedPhoto(w, h);
                for (short int i = 0; i < h; i++)
                    for (short int j = 0; j < w; j++)
                        for (short int k = 0; k < 3; k++)
                            cropedPhoto(j, i, k) = photo(j + y, i + x, k);
                cropedPhoto.saveImage(newImage);
            }
            // Adding a Frame to the Picture.
            else if (filterNumber == 9)
            {
                cout << "Coming soon!" << endl;
            }
            // Detect Image Edges.
            else if (filterNumber == 10)
            {
                cout << "Coming soon!" << endl;
            }
            // Resize Images.
            else if (filterNumber == 11)
            {
                cout << "Enter width and height of the new photo (in order): ";
                float h, w;
                cin >> w >> h;
                Image resizedPhoto(w, h);
                float n = 0;
                for (short int i = 0; i < h; i++)
                {
                    float m = 0;
                    for (short int j = 0; j < w; j++)
                    {
                        for (short int k = 0; k < 3; k++)
                            resizedPhoto(j, i, k) = photo(m, n, k);
                        m += (float)photo.width / w;
                    }
                    n += (float)photo.height / h;
                }
                resizedPhoto.saveImage(newImage);
            }
            // blur.
            else if (filterNumber == 12)
            {
                cout << "Enter the power of blur: ";
                short int blur;
                cin >> blur;
                for (short int i = 0; i < photo.width; i++)
                {
                    for (short int j = 0; j < photo.height; j++)
                    {
                        int avgR = 0, avgG = 0, avgB = 0, counter = 0;
                        for (short int h = -blur; h <= blur; h++)
                        {
                            short int xIndex = i + h;
                            if (xIndex >= 0 && xIndex < photo.width)
                            {
                                avgR += photo(xIndex, j, 0);
                                avgG += photo(xIndex, j, 1);
                                avgB += photo(xIndex, j, 2);
                                counter++;
                            }
                        }
                        photo(i, j, 0) = avgR / counter;
                        photo(i, j, 1) = avgG / counter;
                        photo(i, j, 2) = avgB / counter;
                    }
                }

                for (short int i = 0; i < photo.width; i++)
                {
                    for (short int j = 0; j < photo.height; j++)
                    {
                        int avgR = 0, avgG = 0, avgB = 0, counter = 0;
                        for (short int h = -blur; h <= blur; h++)
                        {
                            short int yIndex = j + h;
                            if (yIndex >= 0 && yIndex < photo.height)
                            {
                                avgR += photo(i, yIndex, 0);
                                avgG += photo(i, yIndex, 1);
                                avgB += photo(i, yIndex, 2);
                                counter++;
                            }
                        }
                        photo(i, j, 0) = avgR / counter;
                        photo(i, j, 1) = avgG / counter;
                        photo(i, j, 2) = avgB / counter;
                    }
                }

                photo.saveImage(newImage);
            }
        }
        else
        {
            exit(0);
        }
        cin.clear();
    }
    return 0;
}