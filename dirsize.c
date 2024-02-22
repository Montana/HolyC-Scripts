#include "Syscalls.h"

U64 GetTotalSize(CStr dirPath) {
    U64 totalSize = 0;
    CDIR *dir = FS->OpenDir(dirPath);
    if (!dir) return 0;
    while (CDEntry *entry = FS->ReadDir(dir)) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            U8 newDirPath[512];
            sprintf(newDirPath, "%s/%s", dirPath, entry->d_name);
            totalSize += GetTotalSize(newDirPath);
        } else if (entry->d_type == DT_REG) {
            U8 filePath[512];
            sprintf(filePath, "%s/%s", dirPath, entry->d_name);
            totalSize += FS->FileSize(filePath);
        }
    }
    FS->CloseDir(dir);
    return totalSize;
}

Void Main() {
    CStr rootDirPath = "C:/"; // Change this to your root directory path
    U64 totalSize = GetTotalSize(rootDirPath);
    PrintF("Total size of all files: %d bytes\n", totalSize);
}
