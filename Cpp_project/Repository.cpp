#include "Repository.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

Repository::Repository(const std::string& name) : name(name) {}

void Repository::addFile(const std::string& filename) {
    trackedFiles.push_back(filename);
    std::cout << "File '" << filename << "' added to the repository." << std::endl;
}

void Repository::listFiles() const {
    std::cout << "Tracked files in the repository '" << name << "':" << std::endl;
    for (const auto& file : trackedFiles) {
        std::cout << "- " << file << std::endl;
    }
}

std::string Repository::generateHash() const {
    std::ostringstream oss;
    for (const auto& file : trackedFiles) {
        oss << file; // Simplified hash: combining filenames
    }

    // Adding a timestamp to make each hash unique
    std::time_t now = std::time(nullptr);
    oss << std::put_time(std::localtime(&now), "%Y%m%d%H%M%S");
    return oss.str();
}

//void Repository::commit(const std::string& message) {
  //  std::string hash = generateHash();
    //lastCommitHash = hash; // Store the last commit's hash
    //std::cout << "Commit made with hash: " << hash << std::endl;
    //std::cout << "Commit message: " << message << std::endl;

    // Store the commit hash along with the list of tracked files
    //commits[hash] = trackedFiles;
//}

void Repository::commit(const std::string& message) {
    std::string hash = generateHash();
    
    // Check if the hash already exists in the commit history
    if (commits.find(hash) != commits.end()) {
        std::cout << "Duplicate commit detected. No new commit was made." << std::endl;
        return; // Do not store the commit if it's a duplicate
    }

    std::cout << "Commit made with hash: " << hash << std::endl;
    std::cout << "Commit message: " << message << std::endl;

    // Store the commit hash along with the list of tracked files
    commits[hash] = trackedFiles;
}


void Repository::showCommitLog() const {
    if (commits.empty()) {
        std::cout << "No commits have been made yet." << std::endl;
    } else {
        std::cout << "Commit Log:" << std::endl;
        for (const auto& commit : commits) {
            std::cout << "Hash: " << commit.first << std::endl;
            std::cout << "Files committed: ";
            for (const auto& file : commit.second) {
                std::cout << file << " ";
            }
            std::cout << std::endl;
        }
    }
}

void Repository::revert(const std::string& commitHash) {
    auto it = commits.find(commitHash);
    if (it != commits.end()) {
        trackedFiles = it->second;
        std::cout << "Repository has been reverted to commit: " << commitHash << std::endl;
        listFiles();
    } else {
        std::cout << "Error: Commit with hash " << commitHash << " not found." << std::endl;
    }
}

// Integrity check implementation
void Repository::checkIntegrity() const {
    std::string currentHash = generateHash(); // Generate hash of current files
    if (currentHash == lastCommitHash) {
        std::cout << "Integrity check passed. No tampering detected." << std::endl;
    } else {
        std::cout << "Warning: File content has been tampered with!" << std::endl;
    }
}
