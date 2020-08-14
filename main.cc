#include <iostream>
#include <fstream>
#include <string>
//TODO: Program flow...
//
// 1. Text input -> Function that creates/prints speech bubble'd text
// 2. Print image function called underneath to sync two together
// 3. ???
// 4. Profit!
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

void print_text(std::string line)
{
    //std::getline(std::cin, line);

    size_t size = line.size();
    //TODO: Add line char. limit, multi-line format rules
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < size+2; ++j)
        {
            if (i != 0 && i != 2 && j != 0 && j != size+1)
                std::cout << line.at(j-1);
            else if ((i == 1 && j == 0) || (i == 1 && j == size+1))
                std::cout << '|';
            else if ((i == 2 && j == 0) || (i == 0 && j == size+1))
                std::cout << '\\';
            else if ((i == 2 && j == size+1) || (i == 0 && j == 0))
                std::cout << '/';
            else
                std::cout << '-';
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) 
{
    std::string line = argv[1];
    print_text(line);
    load_image();
}
