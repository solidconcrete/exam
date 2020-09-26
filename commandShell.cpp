#include "commandShell.h"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

commandShell::commandShell()
{
}
void commandShell::start()
{
	std::cout << "hello and welcome to this command shell prototype" << '\n';
	MVP();
	listenForCommand();
}
void commandShell::listenForCommand()
{
	std::cin >> command;
	if (command == "list")
	{
		list();
	}
	if (command == "enter")
	{
		setPath();
		
	}
	if (command == "leave")
	{
		parentPath();

	}
	if (command == "copy")
	{
		copy();
	}
	if (command == "delete")
	{
		remove();
	}

}
void commandShell::MVP()
{
	if (currentPath.empty())
	{
		std::cout << fs::current_path() << '\n';
	}
	else std::cout << currentPath << '\n';

}
void commandShell::list()
{
	if (currentPath.empty())
	{
		for (const auto& entry : fs::directory_iterator(fs::current_path()))
			std::cout << entry.path() << std::endl;
	}
	else
	{
		for (const auto& entry : fs::directory_iterator(currentPath))
			std::cout << entry.path() << std::endl;
	}
	listenForCommand();
}
void commandShell::setPath()
{
	std::string path;
	std::cin >> path;
	currentPath = path;
	listenForCommand();
	MVP();

}
void commandShell::parentPath()
{
	const std::filesystem::path path = currentPath;
			for (const auto& entry : fs::directory_iterator(currentPath))
			std::cout << entry.path() << std::endl;
	//std::cout << "asasd";
	//std::cout << path.parent_path();
	//fs::path newpath{ fs::u8path(u8"愛.txt") };
	//std::string path_string{ newpath.u8string() };
	//std::cout << path_string;
	
}
void commandShell::copy()
{
	std::string what, where;
	std::cin >> what;
	std::cin >> where;
	fs::copy(what, where);
}
void commandShell::remove()
{
	std::string what;
	std::cin >> what;
	fs::remove(what);
}
void commandShell::stop()
{
	return;
}