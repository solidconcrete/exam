#pragma once
#include <string>
//namespace fs = std::filesystem;
class commandShell
{
public:
	commandShell();
	void start();
	void listenForCommand();
	void MVP();
	void list();
	void setPath();
	void parentPath();
	void copy();
	void remove();
	void stop();

private:
	std::string command;
	std::string currentPath;
	//fs::path currentPathPath;

};

