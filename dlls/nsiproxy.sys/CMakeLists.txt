add_wine_dll(NAME nsiproxy.sys
    UNIXLIB
        nsiproxy.so
    IMPORTS
        ntoskrnl
    SOURCES
	device.c
	icmp_echo.c
	ip.c
	ndis.c
	nsi.c
	tcp.c
	udp.c
)
