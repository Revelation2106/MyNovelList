#pragma once

#include <fstream>
#include <sstream>

namespace MyNovelList {

	void EncryptToFile(std::stringstream& dataStream, const std::string& filename)
	{
		char c;
		std::ofstream out;

		out.open(filename, std::ios::binary);

		while (dataStream)
		{
			dataStream >> std::noskipws >> c;
			int temp = c + 42;
			out << (char)temp;
		}

		out.close();
	}

	std::stringstream DecryptFromFile(const std::string& filename)
	{
		char c;
		std::ifstream in;
		std::stringstream out;

		in.open(filename, std::ios::binary);
		// If file is empty, exit early if it is
		if (in.get(), in.eof())
		{
			in.close();
			return out;
		}

		// Read and decrypt data
		in.clear();
		in.seekg(0);

		while (in)
		{
			in >> std::noskipws >> c;
			int temp = c - 42;
			out << (char)temp;
		}

		in.close();

		return out;
	}

}