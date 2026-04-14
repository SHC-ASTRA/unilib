# unilib

The purpose of this library is to provide a single source of truth for the various
custom formats ASTRA makes use of. This currently includes the following:

- [VicCAN Format](https://docs.google.com/spreadsheets/d/1-Tdnsv2_-r8CBJNxPaAmIR2wMPSTix63AkemrWzVJVY/edit?gid=586685598#gid=586685598)
- ASTRA Epoch Timestamp Format

## Development

You will need [Nix](https://nixos.org/download/#nix-install-linux) installed to work
on this library.

Use the following command to enter the development shell from inside the repository
root:

```bash
$ nix develop
```

To get a Python REPL with the unilib package installed, use this:

```bash
$ nix run
```

Before merging a change to main, make sure you bump the version in
`library.json`.

## Usage

### Python (with Nix)

Add unilib as an input to your project's `flake.nix`:

```nix
{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    unilib.url = "github:SHC-ASTRA/unilib";
  };

  outputs = { nixpkgs, unilib, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };

      # get the unilib python package
      unilibPkg = unilib.packages.${system}.unilib;

      # create a python environment with unilib
      pythonEnv = pkgs.python313.withPackages (ps: [
        unilibPkg
        # add other packages here
      ]);
    in {
      devShells.${system}.default = pkgs.mkShell {
        packages = [ pythonEnv ];
      };
    };
}
```

Then use it in your Python code:

```python
import unilib

# message types
msg_type = unilib.MessageType.PING
print(msg_type.value)  # 1

# microcontroller IDs
mcu = unilib.Microcontroller.CORE
print(mcu.value)  # 1

# data types
dtype = unilib.DataType.FLOAT32
print(dtype.value)  # 1

# docstrings are available on enum values
help(unilib.MessageType.HEARTBEAT)
```

### PlatformIO

1. Add the following line to `lib_deps` in your `platformio.ini`:

```ini
lib_deps =
    https://github.com/SHC-ASTRA/unilib
```

2. Include the header and use the definitions:

```cpp
// example for can_defs.hpp. check /include/ for available components
#include <unilib/can_defs.hpp>

void setup() {
    // Use message types
    uint8_t msg_id = static_cast<uint8_t>(unilib::MessageType::PING);

    // Use microcontroller IDs
    uint8_t mcu_id = static_cast<uint8_t>(unilib::Microcontroller::CORE);

    // Use data types
    uint8_t dtype = static_cast<uint8_t>(unilib::DataType::FLOAT32);
}
```

## Maintainers

| Name | Email | Discord |
| :---: | :---: | :---: |
| Riley McLain | <rjm0037@uah.edu> | `@ryleu` |

