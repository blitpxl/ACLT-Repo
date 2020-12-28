// ArchGen v0.2.9 (28/12/20) by Negated
// ArchGen is a fast file generator for generating large sized file.

// MIT License

// Copyright(c) 2020 Kevin Putra Satrianto

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <io.h>
#include <chrono>
#include "Archaio.h"

void initArchGen()
{
	std::cout << "                                             ArchGen v0.1.2 Initialized" << std::endl;

	while (true)
	{
		std::string fileSize;
		std::string outputPath;

		std::cout << " Enter output file size (in Kb): ";
		getline(std::cin, fileSize);

		std::cout << " Enter output directory (Drive Letter Only): ";
		getline(std::cin, outputPath);

		std::string outputPathFilename = outputPath + "ArchaioGeneratedFile.aio";

		std::stringstream fileSizeInt(fileSize);

		std::cout << " Output path: " + outputPathFilename << std::endl;
		std::cout << " Generating file, Please wait." << std::endl;

		int stdout_dupfd;
		FILE *temp_out;

		stdout_dupfd = _dup(1);

		temp_out = fopen(outputPathFilename.c_str(), "w");

		_dup2(_fileno(temp_out), 1);

		int x = 0;
		int threshold = 0;
		fileSizeInt >> threshold;

		auto t1 = std::chrono::high_resolution_clock::now();

		while (x < threshold)
		{
			std::cout << getUnit();
			x++;
		}

		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
		auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		fflush(stdout);
		fclose(temp_out);

		_dup2(stdout_dupfd, 1);
		_close(stdout_dupfd);

		std::cout << " Process Finished." << std::endl;
		std::cout << "" << std::endl;
		std::cout << " Time Taken: " << duration_s << "s" << " (" << duration_ms << ")" << "ms" << std::endl;

		break;

	}
}