
# myshell — Development Roadmap

## Project Structure

```text
myshell/
├── main.c
├── commands/
│   ├── navigation.c
│   ├── system.c
│   ├── files.c
│   └── network.c
├── include/
│   └── commands.h
└── CMakeLists.txt
```

## Architecture

### main.c
- Initialize and terminate the shell.
- Display the command prompt.
- Read user input.
- Parse command names and arguments.
- Dispatch commands to their implementations.
- Handle unrecognized commands.
- Maintain the main execution loop.

### include/commands.h
- Declare command functions.
- Define shared command interfaces.
- Keep function signatures consistent across modules.

### Command Execution
- Built-in commands execute within the shell process.
- External programs execute through process creation and execution.
- Keep command identification separate from implementation.
- Preserve Unix flag conventions where applicable.
- Command names may be customized later.

---

## Navigation — commands/navigation.c

- [x] **pwd** — Print working directory
  - `getcwd()`
- [x] **cd** — Change working directory
  - `chdir()`
  - `getenv()`
- [ ] **pushd** — Save current directory and change directories
  - `getcwd()`, `chdir()`
- [ ] **popd** — Return to a previously saved directory
  - `chdir()`
- [ ] **dirs** — Display directory history
  - Directory stack implementation

## System — commands/system.c

- [x] **help** — Display available commands
  - `printf()`
- [x] **quit** — Terminate shell execution
  - Main loop state
- [ ] **clear** — Clear terminal
  - ANSI escape sequences
- [ ] **whoami** — Display current username
  - `geteuid()`, `getpwuid()`
- [ ] **hostname** — Display local hostname
  - `gethostname()`
- [ ] **uname** — Display system information
  - `uname()`
- [ ] **env** — Display environment variables
  - `environ`
- [ ] **echo** — Print text and variable values
  - `printf()`
- [ ] **history** — Display command history
  - History buffer
- [ ] **ps** — Display process information
  - `/proc` filesystem
- [ ] **kill** — Send signals to processes
  - `kill()`

## Files — commands/files.c

- [ ] **ls** — List directory contents
  - `opendir()`, `readdir()`
- [ ] **cat** — Display file contents
  - `open()`, `read()`
- [ ] **touch** — Create files or update timestamps
  - `open()`, `utimensat()`
- [ ] **mkdir** — Create directories
  - `mkdir()`
- [ ] **rmdir** — Remove empty directories
  - `rmdir()`
- [ ] **rm** — Remove files
  - `unlink()`
- [ ] **cp** — Copy files
  - `open()`, `read()`, `write()`
- [ ] **mv** — Move or rename files
  - `rename()`
- [ ] **stat** — Display file metadata
  - `stat()`
- [ ] **chmod** — Modify file permissions
  - `chmod()`
- [ ] **find** — Search directory trees
  - `opendir()`, `readdir()`, `stat()`

## Network — commands/network.c

- [ ] **resolve** — Resolve hostnames to IP addresses
  - `getaddrinfo()`
- [ ] **connect** — Establish or test TCP connections
  - `socket()`, `connect()`
- [ ] **interfaces** — Display network interfaces
  - `getifaddrs()`
- [ ] **ping** — Test network reachability
  - ICMP sockets
- [ ] **listen** — Accept incoming network connections
  - `socket()`, `bind()`, `listen()`, `accept()`
- [ ] **download** — Download files over HTTP
  - TCP sockets, HTTP protocol handling

---

## Implementation Order

### Phase 1 — Navigation
- [x] pwd
- [x] cd

### Phase 2 — Filesystem Exploration
- [x] ls
- [ ] cat
- [ ] mkdir
- [ ] touch

### Phase 3 — File Manipulation
- [ ] rm
- [ ] cp
- [ ] mv
- [ ] stat

### Phase 4 — System Information
- [ ] whoami
- [ ] uname
- [ ] env
- [ ] history

### Phase 5 — Networking
- [ ] resolve
- [ ] connect
- [ ] interfaces
- [ ] ping

### Phase 6 — Shell Capabilities
- [ ] Parse command-line arguments
- [ ] Support quoted arguments
- [ ] Support environment variable expansion
- [ ] Support home directory expansion (`~`)
- [ ] Execute external programs with `fork()` and `execvp()`
- [ ] Wait for child processes with `waitpid()`
- [ ] Track command exit statuses
- [ ] Implement input/output redirection
- [ ] Implement pipelines
- [ ] Handle signals
- [ ] Support background processes

---

## Development Notes

- Keep individual command implementations in their respective modules.
- Avoid unnecessary global variables.
- Keep the main execution loop independent of command logic.
- Handle failed system calls and report meaningful errors.
- Test commands individually before adding additional functionality.
- Commit functional changes separately from structural refactors.
- Document significant design decisions as the project develops.
- Maintain compatibility with standard Unix command flags where practical.

## Current Status

**Completed:** pwd, cd, help, quit

**Next:** ls

**Current focus:** Filesystem operations, directory traversal, and command argument handling.
