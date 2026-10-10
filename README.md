

This repo contains some test to implement support of WisMesh Tag on RIOT OS.

> [!CAUTION]
> The current implementation available in this repository has not been properly tested and may potentially brick your device. **Especially, battery-related functionality has not been yet implemented.** 
> 
> So use at your own risk, the software is provided WITHOUT WARRANTY OF ANY KIND.

# Implementation State

- :white_check_mark: LEDs
- :white_check_mark: Button
- :white_check_mark: Buzzer

- :orange_square: GPS
- :orange_square: Accelerometer

- :x: Lora
- :x: Battery (incorrect values)
- :x: ...


# Usage 

## Setup

The repo uses board definition outside RIOT base as described in [RIOT Porting Board Guides](https://doc.riot-os.org/advanced_tutorials/porting_boards/#boards-outside-of-riotbase). 

The repo uses a git submodule to recuperate RIOT (in [./dependencies/RIOT]([./dependencies/RIOT])). You can directly update the Makefile with your own RIOT or recuperate the submodule using:

```bash
git clone https://github.com/bastien-buil/wismeshtag-riot --recursive
```

or using:

```bash
git submodule update --init
git submodule sync
```

## Running examples

For now, one example has been implemented in [./examples/wismesh-test]([./examples/wismesh-test] to make a LED blink and react when pressing a button by making the second led bright up and play a sound using the buzzer.
