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

/* * - Shift+' (apostrophe key, which is BSLH on US layout) */
#define SWE_STAR &kp LS(BSLH)

/* ? - Shift+Plus key (Swedish +/? key maps to US MINUS) */
#define SWE_QMARK &kp LS(MINUS)

/* + - Plus key (Swedish +/? key maps to US MINUS) */
#define SWE_PLUS &kp MINUS

/* Backtick ` - Shift+Acute key (key right of +) */
#define SWE_GRAVE &kp LS(EQUAL)

/* Acute accent ´ - Acute key unshifted */
#define SWE_ACUTE &kp EQUAL

/* ~ (Tilde) - AltGr+Diaeresis key (RBKT) */
#define SWE_TILDE &kp RA(RBKT)

/* ===== BRACKETS AND BRACES ===== */

/* [ - AltGr+8 on Swedish layout */
#define SWE_LBKT &kp RA(N8)

/* ] - AltGr+9 on Swedish layout */
#define SWE_RBKT &kp RA(N9)

/* { - AltGr+7 on Swedish layout */
#define SWE_LBRC &kp RA(N7)

/* } - AltGr+0 on Swedish layout */
#define SWE_RBRC &kp RA(N0)

/* ===== SPECIAL CHARACTERS ===== */

/* @ - AltGr+2 on Swedish layout */
#define SWE_AT &kp RA(N2)

/* $ - AltGr+4 on Swedish layout */
#define SWE_DLLR &kp RA(N4)

/* € - AltGr+5 on Swedish layout */
#define SWE_EURO &kp RA(N5)

/* ^ (Caret) - Shift+Diaeresis key (RBKT) */
#define SWE_CARET &kp LS(RBKT)

/* | (Pipe) - AltGr+< key (GRAVE on US layout) */
#define SWE_PIPE &kp RA(GRAVE)

/* \ (Backslash) - AltGr++ key (MINUS on US layout) */
#define SWE_BSLH &kp RA(MINUS)

/* _ (Underscore) - Shift+- key (Swedish -/_ maps to US SLASH) */
#define SWE_UNDER &kp LS(SLASH)

/* - (Hyphen/Minus) - Hyphen key (Swedish -/_ maps to US SLASH) */
#define SWE_MINUS &kp SLASH

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
