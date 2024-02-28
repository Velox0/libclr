<div align="center">
<img height="20" src="https://img.icons8.com/dusk/64/wrench.png" alt="wrench"/>
Currently a work in progress

<img width="60%" src="images/banner.png"></img>

<hr>
<p>c library for spicing up the output</p>
</div>

# Overview

Perform colour mathematics and colourise output stream with endless customisations. Supports 4-bit, 8-bit and rgb colours. More features are underway.

# Setting up

Fork all the branches and clone the repository:

```bash
git clone https://www.github.com/{username}/libclr.git
cd libclr
```

To run unit tests, from the root of the project, run:

```bash
sh test/buildtest.sh
```

Test all the functions you add in test.c properly before pushing and/or merging.
The errors will be saved in `ERROR.log`

# Installation

In project root run:

```bash
./install.sh
```

## Usage

After installation include the library using the following include line:

```c
#include <libclr/libclr.h>

/*
code...
*/
```
