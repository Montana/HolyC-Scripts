#include "Syscalls.h"

struct BufferedFileWriter {
    U8* buffer;
    U64 bufferSize;
    U64 bufferIndex;
    CFileHandle* fileHandle;
};

U0 BufferedFileWriterInit(struct BufferedFileWriter* writer, CStr fileName, U64 bufferSize) {
    writer->buffer = MAlloc(bufferSize);
    writer->bufferSize = bufferSize;
    writer->bufferIndex = 0;
    writer->fileHandle = FOpen(fileName, "w");
}

U0 BufferedFileWriterWrite(struct BufferedFileWriter* writer, U8* data, U64 dataSize) {
    if (writer->bufferIndex + dataSize > writer->bufferSize) {
        BufferedFileWriterFlush(writer);
    }
    if (dataSize > writer->bufferSize) {
        FWrite(writer->fileHandle, data, dataSize);
    } else {
        MemCpy(writer->buffer + writer->bufferIndex, data, dataSize);
        writer->bufferIndex += dataSize;
    }
}

U0 BufferedFileWriterFlush(struct BufferedFileWriter* writer) {
    if (writer->bufferIndex > 0) {
        FWrite(writer->fileHandle, writer->buffer, writer->bufferIndex);
        writer->bufferIndex = 0;
    }
}

U0 BufferedFileWriterClose(struct BufferedFileWriter* writer) {
    BufferedFileWriterFlush(writer);
    FClose(writer->fileHandle);
    MFree(writer->buffer);
}

U0 Main() {
    struct BufferedFileWriter writer;
    BufferedFileWriterInit(&writer, "output.txt", 1024);
    BufferedFileWriterWrite(&writer, "Hello, World!", 13);
    BufferedFileWriterClose(&writer);
}
