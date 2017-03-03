### About

This folder contains files to run JerryScript with RIOT on [IoT-Lab M3](https://www.iot-lab.info/hardware/m3/) board.
More info [here](https://www.iot-lab.info) on the open access testbed IoT-lab and how get a free account for bare-metal access to thousands of IoT devices.

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
  |      + riot-iotlab
  + RIOT
  |  + examples
```

2, Target board

Assume IoT-Lab_M3 as the target board.



#### 2. Build JerryScript for RIOT-OS

```
# assume you are in harmony folder
cd jerryscript
make -f ./targets/riot-iotlab/Makefile.riot
```

This will generate the following libraries:
```
librelease.jerry-core.a
librelease.jerry-libm.lib.a
```

This will copy one library files to `targets/riot-iotlab/bin` folder:
```
libjerrycore.a
```

This will create a hex file in the `targets/riot-iotlab/bin` folder:
```
riot_jerry.elf
```

#### 4. Flashing and Communicating with the Board

```
make -f ./targets/riot-iotlab/Makefile.riot flash
```


#### 5. Cleaning

To clean the build result:
```
make -f ./targets/riot-samr21/Makefile.riot clean
```


### 5. Running the example

1. compile RIOT .elf

2. connect to the portal http://iot-lab.info

3. through the portal, launch experiment (choosing nodes, and uploading .elf)

4. check the id of the nodes used for the experiment (for example: m3-102)

5. ssh to frontend: ssh your-login@grenoble.iot-lab.info (if needed replace grenoble by other iot-lab site)

5. once the experience in running (indicated on the web portal) open a serial connection on the node(s) with nc command (for example: nc m3-102 20000) then type reboot to get into the RIOT shell.

In the RIOT shell, `help` will provide a list of commands:
```
> help
```

The `script` command will run the test script code that you input in the commant line.
Some examples of scripts you can try:
```
script print ('hello');
```
```
script var x = Math.sqrt (64); var txt = \'\'; while (x>1) { txt += --x + \'\\n\';} print (txt);
```
```
script var person = { fname:\'John\', lname:\'Doe\', age:25 }; var text = \'\'; var x; for (x in person) { text += person[x] + \'\\n\'; } print (text);
```

Remark: outside of the print command, you may have to replace single brackets ' with \'.
