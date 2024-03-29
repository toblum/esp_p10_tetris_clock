# esp_p10_tetris_clock
A tetris clock based on a 16x32 RGB matrix and a ESP8266.


[![alt text](https://j.gifs.com/6RvBDl.gif "Tetris clock animation")](https://youtu.be/BGmjvfqf_0U)
![alt text](https://github.com/toblum/esp_p10_tetris_clock/blob/master/assets/tetris_ribba.gif "Tetris clock build in IKEA RIBBA frame")


Note: Please also have a look on the https://github.com/toblum/TetrisAnimation repo. Brian Lough ported this code to a library and also added text support [in this video](https://www.youtube.com/watch?v=2IejVgrSlWE).


This is the first implementation of the Tetris Clock on a RGB matrix. It uses the ESP8266 that was the only option at that time. The code was ported to [ESP32](https://github.com/witnessmenow/WiFi-Tetris-Clock) by Brian Lough. He also has a version based on the fast [ESP32-HUB75-MatrixPanel-I2S-DMA](https://github.com/mrfaptastic/ESP32-HUB75-MatrixPanel-I2S-DMA) library that you can [easily install using a web flasher](https://www.youtube.com/watch?v=xjTACT1qO_8). Maybe you want to have a look here, if you have a ESP32 at hand.


## Installation
This project is built on [platform.io](http://docs.platformio.org). All dependencies are automatically installed, if you use it. I recommend to use it [together with Visual Studio Code](http://docs.platformio.org/en/latest/ide/vscode.html).

It's also possible to use the Arduino IDE, then you have to install the required libraries manually (see tetris_clock.ino).

Please note: These matrices exist in different pitch sizes P10 means 10mm and results in 32x16 cm panels. The latest build is based on a P6 matrix that is roughly 20x10 cm in size.

## Wiring
This project is based on the famous PxMatrix library. For wiring the matrix, see the excellent instructions [here](https://github.com/2dom/PxMatrix/).

## Building
The complete build instructions can be found on [instructables](https://www.instructables.com/id/Tetris-Time-on-a-P10-RGB-Matrix-With-ESP8266).

You find the 3D printable parts [here](https://www.thingiverse.com/thing:2846368).

## Enhancement
* Support for 32x32 displays
* 12 hour mode [issue](https://github.com/toblum/esp_p10_tetris_clock/issues/2#issuecomment-392286952)
* Weather forecast
* Youtube counter
