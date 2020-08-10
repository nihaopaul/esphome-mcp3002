```yaml


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
