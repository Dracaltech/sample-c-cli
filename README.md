# sample-c-cli
Dracal // SDK code sample for C (POSIX) on CLI

## Assumptions

Running this repository requires you to have installed:
- GCC (version >= 9.4.0)
- Make (version >= 4.2.1)
- DracalView (version >= `3.2.x`)
  - Specifically, `dracal-usb-get` needs to be accessible from your `PATH` environment variable (more info in the [documentation how-to](https://www.dracal.com/en/programmers_howto/#dracal-usb-get)).

Script may need to be adjusted depending on your instrument's # of outputs _(currently assumed: 3 outputs)_. See script comments for details.

## Simple usage

Make sure that in `main.c`, variable `dev` corresponds to your local setup (on Linux/Ubuntu, your serial path might be e.g. `/dev/ttyACM0`)

Build
```
make
```

Run
```
./main
```

## Sample output
<img src="https://github.com/Dracaltech/sample-c-vcp/assets/1357711/f97ecc9a-5e57-4e7e-9756-88717bce3e84" width=400 />

```
↑253 dracal/sample-c-cli git:(main) ▶ ./main
Pressure. (kPa): 102.84
Temperature (C): 22.02
RH......... (%): 52.83
Temperature (F): 71.64
Ξ dracal/sample-c-cli git:(main) ▶
```
