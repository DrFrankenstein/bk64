; makes it easier to work with sprites exported from PETSCII Editor
; since that's the mnemonic it uses
.define BYTE .byte

_spr_paddle:
; Sprite #1
; Single color mode, BG color: 6, Sprite color: 1
	BYTE $60, $00, $06
	BYTE $FF, $FF, $FF
	BYTE $FF, $FF, $FF
	BYTE $FF, $FF, $FF
	BYTE $60, $00, $06
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00

_spr_ball:
; Sprite #2
; Single color mode, BG color: 6, Sprite color: 1
	BYTE $00, $00, $06
	BYTE $00, $00, $0F
	BYTE $00, $00, $0F
	BYTE $00, $00, $06
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00
	BYTE $00, $00, $00

.export _spr_paddle
.export _spr_ball
