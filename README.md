# Calendar CLI 📅

## Compiling ⚙️

initially you will have to compile the code written in C in a compiler installed in your machine, compatible with your processor.

some examples of compilers for each platform:

### Windows

- [MinGW](https://www.mingw-w64.org/)

### Linux and MacOS

On Unix based, Linux and MacOS systems, there is already a standard C compiler, this being GCC.

- [GCC](https://gcc.gnu.org/)

## Running 🏃

Run this command on project folder:

```BASH
gcc main.c -o calendar

```

After that you can run in your terminal in the project folder the calendar program:

```bash
./calendar
```

## Add to PATH 📂

If you want to add the program to your PATH, you can do it by adding the following line to your .bashrc or .zshrc file:

```bash
export PATH=$PATH:/path/to/your/project/folder
```

## Add to Local Bins

```bash
sudo cp /Users/yourUser/Calendar/calendar /usr/local/bin/
```
