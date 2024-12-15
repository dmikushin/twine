add_wine_dll(NAME sechost
    IMPORTLIB
        sechost
    IMPORTS
        kernelbase
    DELAYIMPORTS
        rpcrt4
    SOURCES
        plugplay.idl
        security.c
        service.c
        svcctl.idl
        trace.c
)
