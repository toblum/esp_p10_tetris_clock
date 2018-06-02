# esp_p10_tetris_clock
A tetris clock based on a P10 16x32 RGB matrix and a ESP8266.


[![alt text](https://j.gifs.com/6RvBDl.gif "Tetris clock animation")](https://youtu.be/BGmjvfqf_0U)
![alt text](http://i68.tinypic.com/2cyfj45.jpg "Tetris clock build")



## Installation
This project is built on [platform.io](http://docs.platformio.org). All dependencies are automatically installed, if you use it. I recommend to use it [together with Visual Studio Code](http://docs.platformio.org/en/latest/ide/vscode.html).

It's also possible to use the Arduino IDE, then you have to install the required libraries manually (see tetris_clock.ino).

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
