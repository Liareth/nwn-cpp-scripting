#include "Loader.hpp"
#include <string>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
    Loader::StartupArgs args;

    // The first param is always the file name.
    args.loaderPath = std::string{argv[0]};

    for (int i = 1; i < argc; ++i)
    {
        std::string currentArg{argv[i]};
        std::transform(currentArg.begin(), currentArg.end(), currentArg.begin(), tolower);

        if (argc > i + 1)
        {
            if (currentArg == "-dllname")
            {
                args.dllName = argv[++i];
            }
            else if (currentArg == "-filename")
            {
                args.fileName = argv[++i];
            }
            else if (currentArg == "-fileargs")
            {
                args.fileArgs = argv[++i];
            }
            else
            {
                std::cout << "Invalid argument:" << currentArg << std::endl;
                std::cout << R"(Valid arguments: -dllname "[name]" -filename "[name]" -fileargs "[args]")";
            }
        }
    }

    try
    {
        Loader::Loader loader{args};
    }
    catch (std::exception& ex)
    {
        std::cout << "Caught exception '" << ex.what() << "' while injecting." << std::endl;
        std::cout << "Press any key to exit." << std::endl;
        std::cin.get();
    }
}
