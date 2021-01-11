BOOTMAGIC_ENABLE 	= no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE     = no     # Mouse keys
VIA_ENABLE          = no         # Enable VIA
OLED_DRIVER_ENABLE  = no
LTO_ENABLE          = yes
EXTRAKEY_ENABLE		= yes    # Audio control and System control(+450)
CONSOLE_ENABLE 		= no     # Console for debug(+400)
COMMAND_ENABLE 		= no     # Commands for debug and configuration
NKRO_ENABLE 		= no     # Nkey Rollover
BACKLIGHT_ENABLE 	= no     # Enable keyboard backlight functionality
MIDI_ENABLE 		= no     # MIDI controls
AUDIO_ENABLE 		= no     # Audio output on port C6
UNICODE_ENABLE 		= no     # Unicode
BLUETOOTH_ENABLE 	= no     # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE     = no
RGB_MATRIX_ENABLE   = yes
SWAP_HANDS_ENABLE 	= no	 # Enable one-hand typing
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE 	= no    # Breathing sleep LED during USB suspend
WPM_ENABLE 			= yes

BOOTLOADER = caterina

SRC +=  ./lib/glcdfont.c \
		./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
