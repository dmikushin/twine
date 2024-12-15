add_wine_dll(NAME dhcpcsvc
    DELAYIMPORTS
        iphlpapi
    IMPORTLIB
        dhcpcsvc
    EXTRADLLFLAGS
        -Wb,--prefer-native
    SOURCES
        dhcpcsvc.c
)
