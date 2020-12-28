// Archaio Command Line Tool v0.1.7 (28/12/20)

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

#include <iostream>
#include <string>
#include "Archaio.h"


void showHeaderText()
{
	std::cout << "                           =============================================================" << std::endl;
	std::cout << "                           Archaio Command Line Tool v0.1.5 by Kevin Putra a.k.a Negated" << std::endl;
	std::cout << "                                           Type (help) to show manual" << std::endl;
	std::cout << "                           =============================================================" << std::endl;
	std::cout << "" << std::endl;
}

int main()
{
	showHeaderText();

	while (true)
	{
		std::string cmd;
		std::cout << " Command: ";
		getline(std::cin, cmd);


		if (cmd == "gen")
		{
			initArchGen();
			std::cout << "" << std::endl;
		}

		else if (cmd == "clear")
		{
			system("CLS");

			showHeaderText();
		}

		else if (cmd == "help")
		{
			showManual();
		}

		else if (cmd == "exit")
		{
			break;
		}

		else if (cmd == "")
		{
			std::cout << " Command cannot be empty." << std::endl;
		}

		else
		{
			std::cout << " (" + cmd + ") is an Unknown command, Type (help) to open manual." << std::endl;
		}
	}
}