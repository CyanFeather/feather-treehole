CC=g++
CFLAGS=`pkg-config opencv --cflags --libs`
OUT=hellocv imgread videoCapture

.PHONY: all clean 
all: $(OUT)

$(OUT): % : %.cpp
	$(CC) $< $(CFLAGS) -o $@

clean:
	-@echo Clean application: $(OUT)
	-@rm -f *.o *~ *.out $(OUT)

