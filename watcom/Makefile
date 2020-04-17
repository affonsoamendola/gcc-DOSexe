obj = hello.obj
bin = hello.exe

CC = wcc386
CFLAGS = -zq -od -3
LD = wlink
INCLUDE = include
LIB = /usr/share/openwatcom/lib386/dos/:/usr/share/openwatcom/lib386

$(bin): $(obj)
	$(LD) name $@ file { $(obj) } libpath $(LIB) form dos

.c.obj:
	$(CC) -i$(INCLUDE) -fo=$@ $(CFLAGS) $<

clean: .symbolic
	rm *.obj
	rm $(bin)

run: .symbolic
	dosbox $(bin)