add_wine_dll(NAME netutils
    IMPORTLIB
        netutils
    EXTRADLLFLAGS
        -Wb,--prefer-native
    SOURCES
        main.c
)
