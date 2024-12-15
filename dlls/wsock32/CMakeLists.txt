add_wine_dll(NAME wsock32
    IMPORTLIB
        wsock32
    IMPORTS
        mswsock
        ws2_32
        iphlpapi
    SOURCES
        protocol.c
        service.c
        socket.c
        version.rc
)
