#ifndef EDGE_PARSER_H
#define EDGE_PARSER_H

#include <string>
#include <vector>

// splits s into a vector of strings, at occurences of the delimiter character
std::vector<std::string> split(std::string s, char delimiter);

// returns a modified copy of s, including only the allowed characters specified
// in permittedChars
std::string filterChars(std::string s, std::string permittedChars);

// takes a string such "((300.5, 12), (11, 3800))"
// returns a vector of ints such as {300,12,11,3800}
// if the string has more than 4 coordinates, we discard the extras
// if any coordinate has a non-integral part, we take the floor of thecoordinate
std::vector<int> parseLine(std::string line);

#endif // EDGE_PARSER_H