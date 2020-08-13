#include "esphome.h"


class MCP3002 : public PollingComponent, public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING, spi::DATA_RATE_1KHZ> {
  public:

    Sensor *channel_0 = new Sensor();
    Sensor *channel_1 = new Sensor();
    
    MCP3002(uint32_t update_interval) : PollingComponent(update_interval) { }

    void setup() override {
      SPI.begin();
      pinMode(CS_PIN, OUTPUT);
      
    }

    void update() override {
      word chan0 = read_channel(CHANNEL0);
      channel_0->publish_state(chan0);
      word chan1 = read_channel(CHANNEL1);
      channel_1->publish_state(chan1);
    }

  protected:
    const int CS_PIN = D8;
    const uint8_t CHANNEL0 = 0b11000000;
    const uint8_t CHANNEL1 = 0b11100000;
    word read_channel(uint8_t cmd) {

      digitalWrite (CS_PIN, LOW);
      byte msb, lsb;
      word assembled;

      msb = SPI.transfer(cmd);
      lsb = SPI.transfer(0);

      digitalWrite (CS_PIN, HIGH);
      SPI.endTransaction();

      return word(msb, lsb);

    }
  
};