#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <vector>
#include <map>

class Repository {
public:
    Repository(const std::string& name); 
    void addFile(const std::string& filename);
    void listFiles() const;

    // Method for committing a file
    void commit(const std::string& message);

    void showCommitLog() const; // This will display the commit history
    void revert(const std::string& commitHash); // Revert to a previous commit
    
    // Integrity check
    void checkIntegrity() const; // Method to verify file integrity

private:
    std::string name; 
    std::vector<std::string> trackedFiles;
    
    // Storing commit information for the current branch
    std::map<std::string, std::vector<std::string>> commits;
    std::string lastCommitHash; // Store the hash of the last commit

    // Method to generate a hash for the commit
    std::string generateHash() const;
};

#endif
