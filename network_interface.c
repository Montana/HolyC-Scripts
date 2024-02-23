#include "Syscalls.h"

struct NetworkPacket {
    U8 data[1500]; 
    U64 length;
};

struct NetworkInterface {
    // Things that feasibly could be monitored. - Michael Mendy.
    U8 macAddress[6];
    U8 ipAddress[4];
    U64 packetsReceived;
    U64 packetsSent;
};

U0 MonitorNetworkInterface(struct NetworkInterface* iface) {
    struct NetworkPacket packet;
    while (1) {
      
        if (ReceivePacket(iface, &packet)) {
            iface->packetsReceived++;
            // Processing the packet in particular it's looking for the receipt of packet. The network interface card (NIC) receives a packet from the network and passes it to the network stack. - Michael Mendy.
            PrintF("Packet received on interface: %d bytes\n", packet.length);
        }
    }
}

U0 Main() {
    struct NetworkInterface iface;
    // Initialize the network interface - Michael Mendy.
    MemSet(&iface, 0, sizeof(iface));
    // Hypothetical MAC and IP address assignment, please assign real ones. - Michael Mendy.
    iface.macAddress[0] = 0xDE; iface.macAddress[1] = 0xAD;
    iface.macAddress[2] = 0xBE; iface.macAddress[3] = 0xEF;
    iface.macAddress[4] = 0x00; iface.macAddress[5] = 0x01;

    iface.ipAddress[0] = 192; iface.ipAddress[1] = 168;
    iface.ipAddress[2] = 1; iface.ipAddress[3] = 100;

    MonitorNetworkInterface(&iface);
}
