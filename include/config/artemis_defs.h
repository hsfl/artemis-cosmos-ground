#ifndef _ARTEMIS_DEFS_H
#define _ARTEMIS_DEFS_H

#include <TeensyThreads.h>
#include <support/packetcomm.h>
#include <support/configCosmosKernel.h>
#include <ArduinoJson.h>

#define MAXQUEUESIZE 50

// Sensor Defs
#define ARTEMIS_CURRENT_BEACON_1_COUNT 2
#define ARTEMIS_CURRENT_SENSOR_COUNT 5
#define ARTEMIS_TEMP_SENSOR_COUNT 7

extern const char *current_sen_names[ARTEMIS_CURRENT_SENSOR_COUNT];
extern const char *temp_sen_names[ARTEMIS_TEMP_SENSOR_COUNT];

// Nodes
enum NODES : uint8_t
{
  GROUND_NODE_ID = 1,
  TEENSY_NODE_ID = 2,
  RPI_NODE_ID = 3,
};

extern std::map<string, NODES> NodeType;

// Structs
struct thread_struct
{
  int thread_id;
  uint8_t channel_id;
};

// Enums
enum TEENSY_PINS
{
  UART4_RXD,
  UART4_TXD,
  T_GPIO2,
  T_GPIO3,
  T_GPIO4,
  T_GPIO5,
  T_GPIO6,
  RADIO_RESET,
  UART6_RX,
  T_CS1,
  T_CS,
  SPI0_MOSI,
  SPI0_MISO,
  SPI0_SCLK,
  AIN0,
  AIN1,
  SCL1_I2C,
  SDA1_I2C,
  I2C2_SDA,
  I2C2_SCL,
  AIN3,
  AIN4,
  AIN5,
  AIN6,
  I2C1_SCL,
  I2C1_SDA,
  SPI1_D1,
  SPI1_SCLK,
  UART5_TXD,
  UART5_RXD,
  RX_ON,
  TX_ON,
  PI_STATUS,
  GPS_RSTN,
  UART2_RXD,
  UART2_TXD,
  RPI_ENABLE,
  SDN,
  SPI1_CS1,
  SPI1_D0,
  NIRQ,
  AIN2
};

enum PDU_CMD : uint8_t
{
  None,
  All,
  SW_3V3_1,
  SW_3V3_2,
  SW_5V_1,
  SW_5V_2,
  SW_5V_3,
  SW_5V_4,
  SW_12V,
  VBATT,
  WDT,
  HBRIDGE1,
  HBRIDGE2,
  BURN,
  BURN1,
  BURN2,
  RPI,
};

extern std::map<string, PDU_CMD> PDUType;

// Max threads = 16
extern vector<struct thread_struct> thread_list;

// Mutex for Command Queues
extern Threads::Mutex main_queue_mtx;
extern Threads::Mutex rfm23_queue_mtx;

// Command Queues
extern queue<PacketComm> main_queue;
extern queue<PacketComm> rfm23_queue;

// Other Mutex
extern Threads::Mutex spi1_mtx;

// Utility Functions
int kill_thread(char *thread_name);
int32_t PushQueue(PacketComm &packet, queue<PacketComm> &queue, Threads::Mutex &mtx);
int32_t PullQueue(PacketComm &packet, queue<PacketComm> &queue, Threads::Mutex &mtx);

#endif // _ARTEMIS_DEFS_H
