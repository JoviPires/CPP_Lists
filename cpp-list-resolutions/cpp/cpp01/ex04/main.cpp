#include <iostream>
#include <fstream>
#include <string>

static std::string ft_strreplace(const std::string &str, const std::string &s1, const std::string &s2)
{
    std::string result = str;
    std::string::size_type pos = 0;
    std::string::size_type found;
    while (1)
    {
        found = str.find(s1, pos);
        if (found == std::string::npos)
        {
            result += str.substr(pos);
            break ;
        }
        result += str.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return (1);
    }
    std::ifstream input(filename.c_str());
    if (!input.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return (1);
    }
    std::string str;
    std::string line;
    while (std::getline(input, line))
    {
        str += line;
        if (!input.eof())
            str += "\n";
    }
    input.close();
    std::string result = ft_strreplace(str, s1, s2);
    std::ofstream output((filename + ".replace").c_str());
    if (!output.is_open())
    {
        std::cerr << "Error: Could not create output file " << filename << ".replace" << std::endl;
        return (1);
    }
    output << result;
    output.close();
    return (0);
}