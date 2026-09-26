# BMS firmware

[`bms/bms.ino`](bms/bms.ino) is an Arduino sketch for a Seeeduino Nano. It monitors each cell of the 3S pack and closes the main relay only when the power switch is on **and** every cell is inside its limits.

Drafted with ChatGPT, then reviewed and tested by the author and a member of the Badger Solar Racing team.

## Configuration

| Setting | Value |
|---|---|
| Cell under-voltage cutoff | 3.00 V |
| Cell over-voltage limit | 4.25 V |
| Voltage dividers | 220 kΩ top / 100 kΩ bottom (÷3.2, so up to 16 V reads on a 5 V ADC) |
| ADC reference | 5.0 V (Nano supply) |
| Loop period | 200 ms |
| Serial logging | 115200 baud: per-cell voltages, safe state, switch state, relay state |

## Pins

| Pin | Function |
|---|---|
| A0 | Cell 1 tap (B1+) |
| A1 | Cells 1+2 tap (B2+) |
| A2 | Pack positive (B3+) |
| D3 | Relay MOSFET gate |
| D4 | Power switch (to GND, internal pull-up) |
| VIN | Separate 9 V battery |
| GND | Common with the pack negative |

Each cell's voltage comes from the difference between adjacent taps: `C1 = A0`, `C2 = A1 − A0`, `C3 = A2 − A1`.

On power-up the relay pin is driven LOW before anything else, so the pack stays disconnected until the first safety check passes.
