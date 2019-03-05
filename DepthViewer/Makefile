SRC = ./DepthViewer.cpp
CPPFLAGS = -Dlinux -I../../Include -std=c++11
LDFLAGS = -L../../Lib -lOpenNI

# OpenCV
CPPFLAGS += -I/usr/local/include
LDFLAGS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc

LOCAL_TARGET = Bin/DepthViewer

all: $(LOCAL_TARGET)

$(LOCAL_TARGET): $(SRC)
	$(CXX) $(SRC) $(CPPFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf $(LOCAL_TARGET)
