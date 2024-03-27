// Program: Baby photoshop.
// Authors: Youssef Hassan Fahmy Ahmed, S17, 20230492 => Filter 2, 5
//          Ahmed Hussein Ahmed Mohammed, S17, 20230015 => 1, 4
//          Zyad Atef Al-Abiad, S17, 20231068 => 3

#include "Image_Class.h"
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        cout << "Choose the filter you want: " << endl;
        cout << "0. Exit\n1. Grayscale\n2. Black and White\n3. Invert Image\n4. Flip Image\n5. Rotate Image\n"
             << "=> ";
        string filterNumber;
        getline(cin, filterNumber);
        while (filterNumber.size() == 0 || filterNumber != "0" && filterNumber != "1" && filterNumber != "2" && filterNumber != "3" && filterNumber != "4" && filterNumber != "5")
        {
            cout << "Enter an integer from 0 to 5: ";
            filterNumber = "";
            getline(cin, filterNumber);
        }

        if (stoi(filterNumber))
        {
            cout << "Enter the name of the image you want to edit: ";
            string imageName;
            getline(cin, imageName);
            while (!imageName.size())
            {
                cout << "Empty input, enter the name of the image you want to edit: ";
                getline(cin, imageName);
            }

            string exe = "";

            for (short int i = 0; i < imageName.size(); i++)
            {
                if (imageName[i] == '.')
                {
                    for (short int j = i + 1; j < imageName.size(); j++)
                        exe += imageName[j];
                    break;
                }
            }

            while (!((exe == "jpg") || (exe == "jpeg") || (exe == "png") || (exe == "bmp")))
            {
                cout << "Import an image its extension is (jpg - jpeg - png - bmp): ";
                imageName = "";
                getline(cin, imageName);
                while (!imageName.size())
                {
                    cout << "Enter the name of the image you want to edit: ";
                    getline(cin, imageName);
                }

                exe = "";

                for (short int i = 0; i < imageName.size(); i++)
                {
                    if (imageName[i] == '.')
                    {
                        for (short int j = i + 1; j < imageName.size(); j++)
                            exe += imageName[j];
                        break;
                    }
                }
            }

            try
            {
                Image photo(imageName);
            }
            catch (invalid_argument)
            {
                cout << "Enter an existing image: ";
                getline(cin, imageName);
                while (!imageName.size())
                {
                    cout << "Enter the name of the image you want to edit: ";
                    cin.clear();
                    cin.ignore();
                    getline(cin, imageName);
                }
            }

            Image photo(imageName);

            cout << "Enter the name of the new image to save: ";
            string newImage;
            getline(cin, newImage);
            while (!newImage.size())
            {
                cin.clear();
                cin.ignore();
                cout << "Enter the name of the new image to save: ";
                getline(cin, newImage);
            }

            exe = "";

            for (short int i = 0; i < newImage.size(); i++)
            {
                if (newImage[i] == '.')
                {
                    for (short int j = i + 1; j < newImage.size(); j++)
                        exe += newImage[j];
                    break;
                }
            }

            while (!((exe == "jpg") || (exe == "jpeg") || (exe == "png") || (exe == "bmp")))
            {
                cout << "Import an image its extension is (jpg - jpeg - png - bmp): ";
                newImage = "";
                getline(cin, newImage);
                while (!newImage.size())
                {
                    cout << "Enter the name of the image you want to edit: ";
                    getline(cin, newImage);
                }

                exe = "";

                for (short int i = 0; i < newImage.size(); i++)
                {
                    if (newImage[i] == '.')
                    {
                        for (short int j = i + 1; j < newImage.size(); j++)
                            exe += newImage[j];
                        break;
                    }
                }
            }

            try
            {
                Image photo(newImage);
            }
            catch (invalid_argument)
            {
                cout << "Enter an existing image: ";
                getline(cin, newImage);
                while (!newImage.size())
                {
                    cout << "Enter the name of the image you want to edit: ";
                    cin.clear();
                    cin.ignore();
                    getline(cin, newImage);
                }
            }

            int progress = 0, temp2 = 0;
            double totalPixels = photo.height * photo.width * 0.01;

            // Grayscale.
            if (stoi(filterNumber) == 1)
            {
                for (short int i = 0; i < photo.height; i++)
                {
                    for (short int j = 0; j < photo.width; j++)
                    {
                        photo(j, i, 0) =
                            photo(j, i, 1) =
                                photo(j, i, 2) =
                                    ((photo(j, i, 0) + photo(j, i, 1) + photo(j, i, 2)) / 3);
                        int temp = (++progress / totalPixels);
                        if (temp != temp2)
                            cout << '\r' << temp << '%';
                        temp2 = (progress / totalPixels);
                    }
                }
                photo.saveImage(newImage);
            }
            // Black and White.
            else if (stoi(filterNumber) == 2)
            {
                for (short int i = 0; i < photo.height; i++)
                {
                    for (short int j = 0; j < photo.width; j++)
                    {
                        photo(j, i, 0) =
                            photo(j, i, 1) =
                                photo(j, i, 2) =
                                    ((photo(j, i, 0) + photo(j, i, 1) + photo(j, i, 2)) / 3 > (255 / 2) ? 255 : 0);
                        int temp = (++progress / totalPixels);
                        if (temp != temp2)
                            cout << '\r' << temp << '%';
                        temp2 = (progress / totalPixels);
                    }
                }
                photo.saveImage(newImage);
            }
            // Invert Image.
            else if (stoi(filterNumber) == 3)
            {
                for (short int i = 0; i < photo.height; i++)
                {
                    for (short int j = 0; j < photo.width; j++)
                    {
                        for (short int k = 0; k < photo.channels; k++)
                            photo(j, i, k) = 255 - photo(j, i, k);
                        int temp = (++progress / totalPixels);
                        if (temp != temp2)
                            cout << '\r' << temp << '%';
                        temp2 = (progress / totalPixels);
                    }
                }
                photo.saveImage(newImage);
            }
            // Flip Image.
            else if (stoi(filterNumber) == 4)
            {
                cout << "Enter the direction of flip (V - H): ";
                char flipDir;
                cin >> flipDir;
                if (toupper(flipDir) == 'V')
                {
                    for (short int i = 0; i < photo.height / 2; i++)
                    {
                        for (short int j = 0; j < photo.width; j++)
                        {
                            for (short int h = 0; h < photo.channels; h++)
                                swap(photo(j, i, h), photo(j, photo.height - i - 1, h));
                            int temp = (++progress / (totalPixels * 0.5));
                            if (temp != temp2)
                                cout << '\r' << temp << '%';
                            temp2 = (progress / (totalPixels * 0.5));
                        }
                    }
                }
                else if (toupper(flipDir) == 'H')
                {
                    for (short int i = 0; i < photo.height; i++)
                    {
                        for (short int j = 0; j < photo.width / 2; j++)
                        {
                            for (short int h = 0; h < photo.channels; h++)
                                swap(photo(j, i, h), photo(photo.width - j - 1, i, h));
                            int temp = (++progress / (totalPixels * 0.5));
                            if (temp != temp2)
                                cout << '\r' << temp << '%';
                            temp2 = (progress / (totalPixels * 0.5));
                        }
                    }
                }
                photo.saveImage(newImage);
            }
            // Rotate Image.
            else if (stoi(filterNumber) == 5)
            {
                cout << "Choose the angle of rotation clockwise:\n1. 90\n2. 180\n3. 270" << endl
                     << "=> ";
                short int rotationAngle;
                cin >> rotationAngle;
                while (!cin || rotationAngle < 1 || rotationAngle > 3)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Enter an integer of (1 - 2 - 3): ";
                    cin.clear();
                    cin.ignore();
                    cin >> rotationAngle;
                }

                Image rotatedImage(imageName);

                if (rotationAngle == 2)
                {
                    rotatedImage.height = photo.height;
                    rotatedImage.width = photo.width;
                }
                else
                {
                    rotatedImage.width = photo.height;
                    rotatedImage.height = photo.width;
                }

                if (rotationAngle == 2)
                {
                    for (short int x = 0; x < rotatedImage.height; x++)
                    {
                        for (short int y = 0; y < rotatedImage.width; y++)
                        {
                            for (short int h = 0; h < rotatedImage.channels; h++)
                                rotatedImage(y, x, h) = photo(y, photo.height - x - 1, h);
                            int temp = (++progress / totalPixels);
                            if (temp != temp2)
                                cout << '\r' << temp << '%';
                            temp2 = (progress / totalPixels);
                        }
                    }
                    for (short int x = 0; x < rotatedImage.height; x++)
                        for (short int y = 0; y < rotatedImage.width / 2; y++)
                            for (short int h = 0; h < rotatedImage.channels; h++)
                                swap(rotatedImage(y, x, h), rotatedImage(photo.width - y - 1, x, h));
                }
                else
                {
                    for (short int x = 0; x < rotatedImage.height; x++)
                    {
                        for (short int y = 0; y < rotatedImage.width; y++)
                        {
                            for (short int h = 0; h < rotatedImage.channels; h++)
                                rotatedImage(y, x, h) = photo(x, y, h);
                            int temp = (++progress / totalPixels);
                            if (temp != temp2)
                                cout << '\r' << temp << '%';
                            temp2 = (progress / totalPixels);
                        }
                    }
                    for (short int x = 0; x < rotatedImage.height; x++)
                        for (short int y = 0; y < rotatedImage.width / 2; y++)
                            for (short int h = 0; h < rotatedImage.channels; h++)
                                swap(rotatedImage(y, x, h), rotatedImage(rotatedImage.width - y - 1, x, h));
                    if (rotationAngle == 3)
                    {
                        for (short int x = 0; x < rotatedImage.height / 2; x++)
                            for (short int y = 0; y < rotatedImage.width; y++)
                                for (short int h = 0; h < rotatedImage.channels; h++)
                                    swap(rotatedImage(y, x, h), rotatedImage(y, rotatedImage.height - x - 1, h));
                        for (short int x = 0; x < rotatedImage.height; x++)
                            for (short int y = 0; y < rotatedImage.width / 2; y++)
                                for (short int h = 0; h < rotatedImage.channels; h++)
                                    swap(rotatedImage(y, x, h), rotatedImage(rotatedImage.width - y - 1, x, h));
                    }
                }
                rotatedImage.saveImage(newImage);
            }
        }
        else
        {
            exit(0);
        }
        cout << endl;
        cin.clear();
    }
    return 0;
}