# Swedish Keyboard Layout Reference

This document explains the mapping between ZMK US keycodes and Swedish keyboard layout symbols.

## Key Mapping Table

When your OS is set to **Swedish layout**, ZMK sends US keycodes that the OS interprets as Swedish symbols.

### Number Row

| Swedish Symbol | Description | ZMK Keycode | Definition Name |
|----------------|-------------|-------------|-----------------|
| § | Section sign | `GRAVE` | - |
| ½ | Half | `LS(GRAVE)` | - |
| ! | Exclamation | `LS(N1)` | `SWE_EXCL` |
| " | Double quote | `LS(N2)` | `SWE_DQT` |
| # | Hash | `LS(N3)` | `SWE_HASH` |
| ¤ | Currency | `LS(N4)` | `SWE_CURR` |
| % | Percent | `LS(N5)` | `SWE_PERC` |
| & | Ampersand | `LS(N6)` | `SWE_AMPER` |
| / | Forward slash | `LS(N7)` | `SWE_FSLH` |
| ( | Left paren | `LS(N8)` | `SWE_LPAR` |
| ) | Right paren | `LS(N9)` | `SWE_RPAR` |
| = | Equals | `LS(N0)` | `SWE_EQ` |
| + | Plus | `MINUS` | `SWE_PLUS` |
| ? | Question | `LS(MINUS)` | `SWE_QMARK` |
| ´ | Acute accent | `EQUAL` | `SWE_ACUTE` |
| ` | Backtick | `LS(EQUAL)` | `SWE_GRAVE` |

### Special Characters (AltGr combinations)

| Swedish Symbol | Description | ZMK Keycode | Definition Name |
|----------------|-------------|-------------|-----------------|
| @ | At sign | `RA(N2)` | `SWE_AT` |
| £ | Pound | `RA(N3)` | - |
| $ | Dollar | `RA(N4)` | `SWE_DLLR` |
| € | Euro | `RA(N5)` | `SWE_EURO` |
| { | Left brace | `RA(N7)` | `SWE_LBRC` |
| [ | Left bracket | `RA(N8)` | `SWE_LBKT` |
| ] | Right bracket | `RA(N9)` | `SWE_RBKT` |
| } | Right brace | `RA(N0)` | `SWE_RBRC` |

### Letter Row Special Keys

| Swedish Symbol | Description | ZMK Keycode | Definition Name |
|----------------|-------------|-------------|-----------------|
| Å | A with ring | `LBKT` | - |
| å | a with ring | `LBKT` | - |
| ¨ | Diaeresis | `RBKT` | - |
| ^ | Caret | `LS(RBKT)` | `SWE_CARET` |
| ~ | Tilde | `RA(RBKT)` | `SWE_TILDE` |

### Bottom Row Special Keys

| Swedish Symbol | Description | ZMK Keycode | Definition Name |
|----------------|-------------|-------------|-----------------|
| Ö | O with umlaut | `SEMI` | - |
| ö | o with umlaut | `SEMI` | - |
| ; | Semicolon | `LS(COMMA)` | `SWE_SEMI` |
| Ä | A with umlaut | `SQT` | - |
| ä | a with umlaut | `SQT` | - |
| ' | Apostrophe | `BSLH` | `SWE_SQT` |
| * | Asterisk | `LS(BSLH)` | `SWE_STAR` |

### Other Symbols

| Swedish Symbol | Description | ZMK Keycode | Definition Name |
|----------------|-------------|-------------|-----------------|
| < | Less than | `NUBS` | `SWE_LT` |
| > | Greater than | `LS(NUBS)` | `SWE_GT` |
| § | Section | `GRAVE` | - |
| ½ | Half | `LS(GRAVE)` | - |
| - | Hyphen/Minus | `SLASH` | `SWE_MINUS` |
| _ | Underscore | `LS(SLASH)` | `SWE_UNDER` |
| \ | Backslash | `RA(MINUS)` | `SWE_BSLH` |
| \| | Pipe | `RA(NUBS)` | `SWE_PIPE` |
| , | Comma | `COMMA` | `SWE_COMMA` |
| . | Period | `DOT` | `SWE_DOT` |
| : | Colon | `LS(DOT)` | `SWE_COLON` |

## Physical Layout Comparison

### US ANSI Layout (ZMK keycode names)
```
` 1 2 3 4 5 6 7 8 9 0 - =
  Q W E R T Y U I O P [ ]
  A S D F G H J K L ; ' \
  Z X C V B N M , . /
```

### Swedish Layout (what appears when OS is set to Swedish)
```
§ 1 2 3 4 5 6 7 8 9 0 + ´
  Q W E R T Y U I O P Å ¨
  A S D F G H J K L Ö Ä '
  Z X C V B N M , . -
```

### Swedish Shifted
```
½ ! " # ¤ % & / ( ) = ? `
  Q W E R T Y U I O P Å ^
  A S D F G H J K L Ö Ä *
  Z X C V B N M ; : _
```

### Swedish AltGr (partial)
```
  @ £ $ €     { [ ] }
```

## Important Notes

1. **Brackets and braces** require AltGr combinations:
   - `[` = AltGr+8 (`RA(N8)`)
   - `]` = AltGr+9 (`RA(N9)`)
   - `{` = AltGr+7 (`RA(N7)`)
   - `}` = AltGr+0 (`RA(N0)`)

2. **The + and ? keys** are on the same physical key:
   - Unshifted: `+` (use `MINUS` in ZMK)
   - Shifted: `?` (use `LS(MINUS)` in ZMK)

3. **The ´ and ` keys** are on the same physical key:
   - Unshifted: `´` (use `EQUAL` in ZMK)
   - Shifted: `` ` `` (use `LS(EQUAL)` in ZMK)

4. **Less than and greater than** are on the key left of Z (NUBS key):
   - Unshifted: `<` (use `NUBS` in ZMK)
   - Shifted: `>` (use `LS(NUBS)` in ZMK)
   - Note: The `§` and `½` symbols are on the GRAVE key (top-left corner)

5. **Special slash behavior**:
   - `/` is Shift+7 (`LS(N7)`)
   - `-` is on its own key at the far right (`SLASH` in ZMK)
   - `\` is AltGr++ (`RA(MINUS)` in ZMK)

## Fixed Issues

The following issues have been corrected:

1. **!? key behavior**: Now correctly produces `?` on tap and `!` on shift+tap
2. **Bracket combos**: All bracket symbols `[]{}` now use correct AltGr combinations
3. **Backslash and pipe**: Now use correct AltGr combinations
4. **Plus and minus**: Now mapped to correct physical keys
5. **Caret and tilde**: Now use correct key combinations
