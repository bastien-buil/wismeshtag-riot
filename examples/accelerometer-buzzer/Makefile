
EXTERNAL_BOARD_DIRS += $(CURDIR)/../../boards
RIOTBASE ?= $(CURDIR)/../../dependencies/RIOT
BOARD ?= wismeshtag

DEVELHELP ?= 1
QUIET ?= 1

APPLICATION = accelerometer-test
USEMODULE += periph_pwm
USEMODULE += saul
USEMODULE += saul_default
USEMODULE += lis2dh12
USEMODULE += lis2dh12_i2c


USEMODULE += ztimer_msec

include $(RIOTBASE)/Makefile.include
