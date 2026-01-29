/*
 * Swedish QWERTY keyboard layout support for ZMK
 *
 * This file provides convenient macros for Swedish keyboard symbols.
 * Note: Some symbols (marked with [AltGr]) require the OS keyboard layout
 * to be set to Swedish. ZMK will send the correct physical keycodes.
 */

#pragma once

#include <dt-bindings/zmk/keys.h>

/* ===== NUMBERS AND COMMON PUNCTUATION ===== */

/* ! - Shift+1 */
#define SWE_EXCL &kp LS(N1)

/* " - Shift+2 */
#define SWE_DQT &kp LS(N2)

/* # - Shift+3 */
#define SWE_HASH &kp LS(N3)

/* ¤ (Currency) - Shift+4 */
#define SWE_CURR &kp LS(N4)

/* % - Shift+5 */
#define SWE_PERC &kp LS(N5)

/* & - Shift+6 */
#define SWE_AMPER &kp LS(N6)

/* / - Shift+7 */
#define SWE_FSLH &kp LS(N7)

/* ( - Shift+8 */
#define SWE_LPAR &kp LS(N8)

/* ) - Shift+9 */
#define SWE_RPAR &kp LS(N9)

/* = - Shift+0 */
#define SWE_EQ &kp LS(N0)

/* ? - Shift+Plus/Equal key */
#define SWE_QMARK &kp LS(EQUAL)

/* + - Plus/Equal key (unshifted) */
#define SWE_PLUS &kp EQUAL

/* Backtick ` - Backtick/Acute key */
#define SWE_GRAVE &kp GRAVE

/* ~ (Tilde) - [AltGr] requires special handling or OS layout */
#define SWE_TILDE &kp LS(GRAVE)

/* ===== BRACKETS AND BRACES ===== */

/* [ - [AltGr+8] on Swedish layout, may vary by system */
#define SWE_LBKT &kp LBKT

/* ] - [AltGr+9] on Swedish layout, may vary by system */
#define SWE_RBKT &kp RBKT

/* { - [AltGr+7] typically accessed via physical key position */
#define SWE_LBRC &kp LS(RBKT)

/* } - [AltGr+0] typically accessed via physical key position */
#define SWE_RBRC &kp RBKT

/* ===== SPECIAL CHARACTERS ===== */

/* @ - Shift+2 (common on many Nordic layouts, may need adjustment) */
#define SWE_AT &kp LS(N2)

/* $ - Shift+4 (may require special key combination on some Nordic setups) */
#define SWE_DLLR &kp LS(N4)

/* ^ (Caret) - typically Shift+` on Nordic layouts */
#define SWE_CARET &kp LS(GRAVE)

/* | (Pipe) - [AltGr+Apostrophe] or other combo */
#define SWE_PIPE &kp BSLH

/* \ (Backslash) - [AltGr+Plus] or Shift+Apostrophe */
#define SWE_BSLH &kp LS(SQT)

/* _ (Underscore) - Shift+Minus */
#define SWE_UNDER &kp LS(MINUS)

/* - (Hyphen/Minus) - Minus key */
#define SWE_MINUS &kp MINUS

/* ===== PUNCTUATION ===== */

/* , (Comma) */
#define SWE_COMMA &kp COMMA

/* . (Period) */
#define SWE_DOT &kp DOT

/* : (Colon) - Shift+Period */
#define SWE_COLON &kp LS(DOT)

/* ; (Semicolon) - Shift+Comma */
#define SWE_SEMI &kp LS(COMMA)

/* ' (Apostrophe/Single Quote) */
#define SWE_SQT &kp SQT

/* ===== CONVENIENCE ALIASES ===== */

/* Parentheses pair */
#define SWE_LPAR_SPC SWE_LPAR &kp SPACE
#define SWE_RPAR_SPC SWE_RPAR &kp SPACE

/* Common programming pairs */
#define SWE_PAIR(open, close) open &kp SPACE close

/* ===== NOTES FOR SPECIAL CHARACTERS ===== */

/*
 * AltGr-based symbols (may need Raw HID if not working):
 * - [ ] { } @ | ~ ^ $
 *
 * If these symbols don't work, you may need to:
 * 1. Update your Windows keyboard layout to "Swedish"
 * 2. Use Raw HID keycodes for specific characters
 * 3. Create custom behaviors with multi-key sequences
 *
 * For detailed Swedish layout key mappings, refer to:
 * https://en.wikipedia.org/wiki/QWERTY#Swedish
 */
