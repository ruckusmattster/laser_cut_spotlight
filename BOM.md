# Bill of Materials

## Specific parts

| Part | Notes | Link |
|---|---|---|
| Fresnel lens, 200 mm diameter, 70 mm focal length | A longer focal length also works, but will likely waste some light | [AliExpress](https://www.aliexpress.us/item/3256807718403632.html) |
| Luminus SFT-42R, 6500 K | | [AliExpress](https://www.aliexpress.us/item/3256809660127347.html) |
| Tower CPU air cooler | Well oversized for the job, chosen for looks. The Onshape "calculated offset" assumes this cooler | [AliExpress](https://www.aliexpress.us/item/3256805713681022.html) |
| CC/CV buck-boost converter module | Set to 8.5 A, 3.5 V max. **Not recommended**: its 8.5 A limit caps the LED at about 60% brightness. Look for a module rated for 15 A | [AliExpress](https://www.aliexpress.us/item/3256805819652483.html) |

> AliExpress `.us` links don't work for everyone. If one fails, search for the item number.

## Generic parts

| Qty | Part | Purpose |
|---|---|---|
| 1 | Seeeduino Nano (or Arduino Nano) | Battery management, runs [`firmware/bms/bms.ino`](firmware/bms/bms.ino) |
| 1 | 9 V battery and clip | Independent power for the Nano |
| 1 | Latching power switch | Power button (to D4 and GND) |
| 1 | JD1912 automotive relay | Switches the main pack to the driver |
| 1 | MOSFET, logic level | Driven by D3, switches the relay coil |
| 1 | Diode | Flyback protection across the relay coil |
| 3 | 220 kΩ resistor | Cell-tap dividers, top |
| 3 | 100 kΩ resistor | Cell-tap dividers, bottom |
| – | Gate resistor | MOSFET gate |
| 3 | Samsung 50E 21700 cells | 3S1P pack |
| 1 | 3S 21700 cell holder | |
| – | Thermal paste | LED to cooler |
| – | 1/4" MDF sheet | Entire body |
| – | 1/16" PETG sheet (or any thin material) | LED centering ring |
| – | Assorted screws and nuts | |
| – | Black paint, water-based clear finish | Interior and exterior finishing |
