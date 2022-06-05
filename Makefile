PRJ_NAME   = clockController
CC         = arm-none-eabi-gcc
AS         = arm-none-eabi-gcc -x assembler-with-cpp
OBJCOPY    = arm-none-eabi-objcopy
OBJDUMP    = arm-none-eabi-objdump
SIZE       = arm-none-eabi-size
HEX        = $(OBJCOPY) -O ihex
BIN        = $(OBJCOPY) -O binary -S
SRCDIR     = src
BUILD_DIR  = build
SRC        = $(wildcard $(SRCDIR)/*.c)
ASRC       = $(wildcard $(SRCDIR)/*.s)
OBJ        = $(SRC:.c=.o) $(ASRC:.s=.o)
PROGRAMMER = openocd
PGFLAGS    = -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program $(BUILD_DIR)/$(PRJ_NAME).elf verify reset exit"
DEVICE     = STM32F103xB
DEBUG      = 0
OPT       ?= -Og
LDSCRIPT   = stm32f103c8tx.ld
CFLAGS     = -fdata-sections -ffunction-sections -g3 -Wall -mcpu=cortex-m3 -mlittle-endian -mthumb -I inc/ -D $(DEVICE) $(OPT)
ASFLAGS    =  $(CFLAGS)
LDFLAGS    = -g -T $(LDSCRIPT) -Wl,--gc-sections --specs=nano.specs --specs=nosys.specs

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

.PHONY: all clean flash

all: $(BUILD_DIR)/$(PRJ_NAME).elf $(BUILD_DIR)/$(PRJ_NAME).hex $(BUILD_DIR)/$(PRJ_NAME).bin

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.c=.o)))
vpath %.c $(sort $(dir $(SRC)))
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASRC:.s=.o)))
vpath %.s $(sort $(dir $(ASRC)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(ASFLAGS) $< -o $@

$(BUILD_DIR)/$(PRJ_NAME).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR):
	mkdir $@

clean:
	-rm -fR $(BUILD_DIR)

flash: all
	$(PROGRAMMER) $(PGFLAGS)

-include $(wildcard $(BUILD_DIR)/*.d)
