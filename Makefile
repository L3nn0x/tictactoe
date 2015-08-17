include Makefile.common

OUTFILE := $(BIN_DIR)tictactoe
SRC_FILES := $(wildcard $(SRC_DIR)*.cpp)
OBJ_FILES := $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_FILES:%.cpp=%.o))

.PHONY: all clean mrproper

all: $(OUTFILE)

$(OUTFILE) : $(OBJ_FILES)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	find -name "*.o" -delete
	find -name "*~" -delete
	find -name "\#*" -delete

mrproper: clean
	$(RM) $(BIN_DIR)
	find -name "*.d" -delete
	$(RM) TAGS

include $(subst $(SRC_DIR),$(DEPENDS_DIR),$(SRC_FILES:%.cpp=%.d))
