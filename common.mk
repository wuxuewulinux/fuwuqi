.PHONY:all 
CFLAGS = -Wall -std=c++11
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
BIN := $(addprefix /home/wuxuewu/fuwuqi/base/,$(BIN))

LINK_OBJ_DIR = /home/wuxuewu/fuwuqi/link_obj
$(shell mkdir -p $(LINK_OBJ_DIR))

DEP_DIR = /home/wuxuewu/fuwuqi/dep
$(shell mkdir -p $(DEP_DIR))

OBJS := $(addprefix $(LINK_OBJ_DIR)/,$(OBJS))
DEPS := $(addprefix $(DEP_DIR)/,$(DEPS))
LINK_OBJ = $(wildcard $(LINK_OBJ_DIR)/*.o)
LINK_OBJ +=$(OBJS)
all: $(DEPS) $(OBJS) $(BIN)
ifneq ("$(wildcard $(DEPS))","")	
include $(DEPS)
endif
$(BIN):$(LINK_OBJ)
	g++ -g -o $@ $^ -lprotobuf -pthread 
$(LINK_OBJ_DIR)/%.o:%.cpp
	g++ $(CFLAGS) -g -o $@ -c $(filter %.cpp,$^)
$(DEP_DIR)/%.d:%.cpp 
	g++ -MM $(filter %.cpp,$^) | sed 's,\(.*\).o[ :]*,$(LINK_OBJ_DIR)/\1.o $@:,g' > $@
#clean:
#	rm -f  $(BIN) $(OBJS) $(DEPS)
