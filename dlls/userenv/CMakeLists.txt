add_wine_dll(NAME userenv
    EXTRADEFS
        _USERENV_
    IMPORTS
        advapi32
    IMPORTLIB
        userenv
    EXTRADLLFLAGS
        -Wb,--prefer-native
    SOURCES
        userenv_main.c
)
