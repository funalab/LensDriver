LensDriver
======================
This program is a driver for [Optotune LENS DRIVER 4](http://www.optotune.com/products/focus-tunable-lenses/lens-driver-4 "Optotune LENS DRIVER 4").
By using provided API, user can easily manipulate Optotune EL-10-30 from their C program.

![Screenshot](http://fun.bio.keio.ac.jp/~funa/gitblit/lensdriver.png "Screenshot of sample program running by using LensDriver")

How to Compile
--------------
### Dependencies ###
LensDriver requires following third-party application.  
Please install following libraries before compiling LensDriver.

+   [Exuberant Ctags](http://ctags.sourceforge.net/ "Exuberant Ctags") :  
```sh
% sudo port install ctags
```

### Build LensDriver ###
```sh
% git clone https://funa@fun.bio.keio.ac.jp:8443/git/LensDriver.git
% cd LensDriver  
% make
```

How to use
----------
### Write a code using LensDriver API ###
```sh
% vim main.c
```
```c
#include "lensdriver.h"

int main(int argc, char* argv[]) {
  int fd;
  uint32_t mHz = 1000; /* 1 Hz */
  uint16_t ucurrent = 4000;  /* upper current for sinusoidal */
  uint16_t lcurrent = 0;     /* lower current for sinusoidal */
  /* Check arguments */
  if (argc < 2) {
    usage(argv);
    return 0;
  }
  /* Open device */
  fd = dev_open_setup(argv[1]);

  /* Start */
  if (cmd_start(fd) == -1) {
    safe_exit(fd);
  }

  /* Run sinusoidal */
  if (cmd_run_sinusoidal(fd, ucurrent, lcurrent, mHz) == -1) {
    safe_exit(fd);
  }
  sleep(10);

  /* Reset and close device */
  safe_exit(fd);
  return 0;
}
```

### Compile ###
```sh
% make 
```

### Run ###
+   ./lensdriver /dev/tty.usb`Tab`
+   ./lensdriver /dev/tty.usbmodem1411  (for example)

References
----------
### links
1. [Lens Driver 4 manual (incl. serial firmware protocol)](http://www.optotune.com/images/products/Optotune%20Lens%20Driver%204%20manual.pdf "Lens Driver 4 manual")

License
-------
Copyright &copy; 2013-2017 Funahashi Lab., Keio University
Licensed under the [Apache License, Version 2.0][Apache]  

[Apache]: http://www.apache.org/licenses/LICENSE-2.0
