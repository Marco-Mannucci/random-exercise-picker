# random-exercise-picker

A small C++ command-line tool that picks random exercises from a range of
pages in your textbook. No installation needed: download, run, practice.

## Download

Grab the latest `exercises.exe` from the [Releases](../../releases) page.

## Usage

```
exercises.exe <start_page> <end_page> [-n count]
```

Example: pick 5 random exercises between pages 120 and 135:

```
exercises.exe 120 135 -n 5
```

Run it with no arguments to enter the values interactively.

## Build from source

Requires a C++17 compiler.

```
g++ -std=c++17 -O2 -static main.cpp -o exercises
```

## Contributing

Issues and pull requests are welcome.

## License

MIT
