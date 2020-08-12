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
    
}

int main() 
{
    load_image();
    print_text();
}
