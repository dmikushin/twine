add_wine_tlb(NAME stdole2
    EXTRADLLFLAGS
        -Wb,--data-only
    SOURCES
        rsrc.rc
        stdole2.idl
)
