#include <iostream>
#include "Repository.h"

int main() {
    // Create a repository
    Repository repo("MyRepo");

    // Add files to the repository
    repo.addFile("file1.txt");
    repo.addFile("file2.cpp");

    // First commit
    repo.commit("Initial commit");

    // Show the commit log
    repo.showCommitLog();

    // Attempt to commit again without any changes (should detect duplicate)
    repo.commit("Another commit with no changes");

    // Add a new file and commit again
    repo.addFile("file3.doc");
    repo.commit("Added file3.doc");

    // Show the commit log again
    repo.showCommitLog();

    return 0;
}
