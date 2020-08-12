#include <iostream>
#include <fstream>
#include <string>

void load_image()
{
    std::string line; 
    std::ifstream img("image.txt");

    if (!img.is_open()) 
    {
        std::cout << "ERROR: File cannot be opened.\n";
        exit(1);
    }
    else
    {
        while (getline(img, line))
        {
            std::cout << line << '\n';
        }
        img.close();
    }
}

void print_text()
{
    std::string line;
    std::getline(std::cin, line);

    size_t size = line.size();
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < size+2; ++j)
        {
            if (i != 0 && i != 2 && j != 0 && j != size+1)
                std::cout << line.at(j-1);
            else
                std::cout << '@';
        }
        std::cout << std::endl;
    }
}

int main() 
{
    load_image();
    print_text();
}
