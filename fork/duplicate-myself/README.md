when executing `main`, you can see something like this after running command `ps -x --forest`.
```plain
  23931 pts/1    Ss     0:00  |           |   \_ /usr/bin/bash
  25659 pts/1    S+     0:00  |           |   |   \_ ./build/main
  25660 pts/1    S+     0:00  |           |   |       \_ ./build/main
```
