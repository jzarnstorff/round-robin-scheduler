# Round Robin Scheduler

## Overview

The code in this repository was developed around the **NUCLEO-F411RE** development board with **STM32F411RE** MCU, and it contains the code for a round robin scheduler.

## Requirements

The Arm GNU Toolchain, `gcc-arm-none-eabi`, is required to cross-compile the source code for the target MCU.

    sudo apt update && sudo apt install -y make gcc-arm-none-eabi

Use `make` to compile and link the project.

The output file `./build/task_scheduler.elf` can then be written to the internal flash of the **STM32F411RE** MCU on **NUCLEO-F411RE** Discovery board using a tool such as `openocd`.

Documentation for the project can also be built with `doxygen`.

    sudo apt install -y doxygen

After installing `doxygen`, run the following command to build the documentation.

    make docs

The documentation can be viewed by opening `./html/index.html` using a web browser.

## Developer Requirements

`Poetry` is used to manage the project's dependencies and can be installed using the installer directly from [install.python-poetry.org](https://install.python-poetry.org/). The script can be executed directly using `curl` and `python` from your Linux environment.

    curl -sSL https://install.python-poetry.org | python3 -

After successfully installing `Poetry`, install the project's dependencies:

    poetry install

Source the virtual environment:

    source .venv/bin/activate

Install `pre-commit` to set up the git hook scripts to run linters on the source code when making commits. More on `pre-commit` can be found at [pre-commit.com](https://pre-commit.com/)

    pre-commit install
