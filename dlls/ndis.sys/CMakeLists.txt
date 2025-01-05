add_wine_dll(NAME ndis.sys
    IMPORTS
        advapi32
        ntoskrnl
        iphlpapi
    SOURCES
	main.c
	ndis.sys.spec
)
