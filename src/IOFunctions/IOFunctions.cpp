#include <climits>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> LineRead() {
    std::vector<std::string> BUF;
    std::string buf;
    std::stringstream ss;
    getline(std::cin, buf);
    ss << buf;
    while (ss >> buf) {
        BUF.push_back(buf);
    }
    return BUF;
}
