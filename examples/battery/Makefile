
EXTERNAL_BOARD_DIRS += $(CURDIR)/../../boards
RIOTBASE ?= $(CURDIR)/../../dependencies/RIOT
BOARD ?= wismeshtag

DEVELHELP ?= 1
QUIET ?= 1

APPLICATION = battery-test
USEMODULE += periph_pwm
USEMODULE += saul
USEMODULE += saul_default
USEMODULE += saul_bat_voltage

USEMODULE += ztimer_msec

include $(RIOTBASE)/Makefile.include
