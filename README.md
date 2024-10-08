

# Simple Version Control System

This is a simple implementation of a version control system in C++. The system allows users to track files, commit changes, and maintain a log of commits. It provides basic functionalities similar to what is found in more complex version control systems like Git.

## Features

- **File Tracking**: Add files to the repository for tracking.
- **Commit Changes**: Commit changes with a message and store the state of the tracked files.
- **Commit Log**: View a log of all commits made, including commit hashes and the files associated with each commit.
- **Revert Commits**: Revert the repository to a previous commit based on the commit hash.
- **Integrity Check**: Check the integrity of the repository to ensure no files have been tampered with since the last commit.

## Getting Started

### Prerequisites

- A C++ compiler (like g++ or clang++)
- CMake (optional, for easier build process)

### Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/yourusername/SimpleVersionControlSystem.git
   cd SimpleVersionControlSystem
   ```

2. **Build the project**:

   You can compile the project using the following command:

   ```bash
   g++ main.cpp Repository.cpp -o version_control_system
   ```

### Usage

Run the executable:

```bash
./version_control_system
```

The program performs the following actions:

1. Creates a repository named "MyRepo".
2. Adds two files (`file1.txt` and `file2.cpp`) to the repository.
3. Commits the changes with an "Initial commit" message.
4. Shows the commit log.
5. Attempts to commit again without any changes, which should result in a message indicating a duplicate commit.
6. Adds another file (`file3.doc`) and commits the change.
7. Displays the updated commit log.

### Example Output

When you run the program, you can expect output similar to the following:

```
File 'file1.txt' added to the repository.
File 'file2.cpp' added to the repository.
Commit made with hash: <hash>
Commit message: Initial commit
Commit Log:
Hash: <hash>
Files committed: file1.txt file2.cpp 
Duplicate commit detected. No new commit was made.
File 'file3.doc' added to the repository.
Commit made with hash: <new_hash>
Commit Log:
Hash: <hash>
Files committed: file1.txt file2.cpp 
Hash: <new_hash>
Files committed: file1.txt file2.cpp file3.doc 
```

### API Documentation

- `Repository(const std::string& name)`: Constructor to create a new repository.
- `void addFile(const std::string& filename)`: Adds a file to the repository.
- `void listFiles() const`: Lists all files tracked by the repository.
- `void commit(const std::string& message)`: Commits the current state of the tracked files with a message.
- `void showCommitLog() const`: Displays the commit log.
- `void revert(const std::string& commitHash)`: Reverts the repository to a specified commit using its hash.
- `void checkIntegrity() const`: Checks the integrity of the repository to ensure no files have been tampered with.

