#include "Syscalls.h"

#define SECTOR_SIZE 512
#define PARTITION_TABLE_OFFSET 446
#define PARTITION_ENTRY_SIZE 16
#define PARTITION_TABLE_SIZE 64
#define BOOT_SIGNATURE 0xAA55

struct PartitionEntry {
    U8  boot_indicator;
    U8  start_head;
    U8  start_sector;
    U8  start_cylinder;
    U8  partition_type;
    U8  end_head;
    U8  end_sector;
    U8  end_cylinder;
    U32 starting_sector;
    U32 sectors_long;
};

struct MBR {
    U8  bootstrap_code[PARTITION_TABLE_OFFSET];
    struct PartitionEntry partitions[4];
    U16 signature;
};

# You will need to define things like boot_indicator,etc. Don't forget the swap! - Michael Mendy.

U0 CreatePartition(struct MBR* mbr, U32 start_sector, U32 sectors, U8 partition_type) {
    struct PartitionEntry* entry = &mbr->partitions[0]; 
    entry->boot_indicator = 0x00; 
    entry->start_head = 0;        
    entry->start_sector = 0;      
    entry->start_cylinder = 0;    
    entry->partition_type = partition_type;
    entry->end_head = 0;          
    entry->end_sector = 0;       
    entry->end_cylinder = 0;      
    entry->starting_sector = start_sector;
    entry->sectors_long = sectors;
}

U0 WriteMBR(CStr device) {
    struct MBR mbr;
    MemSet(&mbr, 0, sizeof(mbr));
    mbr.signature = BOOT_SIGNATURE;
    CreatePartition(&mbr, 2048, 4096, 0x83); // Example partition

    CFileHandle* file = FOpen(device, "w");
    if (file) {
        FWrite(file, &mbr, sizeof(mbr));
        FClose(file);
    }
}

U0 Main() {
    WriteMBR("C:/Disk.img");
}
