# Wine for terminal-only Windows apps (T-Wine)

This is Wine stripped off from multimedia and gaming-related subsystems.

Wine is usually used to run Windows games and desktop apps in Linux. Therefore, a lot of effort is
put into supporting DirectX, video/sound, etc. However, this is all done on top of the WIN32 API
core functionality (kernel32, user32, etc), which has a value on its own: an engine to run console
WIN32 applications. Therefore, we create a special simplified edition of Wine tailored to just this
purpose.


## Building

Build a Docker container with the provided `Dockerfile` to definitely separate this version of Wine
from any others in the main system:

```
docker build -t t-wine .
```

