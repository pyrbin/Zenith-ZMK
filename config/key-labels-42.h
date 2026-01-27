/*
 * Key position labels for 42-key TOTEM variant
 * 6 columns x 3 rows + 3 thumb keys per side
 *
 * Usage: #include "key-labels-42.h"
 *
 * Position naming convention:
 *   L/R = Left/Right hand
 *   T/M/B = Top/Middle/Bottom row
 *   H = tHumb cluster
 *   0-5 = Column index (0 = innermost, 5 = outermost)
 */

#pragma once

/*
 * Physical key positions (0-41):
 *
 * ╭──────────────────────────────────╮   ╭──────────────────────────────────╮
 * │  0    1    2    3    4    5     │   │   6    7    8    9   10   11    │
 * │ 12   13   14   15   16   17     │   │  18   19   20   21   22   23    │
 * │ 24   25   26   27   28   29     │   │  30   31   32   33   34   35    │
 * ╰───────────╮ 36   37   38        │   │       39   40   41 ╭────────────╯
 *             ╰─────────────────────╯   ╰──────────────────────╯
 *
 * Key position aliases:
 *
 * ╭──────────────────────────────────╮   ╭──────────────────────────────────╮
 * │ LT5  LT4  LT3  LT2  LT1  LT0    │   │ RT0  RT1  RT2  RT3  RT4  RT5    │
 * │ LM5  LM4  LM3  LM2  LM1  LM0    │   │ RM0  RM1  RM2  RM3  RM4  RM5    │
 * │ LB5  LB4  LB3  LB2  LB1  LB0    │   │ RB0  RB1  RB2  RB3  RB4  RB5    │
 * ╰───────────╮ LH2  LH1  LH0       │   │      RH0  RH1  RH2 ╭────────────╯
 *             ╰─────────────────────╯   ╰──────────────────────╯
 */

/* Left hand - Top row */
#define LT5 0
#define LT4 1
#define LT3 2
#define LT2 3
#define LT1 4
#define LT0 5

/* Right hand - Top row */
#define RT0 6
#define RT1 7
#define RT2 8
#define RT3 9
#define RT4 10
#define RT5 11

/* Left hand - Middle row (home row) */
#define LM5 12
#define LM4 13
#define LM3 14
#define LM2 15
#define LM1 16
#define LM0 17

/* Right hand - Middle row (home row) */
#define RM0 18
#define RM1 19
#define RM2 20
#define RM3 21
#define RM4 22
#define RM5 23

/* Left hand - Bottom row */
#define LB5 24
#define LB4 25
#define LB3 26
#define LB2 27
#define LB1 28
#define LB0 29

/* Right hand - Bottom row */
#define RB0 30
#define RB1 31
#define RB2 32
#define RB3 33
#define RB4 34
#define RB5 35

/* Left hand - Thumb cluster */
#define LH2 36
#define LH1 37
#define LH0 38

/* Right hand - Thumb cluster */
#define RH0 39
#define RH1 40
#define RH2 41

/* Key groups for homerow mods */
#define KEYS_L LT5 LT4 LT3 LT2 LT1 LT0 LM5 LM4 LM3 LM2 LM1 LM0 LB5 LB4 LB3 LB2 LB1 LB0
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RT5 RM0 RM1 RM2 RM3 RM4 RM5 RB0 RB1 RB2 RB3 RB4 RB5
#define THUMBS LH2 LH1 LH0 RH0 RH1 RH2
