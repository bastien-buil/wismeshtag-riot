
EXTERNAL_BOARD_DIRS += $(CURDIR)/../../boards
RIOTBASE ?= $(CURDIR)/../../dependencies/RIOT
BOARD ?= wismeshtag

DEVELHELP ?= 1
QUIET ?= 1

APPLICATION = gps-test
USEMODULE += periph_uart
USEMODULE += periph_pwm

USEMODULE += ztimer_msec

include $(RIOTBASE)/Makefile.include
