TAP_DANCE_ENABLE = yes

VIA_ENABLE = yes

WPM_ENABLE = yes
LTO_ENABLE = yes
RGBLIGHT_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = ssd1306

LAYERS_ENABLE = yes
BONGO_ENABLE = yes
CORNE_LOGO_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
    # SRC += oled_setup.c

	# ifdef BONGO_ENABLE
	# 	ifeq ($(strip $(BONGO_ENABLE)), yes)
	# 		SRC += animation/bongo.c
	# 		OPT_DEFS += -DBONGO_ENABLE
	# 	endif
	# endif
	# ifndef BONGO_ENABLE
	# 	SRC += animation/bongo.c
	# 	OPT_DEFS += -DBONGO_ENABLE
	# endif
endif
