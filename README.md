# Base_Control
Code for base Arduino board

## Arduino Communication Agreement v1.0

1. Signal for begin       $  (single char)

2. Control Type char

   * Motor Control: CTRL
   * Bump Control: BUMP
   * Rope Control: CRUL
   * Light Control: LIGH

3. Control content

   **Motor Control：**

   > Two Char
   >
   > 99: Stop
   >
   > 10: Left
   >
   > 01: Right
   >
   > 11: Forward
   >
   > 00: Back
   >
   > PS: default control time 500ms

   **Bump Control：**

   >Two Char
   >
   >00: water tank 1
   >
   >01: water tank 2
   >
   >10: water tank 3
   >
   >11: water tank 4
   >
   >PS: Two action, Open **One** valve and bump. Time is determined by water tank volume

   **Rope Control：**

   > Two Char
   >
   > First to show CW or CCW, 1 is CW, 0 is CCW
   >
   > Second to show control time: if 2 then means 2*1000=2000ms time 

   **Light Control：**

   > Two Char
   >
   > 11: light on
   >
   > 00: light off

Example：$CTRL11 -> Go Forward 500ms
