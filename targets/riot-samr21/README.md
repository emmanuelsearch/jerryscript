### About

This folder contains files to run JerryScript on RIOT-OS with STM32F4-Discovery board.

### How to build

#### 1. Preface

1, Assumptions/Prerequisites


Follow [this](https://www.riot-os.org/#download) page to get the RIOT-OS source.

Follow the [Inroduction](https://github.com/RIOT-OS/RIOT/wiki/Introduction) wiki site and also check that you can flash the stm32f4-board.

Assumption: RIOT is installed in the same directory as jerryscript, for example let's call it 'harmony', giving something like:

```
harmony
  + jerryscript
  |  + targets
  |      + riot-samr21
  + RIOT
  |  + examples
```

2, Target board

Assume ATMEL SAMR21 as the target board.



#### 2. Build JerryScript for RIOT-OS

```
# assume you are in harmony folder
cd jerryscript
make -f ./targets/riot-samr21/Makefile.riot
```

This will generate the following libraries:
```
librelease.jerry-core.a
librelease.jerry-libm.lib.a
```

This will copy one library files to `targets/riot-samr21/bin` folder:
```
libjerrycore.a
```

This will create a hex file in the `targets/riot-samr21/bin` folder:
```
riot_jerry.elf
```

#### 4. Flashing and Communicating with the Board

```
make -f ./targets/riot-samr21/Makefile.riot flash
```


#### 5. Cleaning

To clean the build result:
```
make -f ./targets/riot-samr21/Makefile.riot clean
```


### 5. Running JerryScript Hello World! example

You may have to press `RESET` on the board after the flash.

Connect to the board via terminal and Minicom (or equivalent) with settings baud 115200 parity 8N1 (for comfort activate echo and carraige return). 
Set `Add Carriage Ret` option by `CTRL-A` > `Z` > `U` and then `E` at the console, if you're using `minicom`.

In the RIOT shell, `help` will provide a list of commands:
```
> help
```

The `script` command will run the test script code that you input in the commant line.
```
script print ('hello');
```

Outside of the print command, you may have to replace single brackets ' with \'.
