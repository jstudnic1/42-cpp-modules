#include "Harl.hpp"

int get_level_index(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
        std::cerr << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    int index = get_level_index(level);
    if (index == -1) {
        std::cerr << "Invalid level: " << level << std::endl;
        return 1;
    }

    Harl harl;

    switch (index) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cerr << "Invalid level: " << level << std::endl;
            return 1;
    }
}
