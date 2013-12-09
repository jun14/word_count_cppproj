#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#include <fstream>
#include <string>

using std::ifstream;
using std::string;

ifstream &open_file(ifstream &in, const string &file);

#endif