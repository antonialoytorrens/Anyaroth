PROG          ?= Anyaroth
VERSION       ?= 1.0.0

CXX           ?= g++
CXXSTD        ?= c++17
PKG_CONFIG    ?= pkg-config

SRC_DIR       ?= Anyaroth
BUILD_DIR     ?= build
BIN_DIR       ?= bin
OBJ_DIR       := $(BUILD_DIR)/obj
DEP_DIR       := $(BUILD_DIR)/dep

DEBUG         ?= 0
ifeq ($(DEBUG),1)
    OPTFLAGS  ?= -O0 -g3 -DDEBUG
    WERROR    ?= -Werror
else
    OPTFLAGS  ?= -O2 -DNDEBUG
    WERROR    ?=
endif

WARNFLAGS     ?= -Wall -Wextra

PKG_LIBS      ?= sdl2 SDL2_image SDL2_mixer SDL2_ttf box2d
PKG_CFLAGS    := $(shell $(PKG_CONFIG) --cflags $(PKG_LIBS))
PKG_LDLIBS    := $(shell $(PKG_CONFIG) --libs   $(PKG_LIBS))

JSON_INCDIR   ?= /usr/include/nlohmann

CPPFLAGS      := -I$(SRC_DIR) -I$(JSON_INCDIR) $(PKG_CFLAGS) \
                 -DANYAROTH_VERSION=\"$(VERSION)\"
CXXFLAGS      := -std=$(CXXSTD) $(OPTFLAGS) $(WARNFLAGS) $(WERROR) -pthread \
                 $(EXTRA_CXXFLAGS)
LDFLAGS       := $(EXTRA_LDFLAGS)
LDLIBS        := $(PKG_LDLIBS)

DEPFLAGS       = -MMD -MP -MF $(DEP_DIR)/$*.d

EXCLUDE_SRCS  ?= \
    $(SRC_DIR)/BouncingBullet.cpp \
    $(SRC_DIR)/BouncingBulletPool.cpp \
    $(SRC_DIR)/PiercingBullet.cpp \
    $(SRC_DIR)/PiercingBulletPool.cpp \
    $(SRC_DIR)/PlayerControllerComponent.cpp \
    $(SRC_DIR)/Shooter.cpp \
    $(SRC_DIR)/ShooterInterface.cpp \
    $(SRC_DIR)/ShotgunShooter.cpp

ALL_SRCS      := $(wildcard $(SRC_DIR)/*.cpp)
SRCS          := $(filter-out $(EXCLUDE_SRCS),$(ALL_SRCS))
OBJS          := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS          := $(patsubst $(SRC_DIR)/%.cpp,$(DEP_DIR)/%.d,$(SRCS))

TARGET        := $(BIN_DIR)/$(PROG)

.PHONY: all clean distclean run help info banner

all: banner $(TARGET)

banner:
	@echo "[$(PROG) $(VERSION)] CXX=$(CXX) ($(shell $(CXX) --version 2>/dev/null | head -1)) CXXSTD=$(CXXSTD) DEBUG=$(DEBUG)"

help:
	@echo "Targets: all clean distclean run info print-VAR"
	@echo "Overrides: PROG VERSION CXX CXXSTD DEBUG OPTFLAGS WARNFLAGS WERROR"
	@echo "           EXTRA_CXXFLAGS EXTRA_LDFLAGS SRC_DIR BUILD_DIR BIN_DIR"

info:
	@echo "PROG       = $(PROG)"
	@echo "VERSION    = $(VERSION)"
	@echo "CXX        = $(CXX)"
	@echo "CXXSTD     = $(CXXSTD)"
	@echo "DEBUG      = $(DEBUG)"
	@echo "OPTFLAGS   = $(OPTFLAGS)"
	@echo "WARNFLAGS  = $(WARNFLAGS)"
	@echo "WERROR     = $(WERROR)"
	@echo "CPPFLAGS   = $(CPPFLAGS)"
	@echo "CXXFLAGS   = $(CXXFLAGS)"
	@echo "LDFLAGS    = $(LDFLAGS)"
	@echo "LDLIBS     = $(LDLIBS)"
	@echo "SRC_DIR    = $(SRC_DIR)"
	@echo "BUILD_DIR  = $(BUILD_DIR)"
	@echo "BIN_DIR    = $(BIN_DIR)"
	@echo "SOURCES    = $(words $(SRCS)) files"

print-%:
	@echo '$*=$($*)'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ_DIR) $(DEP_DIR) $(BIN_DIR):
	@mkdir -p $@

run: $(TARGET)
	cd $(dir $(TARGET)) && ./$(notdir $(TARGET))

clean:
	$(RM) -r $(OBJ_DIR) $(DEP_DIR)

distclean:
	$(RM) -r $(BUILD_DIR) $(BIN_DIR)

-include $(DEPS)
