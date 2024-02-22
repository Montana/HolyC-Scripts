## DirSize in Holy C

This repository contains HolyC scripts that I'm currently working on, including a program specifically designed for TempleOS that recursively calculates the total size of all files contained within a specified root directory and its subdirectories. It's a showcase of leveraging TempleOS's unique system calls and filesystem structure to perform practical tasks.

## Getting Started

These instructions will guide you on how to get a copy of the project up and running on your local machine for development, testing, and exploration purposes.

### Prerequisites

- TempleOS installed on your machine. For installation guidance, visit [TempleOS's official website](https://templeos.org/).
- A fundamental understanding of TempleOS and its HolyC programming language.

### Installing

To run these HolyC scripts on your TempleOS machine:

1. Clone or download this repository to your TempleOS environment.
2. Navigate to the directory where the scripts are located.
3. Open the desired HolyC file in the TempleOS editor.
4. Execute the script.

## Usage

To use the directory size calculator script, you need to modify the `rootDirPath` variable in the `Main` function to reflect the directory you wish to analyze:

```c
CStr rootDirPath = "C:/Path/To/Your/Directory"; // Adjust to your target directory
```

## Acknowledgments

A special thank you to Terry A. Davis for creating the visionary TempleOS and the HolyC programming language. Appreciation to the TempleOS community for their ongoing exploration, documentation, and sharing of knowledge regarding this unique operating system.
