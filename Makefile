DOCS=./html
TARGET_DIR=./build
TARGET=$(TARGET_DIR)/task_sheduler
STM32_LIB=STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries
SRC_DIRS=. ./Src ./Startup $(STM32_LIB)/STM32F4xx_StdPeriph_Driver/src
INCLUDE_DIRS=. ./Inc $(STM32_LIB)/CMSIS/Device/ST/STM32F4xx/Include $(STM32_LIB)/CMSIS/Include $(STM32_LIB)//STM32F4xx_StdPeriph_Driver/inc

TOOLCHAIN_PREFIX=arm-none-eabi-
CC=$(TOOLCHAIN_PREFIX)gcc
OPT=-O0
MC=STM32F411xE
MC_FLAGS= -mcpu=cortex-m4 -mfloat-abi=soft -mthumb
DEPFLAGS= -MP -MD
SYMBOLS= -DUSE_STDPERIPH_DRIVER -D$(MC)
CCFLAGS= -Wall -Wextra -g $(foreach D,$(INCLUDE_DIRS),-I$(D)) $(OPT) $(DEPFLAGS) $(MC_FLAGS) $(SYMBOLS)
LDFLAGS= $(MC_FLAGS) --specs=nano.specs -T STM32F411RETX_FLASH.ld -Wl,-Map=$(TARGET).map

CFILES=$(foreach D,$(SRC_DIRS),$(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))


.PHONY: all
all: $(TARGET_DIR) | $(TARGET).elf


$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)


$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
	$(TOOLCHAIN_PREFIX)objcopy -O ihex $@ $(TARGET).hex
	$(TOOLCHAIN_PREFIX)objcopy -O binary $@ $(TARGET).bin
	$(TOOLCHAIN_PREFIX)objdump -h -S $@ > $(TARGET).list
	$(TOOLCHAIN)size $@


%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<


.PHONY: docs
docs:
	doxygen


.PHONY: clean
clean:
	rm -rf $(TARGET_DIR) $(OBJECTS) $(DEPFILES) $(foreach D,$(SRC_DIRS),$(wildcard $(D)/*.d)) $(DOCS)
