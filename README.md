# cpp2020

## Qol scripts:

`makefile`

```makefile
COMPILER = g++
CFLAGS = -std=c++17 -O2
DAYS = $(wildcard day*)

all: $(DAYS)

%: %/src.cpp
	$(COMPILER) $(CFLAGS) -o $@/solved $<
```

`~/.scripts/solve`

```bash
#!/bin/bash
make $1 && time $1/solved
```

`~/.scripts/advpush`

```bash
#!/bin/bash
git add . && git commit -m "$*" && git push
```

## Workflow:

Make new day directory:

```bash
mkdir dayXX
cd dayXX
touch src.cpp
```

Write the solution in *src.cpp*.

From the project root directory:

```bash
solve dayXX
```

This will *make* and run your solution simultaneously
with *time*.

When it's ready to be pushed remotely:

```bash
advpush your commit message here
```

Adds, commits with your message (no quotes in the argument), and pushes to the remote.

ROOT
* dayXX
    * src.cpp
    * input.dat
* makefile
* .gitignore
* README.md