
EXTERNAL_BOARD_DIRS += $(CURDIR)/../../boards
RIOTBASE ?= $(CURDIR)/../../dependencies/RIOT
BOARD ?= wismeshtag

DEVELHELP ?= 1
QUIET ?= 1

APPLICATION = wismesh-test
USEMODULE += periph_pwm
FEATURES_OPTIONAL += periph_timer

include $(RIOTBASE)/Makefile.include
