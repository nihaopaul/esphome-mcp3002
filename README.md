Sample setup for MCP3002 using SPI1 not SPI0 on the esp8266 for esphome.

TODO:
[ ] break out the cpp and clean up header file
[ ] include configurables for interval, cs and configuration mode (channels, comparitors)

```yaml

esphome:
  name: any_name_you_configured
  platform: ESP8266
  board: nodemcuv2
  includes:
    - mcp3002.h



spi:
  clk_pin: D5
  mosi_pin: D7
  miso_pin: D6
  
sensor:
- platform: custom
  lambda: |-
    auto mcp3002 = new MCP3002();
    App.register_component(mcp3002);
    return {mcp3002->channel_0, mcp3002->channel_1};

  sensors:
  - name: "Channel 0"
    unit_of_measurement: adc
  - name: "Channel 1"
    unit_of_measurement: adc


```
