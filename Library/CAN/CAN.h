#ifndef
#define can_h
class CANClass
{
private:

public:
static void bps(byte bpsRate);

static void send_0();
static void send_1();
static void send_2();

static byte readID_0();
static byte readID_1();
static byte readDATA_0();
static byte readDATA_1();

static void load_0(byte identifier, byte data);
static void load_1(byte identifier, byte data);
static void load_2(byte identifier, byte data);

};
#endif