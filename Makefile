CC=gcc
LDFLAGS=-limobiledevice

TARGETS=idevicedeactivate

all: $(TARGETS)

idevicedeactivate: idevicedeactivate.c
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf $(TARGETS)
