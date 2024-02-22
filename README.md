## My Collection of HolyC Scripts

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

## Most Interesting Scripts I've Made in HolyC

I think the buffered file writer based on an interface and file class was most interestin. Since HolyC is unique to TempleOS it doesn't follow the same OOP paradigms/guard rails. I had to define both the interface and the class, including methods for opening, writing to, and closing the file, as well as buffering the write operations to improve performance. 

However, HolyC, being unique to TempleOS, doesn't follow the same object-oriented programming (OOP) paradigms found in languages like C++ or Java, particularly in the use of interfaces in the way you might expect from those languages. Creating it was merely a conceptual approach to creating a buffered file writer for HolyC.

## Acknowledgments

A special thank you to Terry A. Davis for creating the visionary TempleOS and the HolyC programming language. Appreciation to the TempleOS community for their ongoing exploration, documentation, and sharing of knowledge regarding this unique operating system.
