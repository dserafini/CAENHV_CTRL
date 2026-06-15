<img width="400" src="docs/logo.svg">

> **Warning** The project is still under development:
> a lot of code needs to be properly refactored, and almost no
> errors are properly handled up to now.

# A simple controller for CAEN DT547x H.V. Power Supply

This repo contains a simple program, written in c, for the control of the CAEN DT547x Desktop power supply family under GNU/Linux operating systems.

The communication with the module is accomplished via serial over USB using the protocol
described in the instrument's manual provided by the vendor.

## Installation

The only required dependency is gtk 3.0, under ubuntu it should be as simple as:
````bash
sudo apt-get install libgtk-3-dev
````

Install also icon lists:
````bash
sudo apt install adwaita-icon-theme-full
sudo apt install gnome-icon-theme
````

Then the code can be compiled using the provided CMakeLists:

````bash
mkdir build && cd build
cmake ..
make
````

the GUI can then be launched from the terminal:

````bash
./caenhvctrl
````


## Usage



<img width="500" src="docs/gui.png">

## FAQ

There are no errors but I cannot see the window: check if other graphical applications works, like gedit; if you are using a 2-monitor configuration, switch to a 1-monitor configuration.

I want to use the application inside a linux WSL. Follow the [Microsoft indications](https://learn.microsoft.com/en-us/windows/wsl/connect-usb) for connecting USB devices with WSL. Summarizing, you need to use the [usbipd-win application](https://github.com/dorssel/usbipd-win/releases). Then you can see the USB device from within the WSL instance. The CAENHV_CTRL application can connect to the dedicated device without further coding.

