#How to add TeleMonitor Universal IoT Platform on Arduino1.0.x device list.

copy and add contents of boards.txt to existing boards.txt which is in your \<arduino IDE directory\> / hardware/boards.txt


Next copy the folder TeleMonitorATmega16-32 in your \<arduino IDE directory\>/hardware/variants/

then restart the IDE. (in case you're using STINO with sublime-text you only need to refresh.) 

**Please Note:** Here the compatibility files shall only help to program the MCU used in TeleMonitor Device with Arduino as ISP mode. 