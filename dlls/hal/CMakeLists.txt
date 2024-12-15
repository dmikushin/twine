add_wine_dll(NAME hal
    IMPORTLIB
        hal
    IMPORTS
        ntoskrnl
    SOURCES
        hal.c
        version.rc
)
