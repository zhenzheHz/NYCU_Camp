#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: upload <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string gitAdd = "git add " + filename;
    if (system(gitAdd.c_str()) != 0) {
        std::cerr << "Failed to add file: " << filename << std::endl;
        return 1;
    }

    std::string gitCommit = "git commit -m \"add " + filename + "\"";
    if (system(gitCommit.c_str()) != 0) {
        std::cerr << "Failed to commit changes" << std::endl;
        return 1;
    }
    std::string gitPush = "git push";
    if (system(gitPush.c_str()) != 0) {
        std::cerr << "Failed to push changes" << std::endl;
        return 1;
    }

    std::cout << "File " << filename << " successfully uploaded to GitHub!" << std::endl;
    return 0;
}

