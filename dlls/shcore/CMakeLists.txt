add_wine_dll(NAME shcore
    IMPORTLIB
        shcore
    IMPORTS
        advapi32
    DELAYIMPORTS
        user32
        ole32
    EXTRADLLFLAGS
        -Wb,--prefer-native
    SOURCES
        main.c
)
