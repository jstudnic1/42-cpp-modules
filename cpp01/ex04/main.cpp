#include "replacer.hpp"


bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	// Input validation
	if (filename.empty() || s1.empty())
	{
		std::cerr << "Error: filename and search string cannot be empty" << std::endl;
		return false;
	}

	// Open input file
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "Error: Could not open input file: " << filename << std::endl;
		return false;
	}

	// Check if file is empty
	inFile.seekg(0, std::ios::end);
	if (inFile.tellg() == 0)
	{
		std::cerr << "Error: File is empty: " << filename << std::endl;
		inFile.close();
		return false;
	}
	inFile.seekg(0, std::ios::beg);

	// Read entire file content
	std::string buffer;
	std::getline(inFile, buffer, '\0');
	inFile.close();

	// Check if s1 exists in the file
	if (buffer.find(s1) == std::string::npos)
	{
		std::cerr << "Warning: String '" << s1 << "' not found in the file" << std::endl;
		return false;
	}

	// Create output filename
	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename);
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not create output file: " << outFilename << std::endl;
		return false;
	}

	// Perform replacements
	size_t pos = 0;
	size_t replacements = 0;
	while ((pos = buffer.find(s1, pos)) != std::string::npos)
	{
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos += s2.length();
		replacements++;
	}

	// Write modified content to output file
	outFile << buffer;
	outFile.close();

	std::cout << "Successfully created " << outFilename << std::endl;
	std::cout << "Replaced " << replacements << " occurrence(s) of '" << s1 << "' with '" << s2 << "'" << std::endl;
	return true;
}

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	if (!replaceInFile(av[1], av[2], av[3]))
		return 1;

	return 0;
}
